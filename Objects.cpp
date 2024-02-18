#include <GL/glut.h>
#include<math.h>
#include <SOIL2.h>
#include <stdio.h>

float camX = 0;
float camY = 0;
float camZ = 0;

float rotX = 0;
float rotY = 0;
float rotZ = 0;

float moveX = 0;
float moveY = 0;
float moveZ = 0;

float narrator_rot = 0;

float lavDoor = 0;

float curtain = 0;

float planeMove = 0;

constexpr float PI = 3.14159265358979323846;

float vertices[][3] = { {0,2.5,0},{2,2.5,0},{2,2.5,0.2},{0,2.5,0.2},{0,0,0},{2,0,0},{2,0,0.2},{0,0,0.2} };

// texture mapping
int width;
int height;

unsigned char* image_ceiling;
unsigned char* image_cockpit;
unsigned char* image_Mirror;
unsigned char* image_seat;
unsigned char* image_cupboard;
unsigned char* image_galleyTop;
unsigned char* image_galleyCupboard;
unsigned char* image_galleyCurtain;
unsigned char* image_rack;
unsigned char* image_exit;
unsigned char* image_floor;

GLuint tex_ceiling;
GLuint tex_cockpit;
GLuint tex_Mirror;
GLuint tex_seat;
GLuint tex_cupboard;
GLuint tex_galleyTop;
GLuint tex_galleyCupboard;
GLuint tex_galleyCurtain;
GLuint tex_rack;
GLuint tex_exit;
GLuint tex_floor;

GLfloat backWallRotation = 0.0;
GLfloat cabinDoorRot = 0.0;

void loadTextures_ceiling() {
	image_ceiling = SOIL_load_image("ceiling_N.jpg", &width, &height, 0, SOIL_LOAD_RGB);

	if (image_ceiling == NULL) {
		printf("Error : %s", SOIL_last_result());
	}

	glGenTextures(1, &tex_ceiling);
	glBindTexture(GL_TEXTURE_2D, tex_ceiling);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image_ceiling);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}

void loadTextures_cockpit() {
	image_cockpit = SOIL_load_image("cockpit_test.jpg", &width, &height, 0, SOIL_LOAD_RGB);

	if (image_ceiling == NULL) {
		printf("Error : %s", SOIL_last_result());
	}

	glGenTextures(1, &tex_cockpit);
	glBindTexture(GL_TEXTURE_2D, tex_cockpit);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image_cockpit);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}

void loadTextures_Mirror() {
	image_Mirror = SOIL_load_image("mirror.jpg", &width, &height, 0, SOIL_LOAD_RGB);

	if (image_ceiling == NULL) {
		printf("Error : %s", SOIL_last_result());
	}

	glGenTextures(1, &tex_Mirror);
	glBindTexture(GL_TEXTURE_2D, tex_Mirror);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image_Mirror);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}

void loadTextures_seat() {
	image_seat = SOIL_load_image("seat_texture.jpg", &width, &height, 0, SOIL_LOAD_RGB);

	if (image_ceiling == NULL) {
		printf("Error : %s", SOIL_last_result());
	}

	glGenTextures(1, &tex_seat);
	glBindTexture(GL_TEXTURE_2D, tex_seat);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image_seat);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}

void loadTextures_cupboard() {
	image_cupboard = SOIL_load_image("cupboard.jpg", &width, &height, 0, SOIL_LOAD_RGB);

	if (image_ceiling == NULL) {
		printf("Error : %s", SOIL_last_result());
	}

	glGenTextures(1, &tex_cupboard);
	glBindTexture(GL_TEXTURE_2D, tex_cupboard);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image_cupboard);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}

void loadTextures_galleyTop() {
	image_galleyTop = SOIL_load_image("galleyTop.jpg", &width, &height, 0, SOIL_LOAD_RGB);

	if (image_ceiling == NULL) {
		printf("Error : %s", SOIL_last_result());
	}

	glGenTextures(1, &tex_galleyTop);
	glBindTexture(GL_TEXTURE_2D, tex_galleyTop);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image_galleyTop);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}

void loadTextures_galleyCupboard() {
	image_galleyCupboard = SOIL_load_image("galleyCupboard.jpg", &width, &height, 0, SOIL_LOAD_RGB);

	if (image_ceiling == NULL) {
		printf("Error : %s", SOIL_last_result());
	}

	glGenTextures(1, &tex_galleyCupboard);
	glBindTexture(GL_TEXTURE_2D, tex_galleyCupboard);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image_galleyCupboard);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}

void loadTextures_galleyCurtain() {
	image_galleyCurtain = SOIL_load_image("curtain.jpg", &width, &height, 0, SOIL_LOAD_RGB);

	if (image_ceiling == NULL) {
		printf("Error : %s", SOIL_last_result());
	}

	glGenTextures(1, &tex_galleyCurtain);
	glBindTexture(GL_TEXTURE_2D, tex_galleyCurtain);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image_galleyCurtain);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}

void loadTextures_rack() {
	image_rack = SOIL_load_image("rack.jpg", &width, &height, 0, SOIL_LOAD_RGB);

	if (image_ceiling == NULL) {
		printf("Error : %s", SOIL_last_result());
	}

	glGenTextures(1, &tex_rack);
	glBindTexture(GL_TEXTURE_2D, tex_rack);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image_rack);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}

void loadTextures_exit() {
	image_exit = SOIL_load_image("exit.jpg", &width, &height, 0, SOIL_LOAD_RGB);

	if (image_ceiling == NULL) {
		printf("Error : %s", SOIL_last_result());
	}

	glGenTextures(1, &tex_exit);
	glBindTexture(GL_TEXTURE_2D, tex_exit);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image_exit);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}

