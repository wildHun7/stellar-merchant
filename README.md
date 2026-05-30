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

* `src/domain/` – Core game logic, types, and domain models (e.g., `CommodityType`).
* `src/entities/` – Game entities (Cargo, Ship, Market, Player, Planet, StarSystem)
* `src/map/` – Galaxy graph, edges and map generation (Galaxy, Edge, IMapGenerator)
* `src/systems/` – Business logic (TravelSystem, TradeSystem, IEventSystem)
* `src/pricing/` – Pricing strategy interface and implementation
* `src/core/` – Game state and main loop (in progress)
* `src/io/` – Input/output interfaces (in progress)
* `main.cpp` – Application entry point
* `main.cpp` – Application entry point.
