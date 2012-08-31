#ifndef ROCKGRAPHICSCOMPONENT_HPP
#define ROCKGRAPHICSCOMPONENT_HPP

#include "RockPhysicsComponent.hpp"

static const int segments = 100;

class RockGraphicsComponent
{

public:
    void draw(RockPhysicsComponent const& physicsComp) const;
    // Do whatever you need to to draw the thing

    RockGraphicsComponent();
    // Constructor

private:
    // defining the state variables and the initial state

};

#endif /* RockGraphicsComponent class header */
