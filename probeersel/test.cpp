#include <iostream>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

// Stuff that should go into some include
#define PI 3.1415926535898
double ClockGetTime()
{
    timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    return (double)ts.tv_sec + (double)ts.tv_nsec / 1000000000;
}


typedef enum ForceType {TO_state1, TO_state2} ForceType;
static GLfloat decceleration(800.0);    // in degrees per second^2
static GLfloat acceleration(800.0);

// defining the two spin states
static GLfloat state1(0.0);             // in degrees per second
static GLfloat state2(180.0);

// defining the initial state of the system
static GLfloat spinspeed(state1);
static ForceType force(TO_state1);
static double currentTime (ClockGetTime());

static GLfloat orientation (0.0);
static GLfloat scale (0.5);


void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {
		case 27: //Escape key
			exit(0);
	}
}
    
void initRendering() {
	glClearColor (0.1, 0.0, 0.0, 0.0);
    glShadeModel (GL_SMOOTH);
    glEnable(GL_POINT_SMOOTH);  // make sure the drawn points are round!
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_POLYGON_SMOOTH);
    glEnable(GL_BLEND);
    glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
    glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
    glCullFace(GL_BACK);
    glEnable(GL_CULL_FACE);
    glDisable(GL_DEPTH_TEST);
}

void handleResize(int w, int h) {
    // choose what part of the window represents the OpenGL viewport (here the entire screen)
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);

    // Set the matrix for viewing (Projection matrix)
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
    // use parallel projection matrix, the parameters denote the clipping box that is used around the scene.
//    glOrtho(-scale*(GLfloat)w/2.0, scale*(GLfloat)w/2.0, -scale*(GLfloat)h/2.0, scale*(GLfloat)h/2.0, -1.0, 1.0);
    gluOrtho2D(-scale*(GLfloat)w/2.0, scale*(GLfloat)w/2.0, -scale*(GLfloat)h/2.0, scale*(GLfloat)h/2.0);

    // set the model transformation matrix  WHY?
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT);

    glBlendFunc(GL_SRC_ALPHA_SATURATE, GL_ONE);
    glPushMatrix();
    glRotatef(orientation, 0.0, 0.0, 1.0);

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
	
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    GLfloat angle;
    GLfloat radius(60);
    int segments(100);

	glColor3f(0.0f, 0.0f, 1.0f);
    glLineWidth(2.0f);
    glLineStipple(2, 0x3F07);
    glEnable(GL_LINE_STIPPLE);
    glBegin(GL_LINE_LOOP);
        for (int i=0; i < segments; ++i)
        {
            angle = 2*PI*i/segments;
            glVertex2f(radius*cos(angle), radius*sin(angle));
        }
    glEnd();
    glDisable(GL_LINE_STIPPLE);

    glPointSize(16.0f);
	glColor3f(0.0f, 1.0f, 1.0f);
    glBegin(GL_POINTS);
        glVertex2f(-50, -70);
        glVertex2f(-30, -70);
        glVertex2f(-10, -70);
    glEnd();

    glutSwapBuffers();      // OpenGL commands issued after the swap will only be rendered after the swap took place
	glFlush();              // Force the excecution of the commands (not sure this is needed when using SwapBuffers)

}

GLfloat get_rotation(double const dt)
// returns the amount of rotation the cube did in 'dt' time
// note: spinspeed is a global variable
{
    // First check if the system is in one of the stable states
    if (spinspeed <= state1 && force == TO_state1)
    {
        spinspeed = state1;     // make sure that the spin is really in the state
    }
    else if (spinspeed >= state2 && force == TO_state2)
    {
        spinspeed = state2;
    }

    // If not in one of the stable states:
    else if (force == TO_state1)
    {
        spinspeed -= decceleration* dt;  // The rotational speed (spin) needs to be propagated
    }
    else if (force == TO_state2)
    {
        spinspeed += acceleration* dt;
    }
    else
    {
        throw 1;        // never get here
    }

    // integrate the spin over dt
    return spinspeed * dt;
}

void main_loop(int i)
{
//    sleep(1);
    double newTime (ClockGetTime());
    double dt (newTime-currentTime);  // 'dt' is in seconds
    currentTime = newTime;

    orientation += get_rotation(dt);
    if (orientation > 360.0)
        orientation -= 360.0;
    glutPostRedisplay();
	glutTimerFunc(25, main_loop, 0);
}

void mouse(int button, int state, int x, int y)
{
    switch (button)
    {
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_DOWN)
                force = TO_state1;  // The pressing of the buttons just modifies the state of the force
            break;
        case GLUT_RIGHT_BUTTON:
            if (state == GLUT_DOWN)
                force = TO_state2;
            break;
//        case GLUT_MIDDLE_BUTTON:
//            if (state == GLUT_DOWN)
//            break;
        default:
            break;
    }
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_ALPHA);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(100, 100);
	
	glutCreateWindow("Second test");
	initRendering();

    // get some OpenGL info (Note that we can only do it after initialization or smt)
    GLfloat values[2];
    glGetFloatv (GL_POINT_SIZE_RANGE, values);
    std::cout << "GL_POINT_SIZE_RANGE: " << values[0] << ", " << values[1] << std::endl;
    glGetFloatv (GL_LINE_WIDTH_RANGE, values);
    std::cout << "GL_LINE_WIDTH_RANGE: " << values[0] << ", " << values[1] << std::endl;
    glGetFloatv (GL_LINE_WIDTH_GRANULARITY, values);
    std::cout << "GL_LINE_WIDTH_GRANULARITY: " << values[0] << std::endl;
	
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);
    glutMouseFunc(mouse);
//    glutIdleFunc(main_loop);
	glutTimerFunc(25, main_loop, 0);	// start the update sequence
	
    // start handling events and such
	glutMainLoop();
	return 0;
}