void loadTextures_floor() {
	image_floor = SOIL_load_image("floor.jpg", &width, &height, 0, SOIL_LOAD_RGB);

	if (image_ceiling == NULL) {
		printf("Error : %s", SOIL_last_result());
	}

	glGenTextures(1, &tex_floor);
	glBindTexture(GL_TEXTURE_2D, tex_floor);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image_floor);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}

void init() {
	//glClearColor(0.59, 1, 1, 1);
	glClearColor(0, 0, 0, 1);
	glClearDepth(1.0);
	glEnable(GL_DEPTH_TEST);
	//glEnable(GL_TEXTURE_2D);
	//loadTextures_seat();
}

void drawAxes() {
	glBegin(GL_LINES);

	glLineWidth(1.5);

	glColor3f(1, 0, 0);
	glVertex3f(-30, 0, 0);
	glVertex3f(30, 0, 0);

	glColor3f(0, 1, 0);
	glVertex3f(0, -30, 0);
	glVertex3f(0, 30, 0);

	glColor3f(0, 0, 1);
	glVertex3f(0, 0, -30);
	glVertex3f(0, 0, 30);

	glEnd();
}

void drawGrid() {
	glColor3f(1, 1, 1);
	int x = -30;

	for (x;x < 31;x += 3) {
		glBegin(GL_LINES);
		glVertex3f(x, 0, -30);
		glVertex3f(x, 0, 30);

		glVertex3f(-30, 0, x);
		glVertex3f(30, 0, x);
		glEnd();
	}
}

void setLighting() {
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
	glEnable(GL_LIGHTING);
	//glEnable(GL_LIGHT0);
	//glEnable(GL_LIGHT1);

	GLfloat qaAmbientLight[] = { 0.2, 0.2, 0.2, 1.0 };
	GLfloat qaDiffuseLight[] = { 0.5, 0.5, 0.5, 1.0 };
	GLfloat qaSpecularLight[] = { 1.0, 1.0, 1.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_AMBIENT, qaAmbientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, qaDiffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, qaSpecularLight);

	glLightfv(GL_LIGHT1, GL_AMBIENT, qaAmbientLight);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, qaDiffuseLight);
	glLightfv(GL_LIGHT1, GL_SPECULAR, qaSpecularLight);

	//GLfloat qaLightPosition[] = { 0.0, 0.0, 0.0, 1.0 };
	//glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition);

	GLfloat SpecRef[] = { 0.7,0.7,0.7,1.0 };
	GLint Shine = 128;
	glShadeModel(GL_SMOOTH);
	glEnable(GL_COLOR_MATERIAL);//Tell OpenGL that material properties are defined by glColor*()
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);//Set Ambient and Diffuse to the color defined by glColor*()
	glMaterialfv(GL_FRONT, GL_SPECULAR, SpecRef);//Set specular reflectivity and shininess
	glMateriali(GL_FRONT, GL_SHININESS, Shine);
}

void drawSurface4(int v1, int v2, int v3, int v4) {
	//glPushMatrix();
	//glEnable(GL_TEXTURE_2D);
	//loadTextures_seat();
	glBegin(GL_POLYGON);
	glTexCoord2f(0,1);glVertex3fv(vertices[v1]);
	glTexCoord2f(1,1);glVertex3fv(vertices[v2]);
	glTexCoord2f(1,0);glVertex3fv(vertices[v3]);
	glTexCoord2f(0,0);glVertex3fv(vertices[v4]);
	glEnd();
	//glDisable(GL_TEXTURE_2D);
	//glPopMatrix();
}

void drawBackPart() { // cube for the seat
	// draw back of the seat
	drawSurface4(0, 1, 2, 3);
	drawSurface4(4, 5, 6, 7);
	drawSurface4(3, 0, 4, 7);
	drawSurface4(2, 1, 5, 6);
	drawSurface4(3, 2, 6, 7);
	drawSurface4(0, 1, 5, 4);
}

void drawSeat() {
	glColor3f(0,0.29,0.59);
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
	glColor3f(0,0.19,0.39);
	glScalef(0.15, 1, 0.8);
	glTranslatef(-2, 1, -0.5);
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
	glScalef(1, 0.4, 0.2);
	glTranslatef(0, -3, 0);
	drawBackPart();
	glPopMatrix();

	glPushMatrix();
	glScalef(1, 0.4, 0.2);
	glTranslatef(0, -3, 0);
	glRotatef(90, 1, 0, 0);
	drawBackPart();
	glPopMatrix();

	//seat top pillow
	glPushMatrix();
	glColor3f(1, 1, 1);
	glScalef(0.5, 0.4, 0.1);
	glTranslatef(1, 4.6, -0.2);
	glRotatef(-55, 1, 0, 0);
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

void drawCylinder_Quater(float radius, float height, int n) {
	double angle = 0;

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_QUAD_STRIP);
	//glVertex3d(0, 0, 0);
	for (int c = 0; c <= n; c++) {
		double x = radius * cos(angle);
		double y = 0;
		double z = radius * sin(angle);

		glVertex3f(x, y, z);
		glVertex3f(x, y + height, z);
		angle = angle + ((PI / 2) / n);
	}
	glEnd();
}

void drawDisk(double radius, int n) {
	double angle = 0;

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_TRIANGLE_FAN);
	glVertex3d(0, 0, 0);
	for (int c = 0; c <= n; c++) {
		double z = radius * cos(angle);
		double y = radius * sin(angle);
		glVertex3d(0, y, z);
		angle = angle + ((PI / 2) / n);
	}
	glEnd();

}

void drawDiskFull(double radius, int n) {
	double angle = 0;

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_POLYGON);
	for (int c = 0; c <= n; c++) {
		double x = radius * cos(angle);
		double y = radius * sin(angle);
		glVertex3f(x, y,0);
		angle = angle + ((2 * PI) / n);
	}
	glEnd();

}

