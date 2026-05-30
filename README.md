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

* `src/domain/` – Core types and contracts (enums, interfaces, structs)
* `src/entities/` – Player entities (Player, Ship, Cargo)
* `src/world/` – Game world (Planet, StarSystem, Galaxy, Market, Edge, map generation)
* `src/systems/` – Business logic (TravelSystem, TradeSystem, EventSystem)
* `src/pricing/` – Pricing strategy interface and implementation
* `src/core/` – Game state and main loop (GameState, GameLoop)
* `src/io/` – Input/output interfaces (TerminalRenderer, TerminalInput)
* `main.cpp` – Application entry point
