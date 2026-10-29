#include "GameWindow.h"
#include <QSplitter>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>

namespace sm
{
    GameWindow::GameWindow(QWidget* parent) : QMainWindow(parent)
    {
        setWindowTitle("Stellar Merchant");
        setMinimumSize(1024, 768);

        m_stack = new QStackedWidget(this);
        setCentralWidget(m_stack);

        setupMenuPage();
        setupShipPage();
        setupGamePage();

        m_stack->setCurrentIndex(0);
    }

    void GameWindow::onStateChanged(const Player& player, const Galaxy& galaxy, int current_system_id)
    {
        m_credits_label->setText(QString::fromStdString(std::format("Credits: {} CR", player.getCredits())));
        m_fuel_label->setText(QString::fromStdString(std::format("Fuel: {} units", player.getShip().getFuelAmount())));

        //TODO: map
    }

    void GameWindow::onMessageReceived(const QString& message)
    {
        m_message_log->append(message);
    }

    void GameWindow::onNewGameClicked()
    {
        m_stack->setCurrentIndex(1);
    }

    void GameWindow::setupMenuPage()
    {
        m_menu_page = new QWidget();
        auto* menu_page_layout = new QVBoxLayout(m_menu_page);

        auto* menu_page_title = new QLabel("STELLAR MERCHANT", m_menu_page);
        menu_page_title->setAlignment(Qt::AlignCenter);

        m_new_game_button = new QPushButton("New Game", m_menu_page);
        m_quit_button = new QPushButton("Quit", m_menu_page);

        menu_page_layout->addWidget(menu_page_title);
        menu_page_layout->addSpacing(20);
        menu_page_layout->addWidget(m_new_game_button);
        menu_page_layout->addWidget(m_quit_button);

        connect(m_new_game_button, &QPushButton::clicked, this, &GameWindow::onNewGameClicked);
        connect(m_quit_button, &QPushButton::clicked, this, &GameWindow::quitRequested);

        m_stack->addWidget(m_menu_page);
    }

    void GameWindow::setupShipPage()
    {
        m_ship_page = new QWidget();
        auto* ship_page_layout = new QVBoxLayout(m_ship_page);
        ship_page_layout->setAlignment(Qt::AlignCenter);

        auto* ship_page_title = new QLabel("Select Your Ship", m_ship_page);
        ship_page_title->setAlignment(Qt::AlignCenter);

        auto* buttons_layout = new QHBoxLayout();
        m_shuttle_button = new QPushButton("Shuttle\n100t | 1.0x fuel", m_ship_page);
        m_freighter_button = new QPushButton("Freighter\n200t | 2.0x fuel", m_ship_page);
        m_interceptor_button = new QPushButton("Interceptor\n150t | 0.5x fuel", m_ship_page);

        buttons_layout->addWidget(m_shuttle_button);
        buttons_layout->addWidget(m_freighter_button);
        buttons_layout->addWidget(m_interceptor_button);

        ship_page_layout->addWidget(ship_page_title);
        ship_page_layout->addSpacing(20);
        ship_page_layout->addLayout(buttons_layout);

        connect(m_shuttle_button,     &QPushButton::clicked, [this]() {
            m_stack->setCurrentIndex(2);
            emit gameStartRequested(ShipType::Shuttle); });
        connect(m_freighter_button,   &QPushButton::clicked, [this]() {
            m_stack->setCurrentIndex(2);
            emit gameStartRequested(ShipType::Freighter); });
        connect(m_interceptor_button, &QPushButton::clicked, [this]() {
            m_stack->setCurrentIndex(2);
            emit gameStartRequested(ShipType::Interceptor); });

        m_stack->addWidget(m_ship_page);
    }

    void GameWindow::setupGamePage()
    {
        m_game_page = new QWidget();
        auto* game_page_layout = new QVBoxLayout(m_game_page);
        auto* splitter = new QSplitter(Qt::Horizontal, m_game_page);
        game_page_layout->addWidget(splitter);

        // left panel: map + buttons

        auto* left_panel = new QWidget(splitter);
        auto* left_layout = new QVBoxLayout(left_panel);

        m_map_view = new QGraphicsView(left_panel);
        left_layout->addWidget(m_map_view);

        auto* buttons_layout = new QHBoxLayout();
        m_game_quit_button = new QPushButton("Quit", left_panel);
        m_travel_button = new QPushButton("Travel", left_panel);
        m_buy_button = new QPushButton("Buy", left_panel);
        m_sell_button = new QPushButton("Sell", left_panel);

        buttons_layout->addWidget(m_game_quit_button);
        buttons_layout->addWidget(m_travel_button);
        buttons_layout->addWidget(m_buy_button);
        buttons_layout->addWidget(m_sell_button);
        left_layout->addLayout(buttons_layout);

        // right panel: player stats

        auto* right_panel = new QWidget(splitter);
        auto* right_layout = new QVBoxLayout(right_panel);

        m_credits_label = new QLabel("Credits: 0 CR", right_panel);
        m_fuel_label    = new QLabel("Fuel: 0 units", right_panel);
        m_message_log   = new QTextEdit(right_panel);
        m_message_log->setReadOnly(true);

        right_layout->addWidget(m_credits_label);
        right_layout->addWidget(m_fuel_label);
        right_layout->addWidget(m_message_log);

        splitter->setSizes({700, 324});

        connect(m_travel_button, &QPushButton::clicked, this, &GameWindow::travelRequested);
        connect(m_buy_button, &QPushButton::clicked, this, &GameWindow::buyRequested);
        connect(m_sell_button, &QPushButton::clicked, this, &GameWindow::sellRequested);
        connect(m_game_quit_button, &QPushButton::clicked, this, &GameWindow::quitRequested);

        m_stack->addWidget(m_game_page);
    }

}