#ifndef TRIANGLE_CPP
#define TRIANGLE_CPP

#include <GL/gl.h>

typedef enum ForceType {TO_state1, TO_state2} ForceType;

// Class for a triangle-like thing that can rotate
class Triangle
{

protected:
    // defining the acceleration and decelleration constants
    static const GLfloat decceleration = 800.0;    // in degrees per second^2
    static const GLfloat acceleration = 800.0;

    // defining the two spin states
    static const GLfloat state1 = 0.0;             // in degrees per second
    static const GLfloat state2 = 180.0;

public:
    void set_force(ForceType const force)
    {
        _force = force;
    }

    void propagate(double const dt)
    // returns the amount of rotation the cube did in 'dt' time
    // note: spinspeed is a global variable
    {

        _pos_x += _movespeed * dt;

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
    }

    void draw()
    {
        glPushMatrix();
        glTranslatef(_pos_x, _pos_y, (GLfloat)0.0);
        glRotatef(_orientation, 0.0, 0.0, 1.0);

    //    glRectf(-25.0, -25.0, 25.0, 25.0);  // draw a rectangle
        glBegin(GL_POLYGON);
            glColor3f(1.0f, 1.0f, 1.0f);
            glVertex3f(-25, -25, 0.0);
            glVertex3f(25, -25, 0.0);
            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex3f(35, 35, 0.0);
            glColor3f(1.0f, 1.0f, 1.0f);
            glVertex3f(-25, 25, 0.0);
        glEnd();
        glPopMatrix();
    }

    // The constructor
    Triangle() : _pos_x(0.0), _pos_y(0.0), _orientation(0),
                 _movespeed(10.0), _spinspeed(state1), _force(TO_state1) {};

private:
    // defining the state variables and the initial state
    GLfloat     _pos_x, _pos_y;
    GLfloat     _orientation;
    GLfloat     _movespeed;
    GLfloat     _spinspeed;
    ForceType   _force;
};

#endif /* Triangle class */
