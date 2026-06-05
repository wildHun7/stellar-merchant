# Stellar Merchant 🚀

A space trading simulation game written in C++20.

---

## 🛠️ Tech Stack

* **Language:** C++20
* **Build System:** CMake

---

## 📋 Requirements

* **Compiler:** C++20 compliant compiler (GCC 13+ / Clang 16+)
* **Build Tools:** CMake 3.19 or higher

---

## 🗂️ Project Structure (Current)

```text
src/
├── context/         # Execution contexts handling current player environment
│   └── events/      # Event-driven architecture (IEventSystem, TravelEvent)
├── core/            # High-level application controller and main game loop
│   └── session/     # State machine for application sessions (GameSession, MenuSession)
├── domain/          # Core types, enums, and shared contracts (e.g., Commodity, ShipType)
├── entities/        # Domain models representing game actors (Player, Ship, Cargo)
├── io/              # Input/Output layer, UI rendering, and hardware abstractions
├── pricing/         # Economic strategies and price calculation algorithms
├── systems/         # Pure business logic and state managers (TravelSystem, TradeSystem)
└── world/           # Environment representation and space geography
    └── map/         # Map generation algorithms & data structures (IMapGenerator, Edge)
main.cpp             # Application entry point
