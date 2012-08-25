#ifndef SHIP_CPP
#define SHIP_CPP

#include "Ship.hpp"

void Ship::propagate(double const dt)
{
    _physicsComp.propagate(dt);
}
void Ship::draw()
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
// Constructor
Ship::Ship() : _physicsComp(ShipPhysicsComponent()),
               _graphicsComp(ShipGraphicsComponent()) {}

#endif /* Ship class */
