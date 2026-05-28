cmake_minimum_required(VERSION 3.19)
project(StellarMerchant LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(StellarMerchant
    main.cpp
    README.md
    src/domain/CommodityType.h
    src/domain/PlanetType.h
    src/domain/IPricingStrategy.h
)

target_include_directories(StellarMerchant PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)
