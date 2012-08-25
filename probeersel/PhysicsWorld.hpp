#ifndef PHYSICSWORLD_HPP
#define PHYSICSWORLD_HPP

#include <GL/gl.h>
#include "PhysicsComponent.hpp"

class PhysicsWorld
{

public:
    void apply_boundary(PhysicsComponent* physicsComp) const;
    // apply the boudary conditions on the physics component

    void set_size(GLfloat const size_x, GLfloat const size_y);

    // Constructor
    PhysicsWorld(GLfloat const size_x, GLfloat const size_y);
private:
    GLfloat _size_x, _size_y;
};


// Inline functions
inline GLfloat modulo(GLfloat const pos, GLfloat const size)
{
    if (pos < 0)
        return pos + size;
    else if (pos > size)
        return pos - size;
    else
        return pos;
}

#endif /* PhysicsWorld class header */
