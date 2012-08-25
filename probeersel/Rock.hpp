#ifndef ROCK_HPP
#define ROCK_HPP

#include <GL/gl.h>

#include "RockPhysicsComponent.hpp"
#include "RockGraphicsComponent.hpp"
#include "PhysicsWorld.hpp"

class Rock
{

public:
    void propagate(double const dt);
    void draw() const;

    // constructors
    Rock(PhysicsWorld* const physicsWorld);
    Rock(PhysicsWorld* const physicsWorld, GLfloat const radius);
    Rock(PhysicsWorld* const physicsWorld,
         GLfloat const pos_x, GLfloat const pos_y, GLfloat const orientation,
         GLfloat const movespeed, GLfloat const spinspeed, GLfloat const radius);

// member variables
private:
    RockPhysicsComponent    _physicsComp;
    RockGraphicsComponent   _graphicsComp;

    PhysicsWorld* const     _physicsWorld;  // The world the asteroid lives in
};

#endif /* Rock class header */
