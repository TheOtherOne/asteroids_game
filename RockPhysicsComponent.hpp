#ifndef ROCKPHYSICSCOMPONENT_HPP
#define ROCKPHYSICSCOMPONENT_HPP

#include <GL/gl.h>
#include "PhysicsComponent.hpp"

class RockPhysicsComponent : public PhysicsComponent
// Class dealing with the physical aspects (position, rotation) of an object
{
public:
    typedef PhysicsComponent    base_class;

protected:
// defining the acceleration and decelleration constants
static const GLfloat decceleration_spin = 0.0;
static const GLfloat decceleration_move = 0.0;

// defining the two spin states
static const GLfloat state0 = 0.0;
static const GLfloat spinspeed_max  = 200.0;
static const GLfloat movespeed_max  = 100.0;

static const GLfloat MAX_RADIUS = 60;


public:
    // Methods that are defined in its abstract baseclass
    void propagate(double const dt);
    // Do basic propagation (integration of speed and spin)

    inline GLfloat get_radius() const
    {   return _radius;
    }

    // Constructor
    RockPhysicsComponent();
    RockPhysicsComponent(GLfloat const radius);
    RockPhysicsComponent(GLfloat const pos_x, GLfloat const pos_y, GLfloat const orientation,
                         GLfloat const movespeed, GLfloat const spinspeed, GLfloat const radius);

// Member variables
private:
    GLfloat _radius;    // radius of the circle
};
#endif /* RockPhysicsComponent class header */
