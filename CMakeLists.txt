cmake_minimum_required(VERSION 3.19)
project(StellarMerchant LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(StellarMerchant
    main.cpp

        src/context/IContext.h
        src/context/CityContext.h
        src/context/TravelContext.h

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

        src/entities/Cargo.cpp
        src/entities/Ship.cpp
        src/entities/Player.cpp

        src/pricing/StandardPricing.cpp

        src/world/Market.cpp
        src/world/Planet.cpp
        src/world/StarSystem.cpp
        src/world/Galaxy.cpp
        src/world/map/RandomMapGenerator.cpp


)

target_include_directories(StellarMerchant PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)
