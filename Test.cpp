#include <windows.h> //Optional
#include <GL\glut.h>
#include <math.h>

float PI = 3.14;
int animationFactor = 0;

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT); //clearing color buffer
}

void reshape(GLsizei w, GLsizei h) {
    glViewport(0, 0, w, h);
    //calculate aspect ratio
    if (h == 0)
        h = 1;
    GLfloat aspect = (GLfloat)w / (GLfloat)h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w >= h)
        gluOrtho2D(-10 * aspect, 10 * aspect, -10, 10);
    else
        gluOrtho2D(-10, 10, -10 / aspect, 10 / aspect);
}

void drawDisk(double radius, int n) {

    double angle = 0;

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_POLYGON);
    for (int c = 0; c <= n; c++) {
        double x = radius * cos(angle);
        double y = radius * sin(angle);
        glVertex2d(x, y);
        angle = angle + ((2 * PI) / n);
    }
    glEnd();

}

void drawLines(double rad_1, double rad_2, int n) {
    glColor3f(0.0, 0.0, 0.0);
    double angle = 0;

    for (int c = 0; c <= n; c++) {


        double x_1 = rad_1 * cos(angle);
        double y_1 = rad_1 * sin(angle);

        double x_2 = rad_2 * cos(angle);
        double y_2 = rad_2 * sin(angle);

        glBegin(GL_LINES);
        glVertex2d(x_1, y_1);
        glVertex2d(x_2, y_2);
        glEnd();

        angle = angle + ((2 * PI) / n);

    }

}

void drawHand(double val) {

    /*
    glBegin(GL_TRIANGLES);
    glVertex2d(-0.5,0);
    glVertex2d(0.5,0);
    glVertex2d(0,11);
    glEnd();
    */

    //glLineWidth(4);
    glBegin(GL_LINES);
    glVertex2d(0, 0);
    glVertex2d(0, val);
    glEnd();
}

void animate(int value) {
    glutPostRedisplay();
    glutTimerFunc(1000, animate, 0);
}

void drawClock() {
    glClear(GL_COLOR_BUFFER_BIT);
    /*y axis
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(0, 10);
    glVertex2f(0, -10);
    glEnd();

     x axis
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(10, 0);
    glVertex2f(-10, 0);
    glEnd();*/



    glLineWidth(15.0);
    glColor3f(0.7, 0.7, 0.7);
    glPushMatrix();
    glTranslated(0, 7, 0);
    drawHand(1);
    glPopMatrix();

    glLineWidth(20.0);
    glColor3f(0.6, 0.8, 1.0);
    glPushMatrix();
    glTranslated(-1.75, 8, 0);
    glRotated(-90, 0, 0, 1);
    drawHand(3.5);
    glPopMatrix();

    glLineWidth(15.0);
    glColor3f(0.7, 0.7, 0.7);
    glPushMatrix();
    glTranslated(5, -4, 0);
    glRotated(-150, 0, 0, 1);
    drawHand(3.5);
    glPopMatrix();

    glLineWidth(15.0);
    glColor3f(0.7, 0.7, 0.7);
    glPushMatrix();
    glTranslated(-5, -4, 0);
    glRotated(150, 0, 0, 1);
    drawHand(3.5);
    glPopMatrix();

    /*glLineWidth(15.0);
    glColor3f(0.7, 0.7, 0.7);
    glPushMatrix();
    glTranslated(5, 4, 0);
    glRotated(-35, 0, 0, 1);
    drawHand(2);
    glPopMatrix();

    glLineWidth(15.0);
    glColor3f(0.7, 0.7, 0.7);
    glPushMatrix();
    glTranslated(-5, 4, 0);
    glRotated(35, 0, 0, 1);
    drawHand(2);
    glPopMatrix();*/

    glPushMatrix();
    glColor3f(0.6, 0.8, 1.0);
    glTranslated(5, 4, 0);
    drawDisk(2, 720);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.6, 0.8, 1.0);
    glTranslated(-5, 4, 0);
    drawDisk(2, 720);
    glPopMatrix();


    /*glPushMatrix();
    glColor3f(1,1,1);
    glTranslated(4, 5, 0);
    drawDisk(2, 720);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslated(-4, 5, 0);
    drawDisk(2, 720);
    glPopMatrix();

    glLineWidth(15.0);
    glColor3f(0.7, 0.7, 0.7);
    glPushMatrix();
    glTranslated(4, 5, 0);
    glRotated(-35, 0, 0, 1);
    drawHand(2);
    glPopMatrix();

    glLineWidth(15.0);
    glColor3f(0.7, 0.7, 0.7);
    glPushMatrix();
    glTranslated(-4, 5, 0);
    glRotated(35, 0, 0, 1);
    drawHand(2);
    glPopMatrix();*/



    glColor3f(0.4, 0.4, 1.0);
    drawDisk(7, 720);

    glColor3f(0.9, 0.9, 0.9);
    drawDisk(6, 720);

    glColor3f(1.0, 1.0, 1.0);
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    drawDisk(5.5, 720);

    glLineWidth(3.0);
    drawLines(6, 5.5, 12);

    glLineWidth(1.0);
    drawLines(6, 5.7, 60);

    /*glPushMatrix();
    glScaled(0.5, 0.5, 0);
    drawHand();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.5, 0.3, 0);
    glRotated(-60, 0, 0, 1);
    drawHand();
    glPopMatrix();*/

    glLineWidth(4.0);

    glPushMatrix();
    //glRotated(-90, 0, 0, 1);
    glRotated(-animationFactor / 10, 0, 0, 1);
    drawHand(5);
    glPopMatrix();

    glPushMatrix();
    //glRotated(-90, 0, 0, 1);
    glRotated(-animationFactor / 120, 0, 0, 1);
    drawHand(4);
    glPopMatrix();

    glLineWidth(4.0);
    glColor3f(1, 0, 0);
    glPushMatrix();
    glRotated(-animationFactor * 6, 0, 0, 1);
    drawHand(5);
    glPopMatrix();

    glColor3f(0.0, 0.0, 0.0);
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    drawDisk(0.5, 720);

    glColor3f(1.0, 1.0, 1.0);
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    drawDisk(0.3, 720);




    glutSwapBuffers();

    animationFactor++;
}



void display() {



    glPushMatrix();
    glScaled(0.8, 0.8, 0);
    //glTranslated(0, -3, 0);
    drawClock();
    glPopMatrix();

    glFlush();


}

int main(int argc, char** argv) {
    glutInit(&argc, argv); //initialize the OpenGL environment
    glutInitDisplayMode(GLUT_DOUBLE);//setting the display mode for 2D graphics (optional)

    //Create the display window
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(720, 480);
    glutCreateWindow("Clock");

    //Call the init function
    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(1000, animate, 0);


    glutMainLoop();
    return 0;
}