#ifndef SPHERE_CPP
#define SPHERE_CPP

#include <math.h>
#include <GL/gl.h>

#define PI 3.1415926535898


class Sphere
{

private:
    static const GLfloat MAX_RADIUS = 60;
    static const int segments = 100;

public:
    void draw()
    {
        glPushMatrix();
        glTranslatef(_pos_x, _pos_y, (GLfloat)0.0);
        glRotatef(_orientation, 0.0, 0.0, 1.0);
        if (_radius < 10)
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
                    glVertex2f(_radius*cos(angle), _radius*sin(angle));
                }
            glEnd();
            glDisable(GL_LINE_STIPPLE);
        }
        glPopMatrix();
    }

    // constructors
    Sphere() : _pos_x(0.0), _pos_y(0.0), _orientation(0.0), _radius(MAX_RADIUS) {};
    Sphere(GLfloat const pos_x, GLfloat const pos_y, GLfloat const orientation, GLfloat const radius) :
             _pos_x(pos_x), _pos_y(pos_y), _orientation(orientation), _radius(radius) {};

// member variables
private:
    GLfloat _pos_x, _pos_y;
    GLfloat _orientation;
    GLfloat _radius;    // radius of the circle
};

#endif /* Sphere.cpp */
