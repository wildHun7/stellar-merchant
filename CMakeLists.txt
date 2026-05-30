cmake_minimum_required(VERSION 3.19)
project(StellarMerchant LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(StellarMerchant
    main.cpp
        src/domain/Commodity.h
        src/domain/PlanetType.h
        src/domain/GameStatus.h
        src/domain/Result.h
        src/domain/Position.h
        src/entities/Cargo.h
        src/entities/Ship.h
        src/entities/Player.h
        src/world/Market.h
        src/world/Planet.h
        src/world/StarSystem.h
        src/world/Edge.h
        src/world/Galaxy.h
        src/world/IMapGenerator.h
        src/world/RandomMapGenerator.h
        src/systems/TravelSystem.h
        src/systems/TradeSystem.h
        src/systems/IEventSystem.h
        src/pricing/StandardPricing.h
        src/pricing/IPricingStrategy.h
        src/core/GameState.h
        src/core/GameLoop.h
        src/io/Command.h
        src/io/IRenderer.h
        src/io/IInputHandler.h
        src/io/TerminalRenderer.h
        src/io/TerminalInput.h
)

target_include_directories(StellarMerchant PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)
