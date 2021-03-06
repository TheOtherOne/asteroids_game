#ifndef SHIPPHYSICSCOMPONENT_CPP
#define SHIPPHYSICSCOMPONENT_CPP

#include <math.h>
#include <GL/gl.h>

#include "ShipPhysicsComponent.hpp"

#define PI 3.1415926535898

void ShipPhysicsComponent::set_force(ForceType const force)
// this sets the 'intention' of the object
{
    _force = force;
}

void ShipPhysicsComponent::propagate(double const dt)
// Do basic propagation (integration of speed and spin)
{
    // First check if the system is in one of the stable states

    // If not in one of the stable states:
    if (_force == TO_Left)
    {
        _spinspeed -= acceleration_spin* dt; // The rotational speed (spin) needs to be propagated
        if (_spinspeed <= -spinspeed_max)
            _spinspeed = -spinspeed_max;        // make sure that the spin is really in the state
    }
    else if (_force == TO_Right)
    {
        _spinspeed += acceleration_spin* dt;
        if (_spinspeed >= spinspeed_max)
            _spinspeed = spinspeed_max;
    }
    else if (_force == TO_Front)
    {
        _movespeed += acceleration_move* dt;
        if (_movespeed >= movespeed_max)
            _movespeed = movespeed_max;
    }


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
ShipPhysicsComponent::ShipPhysicsComponent() :
    base_class(), _force(None) {};

ShipPhysicsComponent::ShipPhysicsComponent( GLfloat const pos_x, GLfloat const pos_y,
                                            GLfloat const orientation,
                                            GLfloat const movespeed, GLfloat const spinspeed) :
    base_class(pos_x, pos_y, orientation, movespeed, spinspeed), _force(None) {};

#endif /* ShipPhysicsComponent class */