void drawCupboard() {
	//loadTextures_cupboard();
	//glEnable(GL_TEXTURE_2D);
	glColor3f(1,1,1);

	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-5, 3, -5);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(5, 3, -5);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(5, -3, -5);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-5, -3, -5);
	glEnd();

	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-5, -3, -5);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(5, -3, -5);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(5, -3, 1);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-5, -3, 1);
	glEnd();

	glPushMatrix();
	glColor3f(0.875, 0.875, 0.875);
	glTranslatef(-5, -3, -5);
	drawDisk(6, 32);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.875, 0.875, 0.875);
	glTranslatef(5, -3, -5);
	drawDisk(6, 32);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.875, 0.875, 0.875);
	glTranslatef(0, 3, -5);
	glRotatef(-backWallRotation, 1, 0, 0);
	glTranslated(5, -6, 0);
	glRotatef(90, 0, 0, 1);
	drawCylinder_Quater(6, 10, 32);
	glPopMatrix();
	
	// handle
	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslated(0,3,-5);
	glRotatef(-backWallRotation, 1, 0, 0);
	glTranslated(0, -5, 6);
	glScaled(3, 1, 1);
	glutSolidCube(0.5);
	glPopMatrix();

	//glDisable(GL_TEXTURE_2D);
}

void drawCupboardSet() {
	int i;
	int x = 0;
	for (i = 0;i < 6;i++) {
		glPushMatrix();
		glTranslated(x, 0, 0);
		drawCupboard();
		glPopMatrix();
		x = x + 11;
	}
}

void drawCylinder(double radius,double height) {
	GLUquadric* quad = gluNewQuadric();
	gluCylinder(quad,radius,radius,height,32,32);
	gluDeleteQuadric(quad);
}

void Cylinder(double base,double top, double height) {
	GLUquadric* quad = gluNewQuadric();
	gluCylinder(quad, base, top, height, 32, 32);
	gluDeleteQuadric(quad);
}

void drawWindow() {
	glPushMatrix();
	glColor3f(1, 1, 1);
	glScaled(0.8,2,1);
	drawCylinder(1, 1);
	glPopMatrix();
}

void drawSquare() {
	//loadTextures_Two();
	//glEnable(GL_TEXTURE_2D);
	glBegin(GL_POLYGON);
	glTexCoord2f(0,1); glVertex3f(-3,2,0);
	glTexCoord2f(1,1); glVertex3f(3,2,0);
	glTexCoord2f(1,0); glVertex3f(3,-2,0);
	glTexCoord2f(0,0); glVertex3f(-3,-2,0);
	glEnd();
	//glDisable(GL_TEXTURE_2D);
}

void squareForRack() {
	//loadTextures_rack();
	//glEnable(GL_TEXTURE_2D);
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 1); glVertex3f(-2.1, 0, -1.1);
	glTexCoord2f(1, 1); glVertex3f(2.1, 0, -1.1);
	glTexCoord2f(1, 0); glVertex3f(2.1, 0, 1.1);
	glTexCoord2f(0, 0); glVertex3f(-2.1, 0, 1.1);
	glEnd();
	//glDisable(GL_TEXTURE_2D);
}

void drawRack() {
	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	glTranslated(-2, 0, -1);
	glRotated(-90, 1, 0, 0);
	drawCylinder(0.1, 4.2);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	glTranslated(2, 0, -1);
	glRotated(-90, 1, 0, 0);
	drawCylinder(0.1, 4.2);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	glTranslated(2, 0, 1);
	glRotated(-90, 1, 0, 0);
	drawCylinder(0.1, 4.2);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	glTranslated(-2, 0, 1);
	glRotated(-90, 1, 0, 0);
	drawCylinder(0.1, 4.2);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 1, 0);
	squareForRack();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 2, 0);
	squareForRack();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 3, 0);
	squareForRack();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 4, 0);
	squareForRack();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.25, 0.25, 0.25);
	glTranslated(-2, 4.2, -1);
	glutSolidSphere(0.1, 32, 32);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.25, 0.25, 0.25);
	glTranslated(2, 4.2, -1);
	glutSolidSphere(0.1, 32, 32);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.25, 0.25, 0.25);
	glTranslated(2, 4.2, 1);
	glutSolidSphere(0.1, 32, 32);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.25, 0.25, 0.25);
	glTranslated(-2, 4.2, 1);
	glutSolidSphere(0.1, 32, 32);
	glPopMatrix();
}

void drawMainCarpet() {
	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	//glTranslatef(-2, -1.5, -10);
	glScalef(28, 0.1, 69);
	glutSolidCube(1.5);
	glPopMatrix();
}

void drawMiddleCarpet() {
	glPushMatrix();
	glColor3f(1, 0, 0);
	//glColor3f(0.39, 0, 0);
	glTranslatef(0, 0.2, 0);
	glScalef(3, 0.1, 69);
	glutSolidCube(1.5);
	glPopMatrix();
}

void ceiling() {
	//glEnable(GL_TEXTURE_2D);
	//loadTextures_ceiling();
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glTexCoord2f(0, 0); glVertex3f(-18,15,40);
	glTexCoord2f(1, 0); glVertex3f(18,15,40);
	glTexCoord2f(1, 1); glVertex3f(18,15,-40);
	glTexCoord2f(0, 1); glVertex3f(-18,15,-40);
	glEnd();
	//glDisable(GL_TEXTURE_2D);
}

