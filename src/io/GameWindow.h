#pragma once
#include <QMainWindow>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>

namespace sm
{
    class GameWindow : public QMainWindow
    {
        Q_OBJECT

    public:
        explicit GameWindow(QWidget* parent = nullptr);

        [[nodiscard]] QPushButton* getTravelButton() const;
        [[nodiscard]] QPushButton* getBuyButton() const;
        [[nodiscard]] QPushButton* getSellButton() const;
        [[nodiscard]] QPushButton* getQuitButton() const;

    private:
        QPushButton* m_travel_button;
        QPushButton* m_buy_button;
        QPushButton* m_sell_button;
        QPushButton* m_quit_button;
        QLabel* m_credits_label;
        QLabel* m_fuel_label;
        QLabel* m_cargo_label;
        QTextEdit* m_message_log;
    };
}