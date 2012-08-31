#ifndef SHIP_CPP
#define SHIP_CPP

#include "Ship.hpp"

void Ship::propagate(double const dt)
{
    _physicsComp.propagate(dt);
    _physicsWorld->apply_boundary(&_physicsComp);
}
void Ship::draw() const
{
    _graphicsComp.draw(_physicsComp);
}
void Ship::input(ShipInputType const input)
{
    switch (input)
    {
        case Left:
            _physicsComp.set_force(TO_Left); break;
        case Right:
            _physicsComp.set_force(TO_Right); break;
        case Forward:
            _physicsComp.set_force(TO_Front); break;
        case Neutral:
            _physicsComp.set_force(None); break;
        case Shoot:
            break;
        default:
            break;
    }
}
// Constructors
Ship::Ship(PhysicsWorld* const physicsWorld) :
    _physicsComp(ShipPhysicsComponent()),
    _graphicsComp(ShipGraphicsComponent()),
    _physicsWorld(physicsWorld) {}

Ship::Ship( PhysicsWorld* const physicsWorld,
            GLfloat const pos_x, GLfloat const pos_y, GLfloat const orientation,
            GLfloat const movespeed, GLfloat const spinspeed) :
    _physicsComp(ShipPhysicsComponent(pos_x, pos_y, orientation, movespeed, spinspeed)),
    _graphicsComp(ShipGraphicsComponent()),
    _physicsWorld(physicsWorld) {}
#endif /* Ship class */
