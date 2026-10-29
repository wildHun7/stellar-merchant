#include <QApplication>
#include <QInputDialog>
#include <QDebug>
#include "GameApp.h"
#include "world/Galaxy.h"
#include "entities/Player.h"

namespace sm
{
    GameApp::GameApp(QObject* parent)
    :   QObject(parent)
    {   }

    void GameApp::onGameStartRequested(ShipType type)
    {
        qDebug() << "onNewGame called!";
        qDebug() << "Creating GameSession...";
        m_game_session.emplace(type, this);
        qDebug() << "GameSession created!";

        connect(&m_game_session.value(), &GameSession::stateChanged,
                this, &GameApp::onStateChanged);
        connect(&m_game_session.value(), &GameSession::messageReceived,
                this, &GameApp::onMessageReceived);
        connect(&m_game_session.value(), &GameSession::gameOver,
                this, &GameApp::onQuit);

        m_game_session->initialize();
    }

    void GameApp::onQuit()
    {
        QApplication::quit();
    }

    void GameApp::onTravelRequested()
    {
        bool ok;
        int target_system_id = QInputDialog::getInt(
            nullptr,
            tr("System ID"),
            tr("Enter System ID:"),
            0,                  // def
            0,                  // min
            10,                 // max
            1,                  // Krok zmiany (step)
            &ok
            );

        if (ok && m_game_session) {
            m_game_session->onTravelRequested(target_system_id);
        }
    }

    void GameApp::onBuyRequested()
    {
        QStringList commodities;
        commodities << "Cybernetics" << "Deuterium" << "HydroRations" << "RareOre" << "Stardust";

        bool ok;
        QString selected = QInputDialog::getItem(
            nullptr,
            tr("Buy Commodity"),
            tr("Select commodity:"),
            commodities,
            0,
            false,
            &ok
            );

        if (!ok) return;

        Commodity commodity = static_cast<Commodity>(commodities.indexOf(selected));

        // 2. pobierz quantity
        int quantity = QInputDialog::getInt(
            nullptr,
            tr("Quantity"),
            tr("Enter quantity:"),
            1, 1, 100, 1, &ok
            );

        if (ok && m_game_session)
            m_game_session->onBuyRequested(commodity, quantity);
    }

    void GameApp::onSellRequested()
    {
        QStringList commodities;
        commodities << "Cybernetics" << "Deuterium" << "HydroRations" << "RareOre" << "Stardust";

        bool ok;
        QString selected = QInputDialog::getItem(
            nullptr,
            tr("Sell Commodity"),
            tr("Select commodity:"),
            commodities,
            0,
            false,
            &ok
            );

        if (!ok) return;

        Commodity commodity = static_cast<Commodity>(commodities.indexOf(selected));

        // 2. pobierz quantity
        int quantity = QInputDialog::getInt(
            nullptr,
            tr("Quantity"),
            tr("Enter quantity:"),
            1, 1, 100, 1, &ok
            );

        if (ok && m_game_session)
            m_game_session->onSellRequested(commodity, quantity);
    }

    void GameApp::onStateChanged(const Player& player, const Galaxy& galaxy, int current_system_id)
    {
        emit stateChanged(player, galaxy, current_system_id);
    }

    void GameApp::onMessageReceived(const QString& message)
    {
        emit messageReceived(message);
    }

}