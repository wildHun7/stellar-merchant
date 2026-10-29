#pragma once

#include <QMainWindow>
#include <QStackedWidget>
#include <QPushButton>
#include <QGraphicsView>
#include <QLabel>
#include <QTextEdit>
#include "entities/Player.h"
#include "world/Galaxy.h"
#include "domain/ShipType.h"

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
        void gameStartRequested(ShipType type);
        void quitRequested();
        void travelRequested();
        void buyRequested();
        void sellRequested();

    private slots:
        void onNewGameClicked();

    private:
        void setupMenuPage();
        void setupShipPage();
        void setupGamePage();

        QStackedWidget* m_stack;

        QWidget* m_menu_page;
        QPushButton* m_new_game_button;
        QPushButton* m_quit_button;

        QWidget* m_ship_page;
        QPushButton* m_shuttle_button;
        QPushButton* m_freighter_button;
        QPushButton* m_interceptor_button;

        QWidget* m_game_page;
        QGraphicsView* m_map_view;
        QPushButton* m_game_quit_button;
        QPushButton* m_travel_button;
        QPushButton* m_buy_button;
        QPushButton* m_sell_button;

        QLabel* m_credits_label;
        QLabel* m_fuel_label;
        QTextEdit* m_message_log;
    };
}