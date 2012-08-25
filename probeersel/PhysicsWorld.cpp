#ifndef PHYSICSWORLD_CPP
#define PHYSICSWORLD_CPP

#include "PhysicsWorld.hpp"

void PhysicsWorld::apply_boundary(PhysicsComponent* physicsComp)
// apply the boudary conditions on the physics component
{
    physicsComp->_pos_x = modulo(physicsComp->_pos_x, _size_x);
    physicsComp->_pos_y = modulo(physicsComp->_pos_y, _size_y);
    return;
}

#endif /* PhysicsWorld class implementation */
