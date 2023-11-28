#include <gl\glut.h>
#include <math.h>

//variables to move the camera
GLfloat camX = 0.0; GLfloat camY = 0.0; GLfloat camZ = 0.0;

//variables to move the scene
GLfloat sceRX = 0.0; GLfloat sceRY = 0.0; GLfloat sceRZ = 0.0;
GLfloat sceTX = 0.0; GLfloat sceTY = 0.0; GLfloat sceTZ = 0.0;

////variables to move the objects
GLfloat objRX = 0.0; GLfloat objRY = 0.0; GLfloat objRZ = 0.0;
GLfloat objTX = 0.0; GLfloat objTY = 0.0; GLfloat objTZ = 0.0;

constexpr float PI = 3.14159265358979323846;

float vertices[][3] = { {0,2.5,0},{2,2.5,0},{2,2.5,0.2},{0,2.5,0.2},{0,0,0},{2,0,0},{2,0,0.2},{0,0,0.2} };


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
	glEnable(GL_DEPTH_TEST);
}

void setLighting() {
	// Lighting set up
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
	glEnable(GL_LIGHTING);
	//glEnable(GL_LIGHT0);

	// Set lighting intensity and color
	GLfloat qaAmbientLight[] = { 0.2, 0.2, 0.2, 1.0 };
	GLfloat qaDiffuseLight[] = { 0.8, 0.8, 0.8, 1.0 };
	GLfloat qaSpecularLight[] = { 1.0, 1.0, 1.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_AMBIENT, qaAmbientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, qaDiffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, qaSpecularLight);

	// Set the light position
	GLfloat qaLightPosition[] = { 5.0, 1.0, 5, 1.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition);
}

void drawSurface4(int v1, int v2, int v3, int v4) {
	glBegin(GL_POLYGON);
	glVertex3fv(vertices[v1]);
	glVertex3fv(vertices[v2]);
	glVertex3fv(vertices[v3]);
	glVertex3fv(vertices[v4]);
	glEnd();
}

void drawBackPart() {
	// draw back of the seat
	drawSurface4(0, 1, 2, 3);
	drawSurface4(4, 5, 6, 7);
	drawSurface4(3, 0, 4, 7);
	drawSurface4(2, 1, 5, 6);
	drawSurface4(3, 2, 6, 7);
	drawSurface4(0, 1, 5, 4);
}

void drawSeat() {

	//back part
	glPushMatrix();
	glRotatef(-10, 1, 0, 0);
	drawBackPart();
	glPopMatrix();

	//seat
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	drawBackPart();
	glPopMatrix();

	//left arm
	glPushMatrix();
	glScalef(0.15,1,0.8);
	glTranslatef(-2,1,-0.5);
	glRotatef(90, 1, 0, 0);
	drawBackPart();
	glPopMatrix();

	//right arm
	glPushMatrix();
	glScalef(0.15, 1, 0.8);
	glTranslatef(13.25, 1, -0.5);
	glRotatef(90, 1, 0, 0);
	drawBackPart();
	glPopMatrix();

	//seat stand
	glPushMatrix();
	glScalef(1, 0.4,0.2);
	glTranslatef(0, -3, 0);
	drawBackPart();
	glPopMatrix();

	glPushMatrix();
	glScalef(1, 0.4, 0.2);
	glTranslatef(0, -3, 0);
	glRotatef(90, 1, 0, 0);
	drawBackPart();
	glPopMatrix();

}

void drawSeatSet() {
	int i = 0;
	int j = 0;
	float rowGap = 0;
	float colGap = 0;

	int p = 0;
	int q = 0;
	float rowGap2 = 0;
	float colGap2 = -6;

	for (i;i < 6;i++) {
		for (j;j < 3;j++) {
			glPushMatrix();
			glTranslatef(colGap, 0, rowGap);
			drawSeat();
			glPopMatrix();

			colGap = colGap + 2.5;
		}
		rowGap = rowGap - 4;
		colGap = 0;
		j = 0;
	}

	for (p;p < 6;p++) {
		for (q;q < 3;q++) {
			glPushMatrix();
			glTranslatef(colGap2, 0, rowGap2);
			drawSeat();
			glPopMatrix();

			colGap2 = colGap2 - 2.5;
		}
		rowGap2 = rowGap2 - 4;
		colGap2 = -6;
		q = 0;
	}


}

void drawScene() {
	drawSeatSet();
}

void drawSceneWithLighting() {
	// Set material properties
	GLfloat qaBlack[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat qaGreen[] = { 0.0, 1.0, 0.0, 1.0 };
	GLfloat qaRed[] = { 1.0, 0.0, 0.0, 1.0 };
	GLfloat qaBrown[] = { 0.75, 0.59, 0.36, 1.0 };
	GLfloat qaBlue[] = { 0.0, 0.0, 1.0, 1.0 };
	GLfloat qaLightBlue[] = { 0.0, 0.0, 0.5, 1.0 };
	GLfloat qaWhite[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat qaLowAmbient[] = { 0.2, 0.2, 0.2, 1.0 };
	GLfloat qaFullAmbient[] = { 1.0, 1.0, 1.0, 1.0 };

	//for (int iIndex = 0; iIndex < 5; ++iIndex) {
		/*
		if (iIndex == 0) {
			glShadeModel(GL_FLAT);
		}
		else {
			glShadeModel(GL_SMOOTH);
		}

		*/

		glShadeModel(GL_SMOOTH);

		//Set, ambient, diffuse and specular lighting. Set ambient to 20%.
		glMaterialfv(GL_FRONT, GL_AMBIENT, qaLightBlue);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaLightBlue);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
		glMaterialf(GL_FRONT, GL_SHININESS, 20.0);
		//glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);

		// Draw a sphere

		/*glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glPushMatrix();
		glTranslatef(-2 + (float)iIndex * 8, 0.5, -2.0);
		drawPyramid();
		glPopMatrix();*/

		glPushMatrix();
		//glScalef(2, 2, 2);
		drawScene();
		glPopMatrix();

	//}
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	// camera orientation (eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ)
	gluLookAt(0.0 + camX, 3.0 + camY, 10.0 + camZ, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	// move the scene (all the rendered environment) using keyboard keys
	glTranslatef(sceTX, sceTY, sceTZ);
	glRotatef(sceRY, 0.0, 1.0, 0.0);

	////Draw a grid on the xz plane
	//glColor3f(1, 1, 1);
	//drawGrid();
	////draw the three axes
	//drawAxes();

	setLighting();

	drawSceneWithLighting();

	//drawScene();

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

void keyboardSpecial(int key, int x, int y) {
	if (key == GLUT_KEY_UP)
		camY += 1;

	if (key == GLUT_KEY_DOWN)
		camY -= 1;

	if (key == GLUT_KEY_RIGHT)
		camX += 1;

	if (key == GLUT_KEY_LEFT)
		camX -= 1;



	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
	if (key == 'l')
		objRY += 1;

	if (key == 'r')
		objRY -= 1;

	if (key == 'Z')
		sceTZ += 1;

	if (key == 'z')
		sceTZ -= 1;

	if (key == 'w')
		sceTX += 1;

	if (key == 's')
		sceTX -= 1;

	if (key == 'y')
		sceRY += 1;

	if (key == 'Y')
		sceRY -= 1;

	if (key == 'o')
		glEnable(GL_LIGHT0);

	if (key == 'f')
		glDisable(GL_LIGHT0);

	glutPostRedisplay();
}


int main(void) {
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Complex 3D Shapes");
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(keyboardSpecial);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	init();
	glutMainLoop();
	return 0;
}

