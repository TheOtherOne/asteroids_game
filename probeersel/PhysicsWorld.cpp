#ifndef PHYSICSWORLD_CPP
#define PHYSICSWORLD_CPP

#include "PhysicsWorld.hpp"

void PhysicsWorld::apply_boundary(PhysicsComponent* physicsComp) const
// apply the boudary conditions on the physics component
{
    physicsComp->_pos_x = modulo(physicsComp->_pos_x, _size_x);
    physicsComp->_pos_y = modulo(physicsComp->_pos_y, _size_y);
    return;
}

void PhysicsWorld::set_size(GLfloat const size_x, GLfloat const size_y)
// sets the size of the world
{
    _size_x = size_x;
    _size_y = size_y;
}

// Constructor
PhysicsWorld::PhysicsWorld(GLfloat const size_x, GLfloat const size_y) :
    _size_x(size_x), _size_y(size_y) {};

#endif /* PhysicsWorld class implementation */
