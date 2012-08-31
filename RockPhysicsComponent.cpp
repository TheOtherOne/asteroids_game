#ifndef ROCKPHYSICSCOMPONENT_CPP
#define ROCKPHYSICSCOMPONENT_CPP

#include <math.h>
#include <GL/gl.h>

#include "RockPhysicsComponent.hpp"

#define PI 3.1415926535898

void RockPhysicsComponent::propagate(double const dt)
// Do basic propagation (integration of speed and spin)
{
    // attenuate the speeds with the decay
    GLfloat spinspeed_size = fabs(_spinspeed);
    GLfloat spinspeed_sign = (_spinspeed >= 0.0) ? 1.0 : -1.0;

    spinspeed_size -= decceleration_spin* dt; // decay the rotational speed
    if (spinspeed_size <= state0)
        spinspeed_size = state0;        // make sure that the spin is really in the state
    _spinspeed = spinspeed_sign * spinspeed_size;

    _movespeed -= decceleration_move* dt;
    if (_movespeed <= state0)
        _movespeed = state0;


    // integrate the spin over dt
    _orientation += _spinspeed * dt;
    if (_orientation > 360.0)
        _orientation -= 360.0;

    // adjust position according to orientation and speed
    _pos_x += _movespeed * sin(2*PI*(_orientation/360.0)) * dt;
    _pos_y += _movespeed * cos(2*PI*(_orientation/360.0)) * dt;
}

// constructors
RockPhysicsComponent::RockPhysicsComponent() :
    base_class(), _radius(MAX_RADIUS) {};

RockPhysicsComponent::RockPhysicsComponent(GLfloat const radius) :
    base_class(), _radius(radius) {};

RockPhysicsComponent::RockPhysicsComponent( GLfloat const pos_x, GLfloat const pos_y,
                                            GLfloat const orientation,
                                            GLfloat const movespeed, GLfloat const spinspeed,
                                            GLfloat const radius) :
    base_class(pos_x, pos_y, orientation, movespeed, spinspeed), _radius(radius) {};

#endif /* RockPhysicsComponent class implementation */
