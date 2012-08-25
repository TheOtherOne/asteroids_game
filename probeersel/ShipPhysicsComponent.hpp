#ifndef SHIPPHYSICSCOMPONENT_HPP
#define SHIPPHYSICSCOMPONENT_HPP

#include <GL/gl.h>
#include "PhysicsComponent.hpp"

typedef enum ForceType {TO_Left, TO_Right, TO_Front, None} ForceType;

// defining the acceleration and decelleration constants
static const GLfloat acceleration_spin =  200.0;    // in degrees per second^2
static const GLfloat decceleration_spin = 20.0;
static const GLfloat acceleration_move =  50.0;    // in meters(?) per second^2
static const GLfloat decceleration_move = 10.0;

// defining the two spin states
static const GLfloat state0 = 0.0;
static const GLfloat spinspeed_max  = 200.0;
static const GLfloat movespeed_max  = 100.0;


class ShipPhysicsComponent : public PhysicsComponent
// Class dealing with the physical aspects (position, rotation) of an object
{
public:
    typedef PhysicsComponent    base_class;

public:
    // Methods that are defined in its abstract baseclass
    void propagate(double const dt);
    // Do basic propagation (integration of speed and spin)

public:
    void set_force(ForceType const force);
    // this sets the acting force on the object

    ShipPhysicsComponent();
    // Constructor

// Member variables
private:
    ForceType   _force;

};
#endif /* ShipPhysicsComponent class header */
