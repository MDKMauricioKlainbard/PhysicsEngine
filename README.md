# Lagrangian Physics Engine

A modular C++ physics engine designed to simulate mechanical systems using the **Lagrangian Formalism** and **Numerical Integration**. 

This project serves as a computational laboratory to explore Classical Mechanics, Chaos Theory, and eventually Relativistic Astrophysics. It is built with a focus on **Object-Oriented Design**, mathematical rigor, and clean architecture.

## 🚀 Key Features

* **Abstract Core:** A polymorphic `LagrangianSystem` base class that handles the integration loop, state management, and data logging.
* **Separation of Concerns:** The solver is decoupled from the physical definition of the system.
* **Numerical Methods:** Implements **Semi-Implicit Euler** integration (Symplectic-Euler) for energy stability in oscillatory systems.
* **Data Export:** Automatic `.csv` generation for analysis in Python/Excel.
* **Modern C++:** Uses STL containers, exceptions for safety, and RAII principles.
* **Build System:** Fully integrated with **CMake** for cross-platform compatibility.

## 📂 Project Structure

```text
PhysicsEngine/
├── include/           # Header files (.h) - The Interface
│   ├── LagrangianSystem.h
│   └── SimplePendulum.h
├── src/               # Source files (.cpp) - The Implementation
│   ├── LagrangianSystem.cpp
│   └── SimplePendulum.cpp
├── examples/          # Executables and Demos
│   └── pendulo_demo.cpp
├── CMakeLists.txt     # Build configuration
└── README.md          # Documentation