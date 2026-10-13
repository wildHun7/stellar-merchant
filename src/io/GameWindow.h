#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <QGraphicsView>
#include <QLabel>
#include <QTextEdit>
#include "entities/Player.h"
#include "world/Galaxy.h"

namespace sm
{
    class GameWindow : public QMainWindow
    {
        Q_OBJECT

    public:
        explicit GameWindow(QWidget* parent = nullptr);

    public slots:
        void onStateChanged(const Player& player, const Galaxy& galaxy, int current_system_id);
        void onMessageReceived(const QString& message);

    signals:
        void newGameRequested();
        void quitRequested();

        void travelRequested();
        void buyRequested();
        void sellRequested();

    private:
        // menu buttons
        QPushButton* m_new_game_button;
        QPushButton* m_quit_button;

        // game buttons
        QPushButton* m_travel_button;
        QPushButton* m_buy_button;
        QPushButton* m_sell_button;

        // panels
        QGraphicsView* m_map_view;
        QLabel* m_credits_label;
        QLabel* m_fuel_label;
        QTextEdit* m_message_log;
    };
}