void drawCabin() {
	glPushMatrix();
	glTranslated(0, 0, -2);
	drawMainCarpet();
	drawMiddleCarpet();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(4, 3, 20);
	glScalef(2, 2, 2);
	drawSeatSet();
	glPopMatrix();

	glPushMatrix();
	glRotated(90, 0, 1, 0);
	glTranslated(-24, 12, -15);
	glScaled(0.8, 0.6, 0.6);
	drawCupboardSet();
	glPopMatrix();

	glPushMatrix();
	glRotated(-90, 0, 1, 0);
	glTranslated(-20, 12, -15);
	glScaled(0.8, 0.6, 0.6);
	drawCupboardSet();
	glPopMatrix();
}

void drawCommod(){
	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	glRotated(-90, 1, 0, 0);
	Cylinder(2, 3, 4);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	glRotated(-90, 1, 0, 0);
	drawDiskFull(2, 32);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.25, 0.25, 0.25);
	glTranslated(0, 4, 0);
	glRotated(-90, 1, 0, 0);
	glutSolidTorus(0.5, 2.5, 32, 32);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	//glRotated(-90, 1, 0, 0);
	glScaled(1, 2, 1);
	glTranslated(0, 2, -2);
	drawDiskFull(2.5, 32);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0.5, 1);
	glTranslated(0, 1, 0);
	glRotated(90, 1, 0, 0);
	drawDiskFull(0.8, 32);
	glPopMatrix();
}

void drawWashbasin() {
	glPushMatrix();
	glColor3f(0.25, 0.25, 0.25);
	glScaled(2, 2, 1);
	glTranslated(0, -1.5, 0);
	glRotated(-90, 1, 0, 0);
	Cylinder(3, 3.5, 2);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	glScaled(2, 1, 1);
	glTranslated(0, -2, 0);
	glRotated(-90, 1, 0, 0);
	drawDiskFull(3, 32);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	//glScaled(2, 1, 1);
	glTranslated(0, -23, -2);
	glRotated(-90, 1, 0, 0);
	Cylinder(2, 3.5, 20);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslated(0, -1.8, 0);
	glRotated(90, 1, 0, 0);
	drawDiskFull(0.8, 32);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 1, -3);

	glPushMatrix();
	glColor3f(0.25, 0.25, 0.25);
	glBegin(GL_POLYGON);
	glVertex3f(-2, 0, -1);
	glVertex3f(2, 0, -1);
	glVertex3f(2, 0, 1);
	glVertex3f(-2, 0, 1);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	glRotated(-90, 1, 0, 0);
	drawCylinder(0.3, 2);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	//glRotated(-90, 1, 0, 0);
	glTranslated(0, 1, 0);
	drawCylinder(0.3, 2);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.25, 0.25, 0.25);
	glTranslated(0, 2, 0);
	glRotated(-90, 1, 0, 0);
	Cylinder(0.2, 0.4, 0.5);
	glPopMatrix();

	glPopMatrix();
}

void drawLavatory() {
	glPushMatrix();
	glScaled(0.5, 0.5, 0.5);

	glPushMatrix();
	drawWashbasin();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 6, -4);
	glScaled(8, 7, 1);
	glRotated(-90, 1, 0, 0);
	glColor3f(0.875, 0.875, 0.875);
	//glEnable(GL_TEXTURE_2D);
	//loadTextures_Mirror();
	glBegin(GL_POLYGON);
	glTexCoord2f(0,1);glVertex3f(-2, 0, -1);
	glTexCoord2f(1, 1);glVertex3f(2, 0, -1);
	glTexCoord2f(1, 0);glVertex3f(2, 0, 1);
	glTexCoord2f(0, 0);glVertex3f(-2, 0, 1);
	glEnd();
	//glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	glTranslated(0, -3,0);
	glScaled(8, 1, 5);
	glBegin(GL_POLYGON);
	glVertex3f(-2, 0, -1);
	glVertex3f(2, 0, -1);
	glVertex3f(2, 0, 1);
	glVertex3f(-2, 0, 1);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	glTranslated(0, -4, 5);
	glScaled(8, 1, 1);
	glRotated(-90, 1, 0, 0);
	//glColor3f(0.875, 0.875, 0.875);
	glBegin(GL_POLYGON);
	glVertex3f(-2, 0, -1);
	glVertex3f(2, 0, -1);
	glVertex3f(2, 0, 1);
	glVertex3f(-2, 0, 1);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 0, 0);
	glTranslated(-10, -3, 0);
	glRotated(-90, 1, 0, 0);
	drawCylinder(0.5, 3);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 1, 0);
	glTranslated(-12, -3, 0);
	glRotated(-90, 1, 0, 0);
	drawCylinder(0.5, 3);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 1);
	glTranslated(-12, -3, -2);
	glRotated(-90, 1, 0, 0);
	drawCylinder(0.8, 4);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 1, 1);
	glTranslated(-9, -3, 3);
	//glRotated(-90, 1, 0, 0);
	glutSolidCube(3);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1,1,1);
	glTranslated(-9, -1, 3);
	glRotated(-90, 1, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3f(-1, 0, -1);
	glVertex3f(1, 0, -1);
	glVertex3f(1, 0, 1);
	glVertex3f(-1, 0, 1);
	glEnd();
	glPopMatrix();

	glPopMatrix();

	glPushMatrix();
	glScaled(1.2, 1.2, 1.2);
	glTranslated(-6, -9, 6);
	glRotated(90, 0, 1, 0);
	drawCommod();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, -11, 4);
	glScaled(4, 1, 8);
	//glRotated(-90, 1, 0, 0);
	glColor3f(1,1,1);
	//glEnable(GL_TEXTURE_2D);
	//loadTextures_floor();
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 1);glVertex3f(-2, 0, -1);
	glTexCoord2f(1, 1);glVertex3f(2, 0, -1);
	glTexCoord2f(1, 0);glVertex3f(2, 0, 1);
	glTexCoord2f(0, 0);glVertex3f(-2, 0, 1);
	glEnd();
	//glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void drawWheel(double radius, int n) {
	double angle = 0;
	//glLineWidth(2);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_POLYGON);
	for (int c = 0; c <= n; c++) {
		double x = radius * cos(angle);
		double y = radius * sin(angle);
		glVertex3f(x, y, 0);
		angle = angle + ((2 * PI) / n);
	}
	glEnd();
}

