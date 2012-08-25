#ifndef SHIPGRAPHICSCOMPONENT_CPP
#define SHIPGRAPHICSCOMPONENT_CPP

#include <GL/gl.h>
#include "ShipGraphicsComponent.hpp"

void ShipGraphicsComponent::draw(ShipPhysicsComponent const& physicsComp) const
// Do whatever you need to to draw the thing
{
    glPushMatrix();
    glTranslatef(physicsComp._pos_x,
                 physicsComp._pos_y,
                 (GLfloat)0.0);
    glRotatef(physicsComp._orientation, 0.0, 0.0, -1.0);

    glBegin(GL_POLYGON);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(0.0, 35, 0.0);
        glVertex3f(-25, 0.0, 0.0);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(0.0, -25, 0.0);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(25, 0.0, 0.0);
    glEnd();

    glPopMatrix();
}

// The constructor
ShipGraphicsComponent::ShipGraphicsComponent() {};

#endif /* ShipGraphicsComponent class */
