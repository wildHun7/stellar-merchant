cmake_minimum_required(VERSION 3.19)
project(StellarMerchant LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(StellarMerchant
    main.cpp
    README.md
    src/domain/Commodity.h
    src/domain/PlanetType.h
    src/domain/IPricingStrategy.h
    src/domain/GameStatus.h
    src/domain/Result.h
    src/entities/Cargo.h
    src/entities/Ship.h
    src/entities/Player.h
    src/entities/Market.h
    src/entities/Planet.h
    src/entities/StarSystem.h
    src/domain/Position.h
    src/map/Edge.h
    src/map/Galaxy.h
    src/map/IMapGenerator.h
    src/map/RandomMapGenerator.h
    src/systems/TravelSystem.h
    src/systems/TradeSystem.h
    src/systems/IEventSystem.h
)

target_include_directories(StellarMerchant PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)
