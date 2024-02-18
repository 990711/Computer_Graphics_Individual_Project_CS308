#include "GL/glut.h"
#include <math.h>
#include "SOIL2.h"
#include <stdio.h>

constexpr float PI = 3.14159265358979323846;
float an = 0;
float increment = 0.4;
int width;
int height;
unsigned char* image;
GLuint tex;

//variables to move the camera
GLfloat camX = 0.0; GLfloat camY = 0.0; GLfloat camZ = 0.0;

//variables to move the scene
GLfloat sceRX = 0.0; GLfloat sceRY = 0.0; GLfloat sceRZ = 0.0;
GLfloat sceTX = 0.0; GLfloat sceTY = 0.0; GLfloat sceTZ = 0.0;

////variables to move the objects
GLfloat objRX = 0.0; GLfloat objRY = 0.0; GLfloat objRZ = 0.0;
GLfloat objTX = 0.0; GLfloat objTY = 0.0; GLfloat objTZ = 0.0;


void loadTextures() {
	image = SOIL_load_image("plane_mirror.jpg", &width, &height, 0, SOIL_LOAD_RGB);

	if (image == NULL) {
		printf("Error : %s", SOIL_last_result());
	}

	glGenTextures(1, &tex);
	glBindTexture(GL_TEXTURE_2D, tex);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}
void drawGrid() {
	GLfloat step = 1.0f;
	GLint line;

	glBegin(GL_LINES);
	for (line = -20; line <= 20; line += step) {
		glVertex3f(line, -0.4, 20);
		glVertex3f(line, -0.4, -20);

		glVertex3f(20, -0.4, line);
		glVertex3f(-20, -0.4, line);
	}
	glEnd();
}

void drawAxes() {

	glBegin(GL_LINES);

	glLineWidth(1.5);

	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-200, 0, 0);
	glVertex3f(200, 0, 0);

	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0, -200, 0);
	glVertex3f(0, 200, 0);

	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0, 0, -200);
	glVertex3f(0, 0, 200);

	glEnd();
}

void init(void) {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClearDepth(1.0);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	loadTextures();
}

void object() {
	glBegin(GL_QUADS);
	/*glTexCoord2f(0, 0); glVertex3f(-6, -4, 0);
	glTexCoord2f(1, 0); glVertex3f(6,-4,0);
	glTexCoord2f(1, 1); glVertex3f(6,4,0);
	glTexCoord2f(0, 1); glVertex3f(-6,4,0);*/
	glTexCoord2f(0, 0); glVertex3f(-5, 5, 2);
	glTexCoord2f(1, 0); glVertex3f(5, 5, 2);
	glTexCoord2f(1, 1); glVertex3f(5, 5, -2);
	glTexCoord2f(0, 1); glVertex3f(-5, 5, -2);
	glEnd();
}



void drawPyramid(float x, float y, float z, float height) {
	//glBindTexture(GL_TEXTURE_2D, tex);  // Bind the texture



	//glBindTexture(GL_TEXTURE_2D, 0);  // Unbind the texture
}


void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	// camera orientation (eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ)
	gluLookAt(0.0, 0.0 + camY, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	object();



glPopMatrix();
glutSwapBuffers();
}

void reshape(GLsizei w, GLsizei h) {
	glViewport(0, 0, w, h);
	GLfloat aspect_ratio = h == 0 ? w / 1 : (GLfloat)w / (GLfloat)h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//Define the Perspective projection frustum 
	// (FOV_in_vertical, aspect_ratio, z-distance to the near plane from the camera position, z-distance to far plane from the camera position)
	gluPerspective(120.0, aspect_ratio, 1.0, 100.0);

}



int main(void) {
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Complex 3D Shapes");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	init();
	glutMainLoop();
	return 0;
}