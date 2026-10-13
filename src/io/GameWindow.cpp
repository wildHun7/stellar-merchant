#include "GameWindow.h"
#include <QSplitter>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>

namespace sm
{
    GameWindow::GameWindow(QWidget* parent) : QMainWindow(parent)
    {
        setWindowTitle("Stellar Merchant");
        setMinimumSize(1024, 768);

        auto* splitter = new QSplitter(Qt::Horizontal, this); // this (parent = GameWindow) deletes ptrs (based on Qt Tree)
        setCentralWidget(splitter);

        // left panel:
        // map + buttons

        auto* left_panel = new QWidget(splitter);
        auto* left_layout = new QVBoxLayout(left_panel);

        m_map_view = new QGraphicsView(left_panel);
        left_layout->addWidget(m_map_view);

        auto* buttons_layout = new QHBoxLayout();
        m_new_game_button = new QPushButton("New Game", left_panel);
        m_quit_button = new QPushButton("Quit", left_panel);
        m_travel_button = new QPushButton("Travel", left_panel);
        m_buy_button = new QPushButton("Buy", left_panel);
        m_sell_button = new QPushButton("Sell", left_panel);

        buttons_layout->addWidget(m_new_game_button);
        buttons_layout->addWidget(m_quit_button);
        buttons_layout->addWidget(m_travel_button);
        buttons_layout->addWidget(m_buy_button);
        buttons_layout->addWidget(m_sell_button);
        left_layout->addLayout(buttons_layout);

        // right panel:
        // player stats

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

        // signal & slots

        connect(m_new_game_button, &QPushButton::clicked, this, &GameWindow::newGameRequested);
        connect(m_quit_button, &QPushButton::clicked, this, &GameWindow::quitRequested);
        connect(m_travel_button, &QPushButton::clicked, this, &GameWindow::travelRequested);
        connect(m_buy_button, &QPushButton::clicked, this, &GameWindow::buyRequested);
        connect(m_sell_button, &QPushButton::clicked, this, &GameWindow::sellRequested);
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
}