void servingCart() {
	glPushMatrix();
	glColor3f(0.59, 0.29, 0);
	glTranslated(-2, 0, -1);
	glRotated(-90, 1, 0, 0);
	drawCylinder(0.1, 3.5);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.59, 0.29, 0);
	glTranslated(2, 0, -1);
	glRotated(-90, 1, 0, 0);
	drawCylinder(0.1, 3.5);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.59, 0.29, 0);
	glTranslated(2, 0, 1);
	glRotated(-90, 1, 0, 0);
	drawCylinder(0.1, 3.5);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.59, 0.29, 0);
	glTranslated(-2, 0, 1);
	glRotated(-90, 1, 0, 0);
	drawCylinder(0.1, 3.5);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 1, 0);
	squareForRack();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 2, 0);
	squareForRack();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 3, 0);
	squareForRack();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.39, 0.19, 0);
	glTranslated(-2, 3.5, -1);
	glutSolidSphere(0.1, 32, 32);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.39, 0.19, 0);
	glTranslated(-2, 3.5, 1);
	glutSolidSphere(0.1, 32, 32);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.59, 0.29, 0);
	glTranslated(2.8, 3.8, 1);
	glRotated(30, 0, 0, 1);
	glRotated(-90, 0, 1, 0);
	drawCylinder(0.1, 1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.59, 0.29, 0);
	glTranslated(2.8, 3.8, -1);
	glRotated(30, 0, 0, 1);
	glRotated(-90, 0, 1, 0);
	drawCylinder(0.1, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(2, 0, 1);
	drawWheel(0.5, 32);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-2, 0, 1);
	drawWheel(0.5, 32);
	glPopMatrix();

	glPushMatrix();
	glTranslated(2, 0, -1);
	drawWheel(0.5, 32);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-2, 0, -1);
	drawWheel(0.5, 32);
	glPopMatrix();
}

void galley() {
	glPushMatrix();
	glRotated(90, 0, 1, 0);

	glPushMatrix();
	//glEnable(GL_TEXTURE_2D);
	//loadTextures_galleyTop();
	glColor3f(1, 1, 1);
	glTranslated(0, -3, 0);
	glScaled(10, 1, 5);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-2, 0, -1);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(2, 0, -1);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(2, 0, 1);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-2, 0, 1);
	glEnd();
	//glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();
	//glEnable(GL_TEXTURE_2D);
	//loadTextures_galleyCupboard();
	glColor3f(1, 1, 1);
	glTranslated(0, 3, -4);
	glRotated(90, 1, 0, 0);
	glScaled(10, 1, 5);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-2, 0, -1);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(2, 0, -1);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(2, 0, 1);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-2, 0, 1);
	glEnd();
	//glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();
	//glEnable(GL_TEXTURE_2D);
	//loadTextures_galleyCupboard();
	glColor3f(1, 1, 1);
	glTranslated(9, -10, 6);
	glRotated(90, 1, 0, 0);
	glScaled(5, 1, 5);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-2, 0, -1);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(2, 0, -1);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(2, 0, 1);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-2, 0, 1);
	glEnd();
	//glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	glTranslated(0, -4, 5);
	glScaled(10, 1, 1);
	glRotated(-90, 1, 0, 0);
	//glColor3f(0.875, 0.875, 0.875);
	glBegin(GL_POLYGON);
	glVertex3f(-2, 0, -1);
	glVertex3f(2, 0, -1);
	glVertex3f(2, 0, 1);
	glVertex3f(-2, 0, 1);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(12, -3, 0);
	glScaled(2, 2, 2);
	drawRack();
	glPopMatrix();

	glPopMatrix();

	glPushMatrix();
	glTranslated(0, -15, 5);
	glScaled(2.5, 2.5, 2.5);
	servingCart();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, -15, 12);
	glScaled(2.5, 2.5, 2.5);
	servingCart();
	glPopMatrix();
}

void drawWindows() {
	int i = 0;
	int gap = 22;
	for (i;i <= 25;i++) {
		glPushMatrix();
		glColor3f(0.59, 0.79, 1);
		glScaled(1, 2, 1);
		glTranslated(-22, 4, gap);
		glRotated(90, 0, 1, 0);
		drawCylinder(1, 1);
		glPopMatrix();
		gap = gap - 4;
	}
	i = 0;
	gap = 22;
	for (i;i <= 25;i++) {
		glPushMatrix();
		glColor3f(0.59, 0.79, 1);
		glScaled(1, 2, 1);
		glTranslated(21, 4, gap);
		glRotated(90, 0, 1, 0);
		drawCylinder(1, 1);
		glPopMatrix();
		gap = gap - 4;
	}
}

void drawMainWing_one() {
	//glPushMatrix();
	//glColor3f(1, 1, 1);
	//glScaled(4, 1, 4);
	//glTranslated(-6, 0, 0);
	//glRotated(30, 0, 0, 1);
	glBegin(GL_POLYGON);
	glVertex3f(4,4,-3);
	glVertex3f(4, 4, 3);
	glVertex3f(-4, 4, 1);
	glVertex3f(-5, 4, 0);
	glVertex3f(-4, 4, -2);
	glEnd();

	/*glBegin(GL_POLYGON);
	glVertex3f(0, 4, -2);
	glVertex3f(0, 4, 1);
	glVertex3f(0, -4, 3);
	glVertex3f(0, -4, -2);
	glEnd();

	glPushMatrix();
	glTranslated(0, -4.5, 3);
	glRotated(-180, 1, 0, 0);
	Cylinder(1.5, 0.5, 5);
	glPopMatrix();*/

	//glPopMatrix();
}

