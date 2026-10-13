#include <QApplication>
#include <QInputDialog>
#include <QDebug>
#include "GameApp.h"
#include "world/Galaxy.h"
#include "world/map/RandomMapGenerator.h"
#include "entities/Player.h"
#include "entities/Ship.h"

namespace sm
{
    GameApp::GameApp(QObject* parent)
    :   QObject(parent)
    {   }

    void GameApp::onNewGame()
    {
        qDebug() << "onNewGame called!";
        RandomMapGenerator map_generator;
        Galaxy galaxy = map_generator.generateGalaxy(10, 42);
        ShipType ship_type = ShipType::Freighter; // temp hardcoded TODO
        Player player{Ship(ship_type)}; // most vexing perse

        qDebug() << "Creating GameSession...";
        m_game_session.emplace(std::move(player), std::move(galaxy), this);
        qDebug() << "GameSession created!";

        connect(&m_game_session.value(), &GameSession::stateChanged,
                this, &GameApp::onStateChanged);
        connect(&m_game_session.value(), &GameSession::messageReceived,
                this, &GameApp::onMessageReceived);
        connect(&m_game_session.value(), &GameSession::gameOver,
                this, &GameApp::onQuit);
    }

    void GameApp::onQuit()
    {
        QApplication::quit();
    }

    void GameApp::onTravelRequested()
    {
        qDebug() << "onTravelRequested called!";
        qDebug() << "game_session exists:" << m_game_session.has_value();
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

    void GameApp::onStateChanged(const Player& player, const Galaxy& galaxy, int current_system_id)
    {
        emit stateChanged(player, galaxy, current_system_id);
    }

    void GameApp::onMessageReceived(const QString& message)
    {
        emit messageReceived(message);
    }

}