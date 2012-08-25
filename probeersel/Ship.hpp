#ifndef SHIP_HPP
#define SHIP_HPP

#include "ShipPhysicsComponent.hpp"
#include "ShipGraphicsComponent.hpp"
#include "PhysicsWorld.hpp"

typedef enum ShipInputType {Left, Right, Forward, Neutral, Shoot} ShipInputType;

class Ship
{
public:
    void propagate(double const dt);
    void draw() const;
    void input(ShipInputType const input);

    Ship(PhysicsWorld* const physicsWorld);
    // Constructor

private:
    ShipPhysicsComponent    _physicsComp;
    ShipGraphicsComponent   _graphicsComp;

    PhysicsWorld* const     _physicsWorld;  // The world the ship lives in
};

#endif /* Ship class header */
