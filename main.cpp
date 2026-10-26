#include <iostream>
#include <iomanip>
#include "VectorEngine.hpp"

void printSeparator() {
    std::cout << "\033[1;36m[SYS-MATRIX]\033[0m ──────────────────────────────────────────────────\n";
}

int main() {
    std::cout << std::fixed << std::setprecision(3);
    
    printSeparator();
    std::cout << " INITIALIZING KINEMATIC ALLOCATION MATRIX\n";
    printSeparator();

    EntityManager manager;

    Entity satellite;
    satellite.id = 101;
    satellite.position = {0.0, 500.0, 0.0};
    satellite.velocity = {10.0, 0.0, -5.0};
    satellite.mass = 1200.0;
    
    manager.registerEntity(satellite);

    std::cout << " >> STATUS: Node registered successfully.\n"
              << "    [ID: " << satellite.id << "] "
              << "[Tracked Cluster Count: " << manager.activeCount() << "]\n\n";

    unsigned int faultyID = 999;
    printSeparator();
    std::cout << " EVALUATING MEMORY SAFEGUARDS: Searching for Unmapped ID " << faultyID << "...\n";
    
    auto emptyLookup = manager.fetchEntity(faultyID);
    if (!emptyLookup.has_value()) {
        std::cout << " >> [PASS]: Domain constraint held. std::optional returned empty.\n"
                  << "            Runtime state preserved. Zero segmentation fault hazard.\n\n";
    }

    unsigned int targetID = 101;
    printSeparator();
    std::cout << " RUNNING IDENTITY LOOKUP: Fetching Node " << targetID << "...\n";
    
    auto validLookup = manager.fetchEntity(targetID);
    if (validLookup.has_value()) {
        Entity retrieved = validLookup.value();
        std::cout << " >> [PASS]: Domain coordinate resolved successfully.\n\n";
        
        std::cout << "    METRIC LOGS:\n"
                  << "    ┌──────────────┬────────────────────────────────────────┐\n"
                  << "    │ Parameter    │ Vector State Telemetry Value           │\n"
                  << "    ├──────────────┼────────────────────────────────────────┤\n"
                  << "    │ Position     │ X: " << std::setw(7) << retrieved.position.x 
                                      << " | Y: " << std::setw(7) << retrieved.position.y 
                                      << " | Z: " << std::setw(7) << retrieved.position.z << "      │\n"
                  << "    │ Velocity     │ Mag: " << std::setw(5) << retrieved.velocity.magnitude() << " m/s                             │\n"
                  << "    │ Mass Core    │ " << std::setw(6) << retrieved.mass << " kg                              │\n"
                  << "    └──────────────┴────────────────────────────────────────┘\n";
    }

    printSeparator();
    std::cout << " SYSTEM TERMINATED GRACEFULLY: All memory boundaries intact.\n";
    printSeparator();
    
    return 0;
}