void drawMainWing_two() {
	glBegin(GL_POLYGON);
	glVertex3f(-4, 4, -3);
	glVertex3f(-4, 4, 3);
	glVertex3f(4, 4, 1);
	glVertex3f(5, 4, 0);
	glVertex3f(4, 4, -2);
	glEnd();
}

void taleWings() {
	glBegin(GL_POLYGON);
	glVertex3f(-4, 4, -3);
	glVertex3f(-4, 4, 3);
	glVertex3f(4, 4, 1);
	glVertex3f(4, 4, -2);
	glEnd();
}

void taleWings_two() {
	glBegin(GL_POLYGON);
	glVertex3f(4, 4, -3);
	glVertex3f(4, 4, 3);
	glVertex3f(-4, 4, 1);
	glVertex3f(-4, 4, -2);
	glEnd();
}

void cockpitCarpet() {
	glBegin(GL_TRIANGLES);
	glVertex3f(-11, 0, -5);
	glVertex3f(11, 0, -5);
	glVertex3f(0, 0, 10);
	glEnd();
}

void ceilingFull() {
	int i = 0;
	int z = 20;
	for (i;i < 5;i++) {
		glPushMatrix();
		glTranslated(0, 0, z);
		ceiling();
		glPopMatrix();
		z = z - 20;
	}
}

void drawCockpit() {
	glPushMatrix();
	glColor3f(1, 1, 1);
	glTranslated(0, 5, 0);
	Cylinder(22, 4, 30);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	glTranslated(0, 0, 7);
	glScaled(2, 2, 2);
	cockpitCarpet();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 4, 20);
	glRotated(-90, 1, 0, 0);
	//glEnable(GL_TEXTURE_2D);
	//loadTextures_cockpit();
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glTexCoord2f(0, 0); glVertex3f(-8, 5, 4);
	glTexCoord2f(1, 0); glVertex3f(8, 5, 4);
	glTexCoord2f(1, 1); glVertex3f(8, 5, -4);
	glTexCoord2f(0, 1); glVertex3f(-8, 5, -4);
	glEnd();
	//glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	/*glPushMatrix();
	glTranslated(8, -1, 20);
	glRotated(90, 0, 1, 0);
	glRotated(-20, 1, 0, 0);
	glEnable(GL_TEXTURE_2D);
	loadTextures_cockpit();
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glTexCoord2f(0, 0); glVertex3f(-4, 5, 2);
	glTexCoord2f(1, 0); glVertex3f(4, 5, 2);
	glTexCoord2f(1, 1); glVertex3f(4, 5, -2);
	glTexCoord2f(0, 1); glVertex3f(-4, 5, -2);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-8, -1, 20);
	glRotated(90, 0, 1, 0);
	glRotated(-20, 1, 0, 0);
	glEnable(GL_TEXTURE_2D);
	loadTextures_cockpit();
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glTexCoord2f(0, 0); glVertex3f(-4, 5, 2);
	glTexCoord2f(1, 0); glVertex3f(4, 5, 2);
	glTexCoord2f(1, 1); glVertex3f(4, 5, -2);
	glTexCoord2f(0, 1); glVertex3f(-4, 5, -2);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();*/
}

