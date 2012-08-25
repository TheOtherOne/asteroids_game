#ifndef PHYSICSCOMPONENT_HPP
#define PHYSICSCOMPONENT_HPP

#include <GL/gl.h>

class PhysicsComponent
// Class dealing with the physical aspects (position, rotation) of an object
{
public:
    virtual void propagate(double const dt);
    // Do basic propagation (integration of speed and spin)


public: // TODO make sure that only friend classes can access this
    GLfloat     _pos_x, _pos_y;
    GLfloat     _orientation;
    GLfloat     _movespeed;
    GLfloat     _spinspeed;
};
#endif /* PhysicsComponent class header */
