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
            _physicsComp.set_force(TO_state1); break;
        case Right:
            _physicsComp.set_force(TO_state2); break;
        case Forward:
            break;
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
