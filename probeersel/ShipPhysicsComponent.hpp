#ifndef SHIPPHYSICSCOMPONENT_HPP
#define SHIPPHYSICSCOMPONENT_HPP

#include <GL/gl.h>

typedef enum ForceType {TO_Left, TO_Right, TO_Front, None} ForceType;

// defining the acceleration and decelleration constants
static const GLfloat acceleration =  800.0;    // in degrees per second^2
static const GLfloat decceleration = 100.0;

// defining the two spin states
static const GLfloat state0 = 0.0;
static const GLfloat spinspeed_max  = 180.0;
static const GLfloat movespeed_max  = 10.0;


class ShipPhysicsComponent
// Class dealing with the physical aspects (position, rotation) of an object
{
protected:

public:
    void set_force(ForceType const force);
    // this sets the acting force on the object

    void propagate(double const dt);
    // Do basic propagation (integration of speed and spin)

    ShipPhysicsComponent();
    // Constructor

public: // TODO make sure that only friend classes can access this
    GLfloat     _pos_x, _pos_y;
    GLfloat     _orientation;
    GLfloat     _movespeed;
    GLfloat     _spinspeed;
    ForceType   _force;
};
#endif /* ShipPhysicsComponent class header */
