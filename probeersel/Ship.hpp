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

    // Constructors
    Ship(PhysicsWorld* const physicsWorld);
    Ship(PhysicsWorld* const physicsWorld,
        GLfloat const pos_x, GLfloat const pos_y, GLfloat const orientation,
        GLfloat const movespeed, GLfloat const spinspeed);

private:
    ShipPhysicsComponent    _physicsComp;
    ShipGraphicsComponent   _graphicsComp;

    PhysicsWorld* const     _physicsWorld;  // The world the ship lives in
};

#endif /* Ship class header */
