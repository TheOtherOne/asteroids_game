#ifndef ROCK_CPP
#define ROCK_CPP

#include "Rock.hpp"

void Rock::propagate(double const dt)
{
    _physicsComp.propagate(dt);
    _physicsWorld->apply_boundary(&_physicsComp);
}
void Rock::draw() const
{
    _graphicsComp.draw(_physicsComp);
}

// Constructors
Rock::Rock(PhysicsWorld* const physicsWorld) :
    _physicsComp(RockPhysicsComponent()),
    _graphicsComp(RockGraphicsComponent()),
    _physicsWorld(physicsWorld) {}

Rock::Rock(PhysicsWorld* const physicsWorld, GLfloat const radius) :
    _physicsComp(RockPhysicsComponent(radius)),
    _graphicsComp(RockGraphicsComponent()),
    _physicsWorld(physicsWorld) {}

Rock::Rock( PhysicsWorld* const physicsWorld,
            GLfloat const pos_x, GLfloat const pos_y, GLfloat const orientation,
            GLfloat const movespeed, GLfloat const spinspeed, GLfloat const radius) :
    _physicsComp(RockPhysicsComponent(pos_x, pos_y, orientation, movespeed, spinspeed, radius)),
    _graphicsComp(RockGraphicsComponent()),
    _physicsWorld(physicsWorld) {}

#endif /* Ship class implementation */