void drawCabinScene() {
	glPushMatrix();
	drawCabin();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 0, -60);
	drawCabin();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	glTranslated(-10, 4, -30);
	glScaled(1.5, 2, 0.4);
	glutSolidCube(10);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	glTranslated(10, 4, -30);
	glScaled(1.5, 2, 0.4);
	glutSolidCube(10);
	glPopMatrix();

	//Door
	glPushMatrix();
	glColor3f(0.25, 0.25, 0.25);
	glTranslated(-2, 6.5, -32);
	glRotated(cabinDoorRot, 0, 1, 0);
	glTranslated(2, 0, 0);
	glScaled(1.5, 3, 0.2);
	glutSolidCube(5);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.25, 0.25, 0.25);
	glTranslated(-2, 7, -90);
	glRotated(cabinDoorRot, 0, 1, 0);
	glTranslated(2, 0, 0);
	glScaled(1.5, 3, 0.2);
	glutSolidCube(5);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.25, 0.25, 0.25);
	glTranslated(-2, 7, 40);
	glRotated(cabinDoorRot, 0, 1, 0);
	glTranslated(2, 0, 0);
	glScaled(1.5, 3, 0.2);
	glutSolidCube(5);
	glPopMatrix();

	// exit

	glPushMatrix();
	glTranslated(15, 12, 35);
	//glScaled(8, 7, 1);
	glRotated(-90, 0, 1, 0);
	glRotated(-90, 1, 0, 0);
	glColor3f(0.875, 0.875, 0.875);
	//glEnable(GL_TEXTURE_2D);
	//loadTextures_exit();
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 1);glVertex3f(-2, 0, -1);
	glTexCoord2f(1, 1);glVertex3f(2, 0, -1);
	glTexCoord2f(1, 0);glVertex3f(2, 0, 1);
	glTexCoord2f(0, 0);glVertex3f(-2, 0, 1);
	glEnd();
	//glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	glTranslated(-10, 5, -90);
	glScaled(1.5, 2, 0.4);
	glutSolidCube(10);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	glTranslated(10, 5, -90);
	glScaled(1.5, 2, 0.4);
	glutSolidCube(10);
	glPopMatrix();

	glPushMatrix();
	glTranslated(12, 9, -94.5);
	glScaled(0.8, 0.8, 0.8);
	glRotated(-180, 0, 1, 0);
	drawLavatory();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-16, 10, -104);
	glScaled(0.6, 0.6, 0.6);
	galley();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	glTranslated(0, 5, -117);
	glScaled(4, 2, 0.4);
	glutSolidCube(10);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	glTranslated(10, 5, -105);
	glScaled(1.5, 2, 0.4);
	glutSolidCube(10);
	glPopMatrix();

	// lavatory sliding door
	glPushMatrix();
	glColor3f(0.25, 0.25, 0.25);
	glTranslated(0, 0, lavDoor);
	glTranslated(3, 7, -100);
	glRotated(90, 0, 1, 0);
	glScaled(1.5, 3, 0.1);
	glutSolidCube(5);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.25, 0.25, 0.25);
	glTranslated(2.3, 7, -95);
	glRotated(90, 0, 1, 0);
	glScaled(1.5, 3, 0.1);
	glutSolidCube(5);
	glPopMatrix();

	// main body
	glPushMatrix();
	glColor3f(1, 1, 1);
	glTranslated(0, 5, -120);
	drawCylinder(22, 170);
	glPopMatrix();

	// front body
	glPushMatrix();
	glColor3f(1, 1, 1);
	glTranslated(0, 5, 50);
	Cylinder(22, 4, 30);
	glPopMatrix();

	// windows
	glPushMatrix();
	drawWindows();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 1, 1);
	glScaled(8, 1, 4);
	glTranslated(-4, 0, 0);
	glRotated(30, 0, 0, 1);
	drawMainWing_one();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 1, 1);
	glScaled(4, 1, 4);
	glTranslated(-12, -1, 0);
	glBegin(GL_POLYGON);
	glVertex3f(0, 4, -2);
	glVertex3f(0, 4, 1);
	glVertex3f(0, -4, 3);
	glVertex3f(0, -4, -2);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-48, -7.5, 11);
	glScaled(2, 2, 4);
	glRotated(-170, 1, 0, 0);
	Cylinder(1.5, 0.5, 5);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 1, 1);
	glScaled(8, 1, 4);
	glTranslated(4, 0, 0);
	glRotated(-30, 0, 0, 1);
	drawMainWing_two();
	glPopMatrix();

	glPushMatrix();
	glScaled(4, 1, 4);
	glTranslated(12, -1, 0);
	glBegin(GL_POLYGON);
	glVertex3f(0, 4, -2);
	glVertex3f(0, 4, 1);
	glVertex3f(0, -4, 3);
	glVertex3f(0, -4, -2);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(48, -7.5, 11);
	glScaled(2, 2, 4);
	glRotated(-170, 1, 0, 0);
	Cylinder(1.5, 0.5, 5);
	glPopMatrix();

	// tale
	glPushMatrix();
	glTranslated(0, 5, -120);
	glRotated(180, 1, 0, 0);
	Cylinder(22, 2, 30);
	glPopMatrix();

	// tale wings 
	glPushMatrix();
	glScaled(6, 3, 3);
	glTranslated(-4.3, 8, -45);
	glRotated(-20, 0, 1, 0);
	glRotated(160, 0, 0, 1);
	taleWings();
	glPopMatrix();

	glPushMatrix();
	glScaled(6, 3, 3);
	glTranslated(4, 8, -48);
	glRotated(-32, 1, 0, 0);
	glRotated(90, 0, 0, 1);
	taleWings();
	glPopMatrix();

	glPushMatrix();
	glScaled(6, 3, 3);
	glTranslated(4.3, 8, -45);
	glRotated(20, 0, 1, 0);
	glRotated(-160, 0, 0, 1);
	taleWings_two();
	glPopMatrix();

	// cockpit carpet
	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	glTranslated(0, 0, 57);
	glScaled(2, 2, 2);
	cockpitCarpet();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	glTranslated(-10, 5, 30);
	glScaled(1.5, 2, 0.4);
	glutSolidCube(10);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	glTranslated(10, 5, 30);
	glScaled(1.5, 2, 0.4);
	glutSolidCube(10);
	glPopMatrix();

	// main door - entrance
	glPushMatrix();
	glColor3f(0.5,0.5, 0.5);
	//glRotated(cabinDoorRot, 0, 1, 0);
	//glTranslated(0, 4, 15);
	glTranslated(-21, 7, 35);
	glRotated(90, 0, 1, 0);
	glScaled(1.5, 3, 0.4);
	glutSolidCube(5);
	glPopMatrix();

	// main door - exit
	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	//glRotated(cabinDoorRot, 0, 1, 0);
	//glTranslated(0, 4, 15);
	glTranslated(21, 7, 35);
	glRotated(90, 0, 1, 0);
	glScaled(1.5, 3, 0.4);
	glutSolidCube(5);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	glTranslated(-10, 5, 40);
	glScaled(1.5, 2, 0.4);
	glutSolidCube(10);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	glTranslated(10, 5, 40);
	glScaled(1.5, 2, 0.4);
	glutSolidCube(10);
	glPopMatrix();

	// ceiling
	glPushMatrix();
	glTranslated(0, 0, 12);
	ceiling();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 0, -70);
	ceiling();
	glPopMatrix();

	// cockpit
	glPushMatrix();
	glColor3f(1, 1, 1);
	glTranslated(0, 8, 55);
	glRotated(-90, 1, 0, 0);
	//glEnable(GL_TEXTURE_2D);
	//loadTextures_cockpit();
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glTexCoord2f(0, 0); glVertex3f(-18, 5, 8);
	glTexCoord2f(1, 0); glVertex3f(18, 5, 8);
	glTexCoord2f(1, 1); glVertex3f(18, 5, -8);
	glTexCoord2f(0, 1); glVertex3f(-18, 5, -8);
	glEnd();
	//glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	// front covering disk
	glPushMatrix();
	glColor3f(1, 1, 1);
	glTranslated(0, 5, 80);
	drawDiskFull(4, 32);
	glPopMatrix();

	// back covering disk
	glPushMatrix();
	glColor3f(1, 1, 1);
	glTranslated(0, 5, -150);
	drawDiskFull(2, 32);
	glPopMatrix();

	// Galley wall
	glPushMatrix();
	glColor3f(0.25, 0.25, 0.25);
	glTranslated(-3, 7, -98);
	glRotated(90, 0, 1, 0);
	glScaled(3, 3, 0.1);
	glutSolidCube(5);
	glPopMatrix();

	// galley curtain
	glPushMatrix();
	//glEnable(GL_TEXTURE_2D);
	//loadTextures_galleyCurtain();
	glColor3f(1, 1, 1);
	glTranslated(0, 0,curtain);
	glTranslated(-3, 4, -110);
	glRotated(90, 0, 0, 1);
	glScaled(5, 1, 6);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-2, 0, -1);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(2, 0, -1);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(2, 0, 1);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-2, 0, 1);
	glEnd();
	//glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslated(-3,14,-115);
	drawCylinder(0.2, 10);
	glPopMatrix();
}

