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
├── core/            # Application orchestrator and main game loop (GameApp)
│   └── session/     # Game and menu sessions (GameSession, MenuSession)
├── context/         # Player state machine (CityContext, TravelContext)
├── systems/         # Game mechanics and transaction logic
├── pricing/         # Price calculation strategies (StandardPricing)
├── world/           # Game world — planets, star systems, galaxy
│   └── map/         # Procedural map generation (RandomMapGenerator)
├── entities/        # Player, Ship, Cargo
├── domain/          # Core types and contracts (e. g. Commodity, ShipType, Result)
└── io/              # Terminal-based UI 
main.cpp             # Entry point — wires dependencies and starts GameApp
```
