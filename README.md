# Kinematic Vector State Engine (Core Proof of Concept)

A type-safe, low-level 3D physics architecture engineered in C++17 to model particle coordinates and states within rigid memory boundaries. 

## Architectural Philosophy

Traditional low-level physics engines frequently rely on raw pointers (`Entity*`) or unchecked array indices to perform rapid state lookups. In resource-constrained or unguided environments, these patterns create significant vulnerability to undefined behavior, null-pointer de-referencing, and fatal runtime crashes (`Segmentation fault (core dumped)`).

This engine resolves those structural vulnerabilities by implementing **explicit domain safeguards**. By wrapping lookup operations inside a categorical envelope via `std::optional`, the system replaces hazardous manual memory tracking with a deterministic, compile-time type invariant. If a target tracking node ID is invalid or out-of-bounds, the lookup explicitly evaluates to `std::nullopt`, preserving system stability and forcing type-safe transformation pipelines.

## Project Structure

* **`VectorEngine.hpp`**: The core header blueprint. Contains the structural layouts for 3D coordinate arrays (`Vector3D`), simulated moving elements (`Entity`), and the encapsulated collection controller (`EntityManager`).
* **`main.cpp`**: The stylized diagnostic test harness. Acts as an intentional runtime boundary check, purposefully challenging the memory safeguards with out-of-bounds inputs to verify crash immunity before extracting successful telemetry logs.

## Technical Specifications & Toolchain

* **Language Standard**: Modern C++17 (Strict ISO compliance)
* **Compiler Infrastructure**: Clang++ / LLVM (Selected for strict static analysis diagnostics and optimized intermediate representations)
* **Mathematical Norm**: Real-space Euclidean vector magnitude calculation:
  $$\Vert\vec{v}\Vert = \sqrt{x^2 + y^2 + z^2}$$

## Local Compilation and Verification

To compile and link the runtime architecture using Clang, execute the following command in your terminal workspace:

```bash
clang++ -std=c++17 main.cpp -o KinematicEngine && ./KinematicEngine
```

### Verified Telemetry Telemetry Log
When executed successfully, the system bypasses unverified transformations to render a text-mapped data layout dashboard:
* Validates successful node registration into continuous vector memory boundaries.
* Verifies out-of-bounds address protection layers.
* Outputs precise floating-point tracking logs for X, Y, and Z vector state metrics.

## Project intent & Engineering context
* If you are curious about the origins, this 3D physics framework functions as a foundational tracking sandbox built to explore elementary kinematic properties. This system's operation is specifically modeled to simulate high-velocity friction (tracking relationships with other components, as partially developed or stated in VectorEngine.hpp where the absolute scalar speed is resolved from multi-axis components using the three-dimensional Euclidean norm '(Vector3D::magnitude()' drawing inspiration from the complex mechanics seen from the AC units in Armored Core 6.)
* By calculating focal-point trajectories across an Euclidean coordinate space, the system handles the dynamic state registration and boundary safeguards natively. When auditing or evaluating unmapped data parameters (such as an invalid search key 'feultyID'), the pipeline securely verifies that the domain constraint holds via verification checks ('!emptyLookup.has_value()'), bypassing null pointer segmentation faults. The cinematic layout of the console dashboard is an intentional design choice, constructed to represent a retro-futuristic telemetry command module interface.
