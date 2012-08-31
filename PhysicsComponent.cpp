#ifndef PHYSICSCOMPONENT_CPP
#define PHYSICSCOMPONENT_CPP

#include <GL/gl.h>
#include "PhysicsComponent.hpp"

// Constructors
PhysicsComponent::PhysicsComponent() :
     _pos_x(0.0), _pos_y(0.0), _orientation(0.0), _movespeed(0.0),
     _spinspeed(0.0) {};

PhysicsComponent::PhysicsComponent(GLfloat const pos_x, GLfloat const pos_y,
                                   GLfloat const orientation,
                                   GLfloat const movespeed, GLfloat const spinspeed) :
     _pos_x(pos_x), _pos_y(pos_y), _orientation(orientation),
     _movespeed(movespeed), _spinspeed(spinspeed) {};


#endif /* PhysicsComponent class implementation */
