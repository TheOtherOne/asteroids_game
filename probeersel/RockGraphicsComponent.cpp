#ifndef ROCKGRAPHICSCOMPONENT_CPP
#define ROCKGRAPHICSCOMPONENT_CPP

#include <math.h>
#include <GL/gl.h>
#include "RockGraphicsComponent.hpp"

#define PI 3.1415926535898

void RockGraphicsComponent::draw(RockPhysicsComponent const& physicsComp) const
// Do whatever you need to to draw the thing
{
    glPushMatrix();
    glTranslatef(physicsComp._pos_x,
                 physicsComp._pos_y,
                 (GLfloat)0.0);
    glRotatef(physicsComp._orientation, 0.0, 0.0, -1.0);

    if (physicsComp.get_radius() < 10)
    {
        glPointSize(16.0f);
        glColor3f(0.0f, 1.0f, 1.0f);
        glBegin(GL_POINTS);
            glVertex2f(0, 0);
        glEnd();
    }
    else
    {
        float angle(0.0);

        glColor3f(0.0f, 0.0f, 1.0f);
        glLineWidth(2.0f);
        glLineStipple(2, 0x3F07);
        glEnable(GL_LINE_STIPPLE);
        glBegin(GL_LINE_LOOP);
            for (int i=0; i < segments; ++i)
            {
                angle = 2*PI*i/segments;
                glVertex2f(physicsComp.get_radius()*cos(angle), physicsComp.get_radius()*sin(angle));
            }
        glEnd();
        glDisable(GL_LINE_STIPPLE);
    }

    glPopMatrix();
}

// The constructor
RockGraphicsComponent::RockGraphicsComponent() {};

#endif /* RockGraphicsComponent class implementation */
