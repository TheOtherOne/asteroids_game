#ifndef SHIPGRAPHICSCOMPONENT_HPP
#define SHIPGRAPHICSCOMPONENT_HPP

#include "ShipPhysicsComponent.hpp"

// Class for a triangle-like thing that can rotate
class ShipGraphicsComponent
{

public:
    void draw(ShipPhysicsComponent const& pysicsComp) const;
    // Do whatever you need to to draw the thing

    ShipGraphicsComponent();
    // Constructor

private:
    // defining the state variables and the initial state

};

#endif /* ShipGraphicsComponent class header */
