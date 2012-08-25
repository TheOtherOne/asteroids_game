#ifndef TEST_CPP
#define TEST_CPP

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "Defs.hpp"
#include "Ship.hpp"
#include "Sphere.cpp"
#include "PhysicsWorld.hpp"



/////////////////////////////////////////////////////////
// Main stuff

static double currentTime (ClockGetTime());
static GLfloat scale (0.5);
static PhysicsWorld universe(300.0, 300.0);
static Ship triangle1(&universe);
static Sphere sphere1(150, 100, 0, 20);
static Sphere sphere2(100, 50, 0, 20);

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
//    gluOrtho2D(-scale*(GLfloat)w/2.0, scale*(GLfloat)w/2.0, -scale*(GLfloat)h/2.0, scale*(GLfloat)h/2.0);
    gluOrtho2D(0, scale*(GLfloat)w, 0, scale*(GLfloat)h);

    // Change the size of the universe to match the new window size
    universe.set_size(scale*(GLfloat)w, scale*(GLfloat)h);

    // set the model transformation matrix (default)
	glMatrixMode(GL_MODELVIEW);
}

void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT);
    // assume that the current matrix is the MODELVIEW matrix
	glLoadIdentity();

    glBlendFunc(GL_SRC_ALPHA_SATURATE, GL_ONE);
    triangle1.draw();
	
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    sphere1.draw();
    sphere2.draw();

    glutSwapBuffers();      // OpenGL commands issued after the swap will only be rendered after the swap took place
	glFlush();              // Force the excecution of the commands (not sure this is needed when using SwapBuffers)

}


void main_loop(int i)
{
//    sleep(1);
    double newTime (ClockGetTime());
    double dt (newTime-currentTime);  // 'dt' is in seconds
    currentTime = newTime;

    // get the new state by integrating over time the old state
    // For now the only state variable is the orientation of the triangle
    triangle1.propagate(dt);
    glutPostRedisplay();
	glutTimerFunc(25, main_loop, 0);
}

void mouse(int button, int state, int x, int y)
{
    switch (button)
    {
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_DOWN)
            {
                triangle1.input(Left);  // The pressing of the buttons just modifies the state of the force
//                std::cout << "left" << std::endl;
            }
            else
            {
                triangle1.input(Neutral);
//                std::cout << "Neutral" << std::endl;
            }
            break;
        case GLUT_RIGHT_BUTTON:
            if (state == GLUT_DOWN)
            {
                triangle1.input(Right);
//                std::cout << "Right" << std::endl;
            }
            else
            {
                triangle1.input(Neutral);
//                std::cout << "Neutral" << std::endl;
            }
            break;
        case GLUT_MIDDLE_BUTTON:
            if (state == GLUT_DOWN)
            {
                triangle1.input(Forward);
//                std::cout << "Forward" << std::endl;
            }
            else
            {
                triangle1.input(Neutral);
//                std::cout << "Neutral" << std::endl;
            }
            break;
        default:
            break;
    }
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_ALPHA);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	
	glutCreateWindow("Asteroids");
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



#endif /* Test.cpp */
