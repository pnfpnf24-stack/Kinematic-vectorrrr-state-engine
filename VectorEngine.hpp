#ifndef VECTOR_ENGINE_HPP
#define VECTOR_ENGINE_HPP

#include <iostream>
#include <vector>
#include <cmath>
#include <optional>

// Represents a 3D vector for position, velocity, or acceleration
struct Vector3D {
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;

    // Returns the length (or speed) of the vector
    double magnitude() const {
        return std::sqrt(x*x + y*y + z*z);
    }
};

// Any moving object in the physics simulation
struct Entity {
    unsigned int id;
    Vector3D position;
    Vector3D velocity;
    double mass;
};

// Manages all active entities in the simulation
class EntityManager {
private:
    std::vector<Entity> entities;

public:
    // Adds a new entity to the simulation
    void registerEntity(const Entity& entity) {
        entities.push_back(entity);
    }

    // Looks up an entity by its ID. Returns std::nullopt if not found.
    std::optional<Entity> fetchEntity(unsigned int id) const {
        for (const auto& entity : entities) {
            if (entity.id == id) {
                return entity;
            }
        }
        return std::nullopt;
    }

    // Returns the total number of tracked entities
    size_t activeCount() const { return entities.size(); }
};

#endif // VECTOR_ENGINE_HPP
#ifndef VECTOR_ENGINE_HPP
#define VECTOR_ENGINE_HPP

#include <iostream>
#include <vector>
#include <cmath>
#include <optional>

// Represents a 3D vector for position, velocity, or acceleration
struct Vector3D {
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;

    // Returns the length (or speed) of the vector
    double magnitude() const {
        return std::sqrt(x*x + y*y + z*z);
    }
};

// Any moving object in the physics simulation
struct Entity {
    unsigned int id;
    Vector3D position;
    Vector3D velocity;
    double mass;
};

// Manages all active entities in the simulation
class EntityManager {
private:
    std::vector<Entity> entities;

public:
    // Adds a new entity to the simulation
    void registerEntity(const Entity& entity) {
        entities.push_back(entity);
    }

    // Looks up an entity by its ID. Returns std::nullopt if not found.
    std::optional<Entity> fetchEntity(unsigned int id) const {
        for (const auto& entity : entities) {
            if (entity.id == id) {
                return entity;
            }
        }
        return std::nullopt;
    }

    // Returns the total number of tracked entities
    size_t activeCount() const { return entities.size(); }
};

#endif // VECTOR_ENGINE_HPP

