#ifndef SHIP_HPP
#define SHIP_HPP

#include "ShipPhysicsComponent.hpp"
#include "ShipGraphicsComponent.hpp"

typedef enum ShipInputType {Left, Right, Forward, Shoot} ShipInputType;

class Ship
{
public:
    void propagate(double const dt);
    void draw();
    void input(ShipInputType const input);

    Ship();
    // Constructor

private:
    ShipPhysicsComponent    _physicsComp;
    ShipGraphicsComponent   _graphicsComp;
};

#endif /* Ship class header */
