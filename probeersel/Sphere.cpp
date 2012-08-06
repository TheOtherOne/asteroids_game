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
        if (_radius < 10)
        {
            glPointSize(16.0f);
            glColor3f(0.0f, 1.0f, 1.0f);
            glBegin(GL_POINTS);
                glVertex2f(-50, -70);
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
    }

    // constructors
    Sphere() : _radius(MAX_RADIUS) {};
    Sphere(GLfloat const radius) : _radius(radius) {};

// member variables
private:
    GLfloat _radius;    // radius of the circle
};

#endif /* Sphere.cpp */
