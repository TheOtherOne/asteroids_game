#ifndef SHIPPHYSICSCOMPONENT_HPP
#define SHIPPHYSICSCOMPONENT_HPP

#include <GL/gl.h>

typedef enum ForceType {TO_state1, TO_state2} ForceType;

class ShipPhysicsComponent
// Class dealing with the physical aspects (position, rotation) of an object
{
protected:
    // defining the acceleration and decelleration constants
    static const GLfloat decceleration = 800.0;    // in degrees per second^2
    static const GLfloat acceleration = 800.0;

    // defining the two spin states
    static const GLfloat state1 = 0.0;             // in degrees per second
    static const GLfloat state2 = 180.0;

public:
    void set_force(ForceType const force);
    // this sets the 'intention' of the object

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