void test() {
	
}

void drawObject() {
	//drawSeat();
	//drawSeatSet();
	//drawCupboard();
	//test();
	//drawCupboardSet();
	//drawWindow();
	//drawCockpit();
	//drawRack();
	//drawCommod();
	drawLavatory();
	//galley();
	//drawMainWing_one();
	//cockpitCarpet();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	setLighting();

	glPushMatrix();
	glTranslatef(moveX, moveY, moveZ);
	glRotated(narrator_rot, 0, 1, 0);
	gluLookAt(0 + camX, 5 + camY, 100 + camZ, 0, 0, 0, 0, 1, 0);

	glTranslatef(moveX, moveY, moveZ);

	glRotatef(rotX, 1, 0, 0);
	glRotatef(rotY, 0, 1, 0);
	glRotatef(rotZ, 0, 0, 1);

	//drawAxes();

	//drawGrid();

	glPushMatrix();
	//glTranslated(0, 0, 150); // 150
	glTranslated(planeMove, 0, 0);
	drawCabinScene();
	glPopMatrix();
	//drawObject();

	glPopMatrix();

	glutSwapBuffers();

	//rotY++;
}

void keyboardSpecial(int key, int x, int y) {
	if (key == GLUT_KEY_UP)
		rotY += 1;
	if (key == GLUT_KEY_DOWN)
		rotY -= 1;
	if (key == GLUT_KEY_LEFT)
		rotX += 1;
	if (key == GLUT_KEY_RIGHT)
		rotX -= 1;
	if (key == GLUT_KEY_PAGE_UP)
		if (lavDoor <= 6) {
			lavDoor += 1;
		}
	if (key == GLUT_KEY_PAGE_DOWN)
		if (lavDoor >= 0) {
			lavDoor -= 1;
		}


	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
	if (key == 'x') {
		camX += 1;
	}
	if (key == 'y') {
		camY += 1;
	}
	if (key == 'z') {
		camZ += 1;
	}
	if (key == 'X') {
		camX -= 1;
	}
	if (key == 'Y') {
		camY -= 1;
	}
	if (key == 'Z') {
		camZ -= 1;
	}

	if (key == 'w') {
		moveX += 1;
	}
	if (key == 'W') {
		moveX -= 1;
	}
	if (key == 's') {
		moveY += 1;
	}
	if (key == 'S') {
		moveY -= 1;
	}
	if (key == 't') {
		moveZ += 1;
	}
	if (key == 'T') {
		moveZ -= 1;
	}

	if (key == 'c') {
		narrator_rot += 1;
	}
	if (key == 'C') {
		narrator_rot -= 1;
	}

	if (key == 'p') {
		narrator_rot += 1;
	}
	if (key == 'P') {
		narrator_rot -= 1;
	}

	if (key == 'o') {
		glEnable(GL_LIGHT0);
		glEnable(GL_LIGHT1);
	}
	if (key == 'O') {
		glDisable(GL_LIGHT0);
		glDisable(GL_LIGHT1);
	}

	if (key == 'b') {
		if (backWallRotation <= 30) {
			backWallRotation += 0.5;
		}
	}
		

	if (key == 'B') {
		if (backWallRotation > 0) {
			backWallRotation -= 0.5;
		}
	}

	if (key == 'a') {
		if (cabinDoorRot <= 70) {
			cabinDoorRot += 1;
		}
	}


	if (key == 'A') {
		if (cabinDoorRot > 0) {
			cabinDoorRot -= 1;
		}
	}

	if (key == 'g')
		if (curtain <= 6) {
			curtain += 1;
		}
	if (key == 'G')
		if (curtain >= 0) {
			curtain -= 1;
		}
		

	glutPostRedisplay();
}

void Timer(int x) {
	glutPostRedisplay();

	glutTimerFunc(60, Timer, 1);
}

void reshape(GLsizei w, GLsizei h) {
	glViewport(0, 0, w, h);
	GLfloat aspectRatio = h == 0 ? w / 1 : (GLfloat)w / (GLfloat)h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(120, aspectRatio, 1, 100);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(150, 150);
	glutCreateWindow("Practice");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	glutKeyboardFunc(keyboard);
	glutSpecialFunc(keyboardSpecial);

	glutTimerFunc(60, Timer, 1);

	init();
	glutMainLoop();

	return 0;
}