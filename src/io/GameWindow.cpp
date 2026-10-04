#include "GameWindow.h"
#include <QSplitter>
#include <QGraphicsView>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>

namespace sm
{
    GameWindow::GameWindow(QWidget* parent) : QMainWindow(parent)
    {
        setWindowTitle("Stellar Merchant");
        setMinimumSize(1024, 768);

        // main splitter as central widget
        auto* splitter = new QSplitter(Qt::Horizontal, this); // parent = this (GameWindow) deletes raw ptrs
        setCentralWidget(splitter);

        // left panel: map + action button
        auto* left_panel = new QWidget(splitter);
        auto* left_panel_layout = new QVBoxLayout(left_panel);

        auto* map_view = new QGraphicsView(left_panel);
        left_panel_layout->addWidget(map_view);

        auto* buttons_layout = new QHBoxLayout();
        m_travel_button = new QPushButton("Travel", left_panel);
        m_buy_button = new QPushButton("Buy", left_panel);
        m_sell_button = new QPushButton("Sell", left_panel);
        m_quit_button = new QPushButton("Quit", left_panel);

        buttons_layout->addWidget(m_travel_button);
        buttons_layout->addWidget(m_buy_button);
        buttons_layout->addWidget(m_sell_button);
        buttons_layout->addWidget(m_quit_button);

        left_panel_layout->addLayout(buttons_layout);

        // right panel: game stats
        auto* right_panel = new QWidget(splitter);
        auto* right_panel_layout = new QVBoxLayout(right_panel);

        splitter->setSizes({700, 324});

        m_credits_label = new QLabel("Credits: 0 CR", right_panel);
        m_fuel_label    = new QLabel("Fuel: 0 units", right_panel);
        m_cargo_label   = new QLabel("Cargo: Empty", right_panel);
        m_message_log   = new QTextEdit(right_panel);
        m_message_log->setReadOnly(true);

        right_panel_layout->addWidget(m_credits_label);
        right_panel_layout->addWidget(m_fuel_label);
        right_panel_layout->addWidget(m_cargo_label);
        right_panel_layout->addWidget(m_message_log);
    }

    QPushButton* GameWindow::getTravelButton() const
    {
        return m_travel_button;
    };

    QPushButton* GameWindow::getBuyButton() const
    {
        return m_buy_button;
    }

    QPushButton* GameWindow::getSellButton() const
    {
        return m_sell_button;
    }

    QPushButton* GameWindow::getQuitButton() const
    {
        return m_quit_button;
    }
}
