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
    if (_spinspeed <= state1 && _force == TO_state1)
    {
        _spinspeed = state1;     // make sure that the spin is really in the state
    }
    else if (_spinspeed >= state2 && _force == TO_state2)
    {
        _spinspeed = state2;
    }

    // If not in one of the stable states:
    else if (_force == TO_state1)
    {
        _spinspeed -= decceleration* dt;  // The rotational speed (spin) needs to be propagated
    }
    else if (_force == TO_state2)
    {
        _spinspeed += acceleration* dt;
    }
    else
    {
        throw 1;        // never get here
    }

    // integrate the spin over dt
    _orientation += _spinspeed * dt;
    if (_orientation > 360.0)
        _orientation -= 360.0;

    // adjust position according to orientation and speed
    _pos_x += _movespeed * sin(2*PI*(_orientation/360.0)) * dt;
    _pos_y += _movespeed * cos(2*PI*(_orientation/360.0)) * dt;
}

// constructor
ShipPhysicsComponent::ShipPhysicsComponent() :
     _pos_x(0.0), _pos_y(0.0), _orientation(0.0), _movespeed(0.0),
     _spinspeed(0.0), _force(TO_state1) {};

#endif /* ShipPhysicsComponent class */
