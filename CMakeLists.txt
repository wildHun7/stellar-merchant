cmake_minimum_required(VERSION 3.19)
project(StellarMerchant LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

add_executable(StellarMerchant WIN32
main.cpp

        src/context/IContext.h
        src/context/CityContext.h
        src/context/TravelContext.h
        src/context/QuitContext.h

        src/core/GameApp.h
        src/core/session/MenuSession.h
        src/core/session/GameSession.h

        src/domain/Commodity.h
        src/domain/PlanetType.h
        src/domain/GameStatus.h
        src/domain/Result.h
        src/domain/Position.h
        src/domain/ShipType.h

        src/entities/Cargo.h
        src/entities/Ship.h
        src/entities/Player.h

        src/io/Command.h
        src/io/IRenderer.h
        src/io/IInputHandler.h
        src/io/TerminalRenderer.h
        src/io/TerminalInput.h
        src/io/GameWindow.h

        src/pricing/StandardPricing.h
        src/pricing/IPricingStrategy.h

        src/systems/TravelSystem.h
        src/systems/TradeSystem.h
        src/systems/IEventSystem.h

        src/world/Market.h
        src/world/Planet.h
        src/world/StarSystem.h
        src/world/Galaxy.h
        src/world/map/IMapGenerator.h
        src/world/map/RandomMapGenerator.h
        src/world/map/Edge.h

        src/context/CityContext.cpp
        src/context/TravelContext.cpp

        src/core/session/GameSession.cpp
        src/core/session/MenuSession.cpp
        src/core/GameApp.cpp

        src/entities/Cargo.cpp
        src/entities/Ship.cpp
        src/entities/Player.cpp

        src/io/TerminalInput.cpp
        src/io/TerminalRenderer.cpp

        src/pricing/StandardPricing.cpp

        src/systems/TravelSystem.cpp
        src/systems/TradeSystem.cpp

        src/world/Market.cpp
        src/world/Planet.cpp
        src/world/StarSystem.cpp
        src/world/Galaxy.cpp
        src/world/map/RandomMapGenerator.cpp
        src/io/GameWindow.cpp
        src/io/QtInputHandler.h
        src/io/QtInputHandler.cpp

)

target_include_directories(StellarMerchant PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(StellarMerchant
    PRIVATE
        Qt6::Core
        Qt6::Widgets
)
