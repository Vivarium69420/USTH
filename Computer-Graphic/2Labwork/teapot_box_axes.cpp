// #include <GL/glew.h>//OpenGL Extension Wrangler Library
#include <GL/glut.h> //Utilities e.g: setting camera view and projection

using namespace std;
struct Vector3f {
  float x, y, z;
  Vector3f(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
};

Vector3f Eye(8, 8, 10); // eye position
Vector3f lightPos(4, 0, 4); // lightDir vector
Vector3f lightColor(1, 0.5, 0.0);
float MaterialSh = 120;
//
GLfloat rtri = 0;  // Angle For The Triangle ( NEW )
GLfloat rquad = 0; // Angle For The Quad ( NEW )

void changeSize(int w, int h) {
  if (h == 0)
    h = 1; // Prevent a divide by zero, when window is too short
  float ratio = 1.0 * w / h;

  // Reset the coordinate system before modifying
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  // Set the viewport to be the entire window
  glViewport(0, 0, w, h);
  // Set the correct perspective.
  gluPerspective(60, ratio, 0.1, 10000); // fovy, ratio, near, far

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(Eye.x, Eye.y, Eye.z, 0.0, 0.0, 0.0, 0.0, 0, 1.0); // eye, at, up
}

void drawTriangles() {
  glLoadIdentity(); // Reset The Current Modelview Matrix
                    // glTranslatef(-1.5f,0.0f,-6.0f);
                    // //
  // Move Left 1.5 Units And Into The Screen 6.0 glRotatef(rtri,0.0f,1.0f,0.0f);

  glLoadIdentity();
  // Reset The Current Modelview Matrix glTranslatef(-1.5f,0.0f,-6.0f);
  // Move Left 1.5 Units And Into The Screen 6.0
  glRotatef(rtri,0.0f,1.0f,0.0f);			    	   // Rotate The
  // Triangle On The Y axis ( NEW ) rtri+=0.02f;
  // Increase The Rotation Variable For The Triangle ( NEW ) cout << "Rotate
  // angle " << rtri<< endl;

  // glBegin(GL_TRIANGLES);
  // // Start Drawing A Triangle 	glColor3f(1.0f,0.0f,0.0f);
  //// Red 	glVertex3f( 0.0f, 1.0f, 0.0f);
  //// Top Of Triangle (Front) 	glColor3f(0.0f,1.0f,0.0f);
  //// Green 	glVertex3f(-1.0f,-1.0f, 1.0f);
  //// Left Of Triangle (Front) 	glColor3f(0.0f,0.0f,1.0f);
  //// Blue 	glVertex3f( 1.0f,-1.0f, 1.0f);
  //// Right Of Triangle (Front) 	glColor3f(1.0f,0.0f,0.0f);
  //// Red 	glVertex3f( 0.0f, 1.0f, 0.0f);
  //// Top Of Triangle (Right) 	glColor3f(0.0f,0.0f,1.0f);
  //// Blue 	glVertex3f( 1.0f,-1.0f, 1.0f);
  //// Left Of Triangle (Right) 	glColor3f(0.0f,1.0f,0.0f);
  //// Green 	glVertex3f( 1.0f,-1.0f, -1.0f);				   //
  // Right Of Triangle (Right) 	glColor3f(1.0f,0.0f,0.0f);
  //// Red 	glVertex3f( 0.0f, 1.0f, 0.0f);
  //// Top Of Triangle (Back) 	glColor3f(0.0f,1.0f,0.0f);
  //// Green 	glVertex3f( 1.0f,-1.0f, -1.0f);				   //
  // Left Of Triangle (Back) 	glColor3f(0.0f,0.0f,1.0f);
  //// Blue 	glVertex3f(-1.0f,-1.0f, -1.0f);				   //
  // Right Of Triangle (Back) 	glColor3f(1.0f,0.0f,0.0f);
  //// Red 	glVertex3f( 0.0f, 1.0f, 0.0f);
  //// Top Of Triangle (Left) 	glColor3f(0.0f,0.0f,1.0f);
  //// Blue 	glVertex3f(-1.0f,-1.0f,-1.0f);
  //// Left Of Triangle (Left) 	glColor3f(0.0f,1.0f,0.0f);
  //// Green 	glVertex3f(-1.0f,-1.0f, 1.0f);
  //// Right Of Triangle (Left) glEnd();
}
void drawTeapot() {
  glPushMatrix();
  glTranslatef(0, 0, 5.0f);
  glColor3f(0.0, 1.0, 1.0);

  glRotatef(90, 1, 0.0f, 0);

  rquad -= 0.15f; // Decrease The Rotation Variable For The Quad ( NEW )
  glRotatef(rquad, 0, 1, 0);
  glutSolidTeapot(2.0);
  // glutWireTeapot(1.5);
  // glutSolidSphere(1, 8, 8);
  // glColor3f(1.0, 1.0, 0.0);
  // glutWireTeapot(2.0);
  glEnd();
  glPopMatrix();
}

void drawCube() {
  glPushMatrix();
  // glLoadIdentity();
  // // Reset The Current Modelview Matrix
  glTranslatef(0.0f, -3.0f, 0.0f); // Move -3 along y axis
  // glRotatef(rquad, 1.0f, 1.0f, 1.0f);				 //
  // Rotate The Quad On The X axis ( NEW )
  rquad -= 0.015f;   // Decrease The Rotation Variable For The Quad ( NEW )
  glBegin(GL_QUADS); // Draw A Quad
  glColor3f(0.0f, 1.0f, 0.0f);     // Set The Color To Green
  glVertex3f(1.0f, 1.0f, -1.0f);   // Top Right Of The Quad (Top)
  glVertex3f(-1.0f, 1.0f, -1.0f);  // Top Left Of The Quad (Top)
  glVertex3f(-1.0f, 1.0f, 1.0f);   // Bottom Left Of The Quad (Top)
  glVertex3f(1.0f, 1.0f, 1.0f);    // Bottom Right Of The Quad (Top)
  glColor3f(1.0f, 0.5f, 0.0f);     // Set The Color To Orange
  glVertex3f(1.0f, -1.0f, 1.0f);   // Top Right Of The Quad (Bottom)
  glVertex3f(-1.0f, -1.0f, 1.0f);  // Top Left Of The Quad (Bottom)
  glVertex3f(-1.0f, -1.0f, -1.0f); // Bottom Left Of The Quad (Bottom)
  glVertex3f(1.0f, -1.0f, -1.0f);  // Bottom Right Of The Quad (Bottom)
  glColor3f(1.0f, 0.0f, 0.0f);     // Set The Color To Red
  glVertex3f(1.0f, 1.0f, 1.0f);    // Top Right Of The Quad (Front)
  glVertex3f(-1.0f, 1.0f, 1.0f);   // Top Left Of The Quad (Front)
  glVertex3f(-1.0f, -1.0f, 1.0f);  // Bottom Left Of The Quad (Front)
  glVertex3f(1.0f, -1.0f, 1.0f);   // Bottom Right Of The Quad (Front)
  glColor3f(1.0f, 1.0f, 0.0f);     // Set The Color To Yellow
  glVertex3f(1.0f, -1.0f, -1.0f);  // Top Right Of The Quad (Back)
  glVertex3f(-1.0f, -1.0f, -1.0f); // Top Left Of The Quad (Back)
  glVertex3f(-1.0f, 1.0f, -1.0f);  // Bottom Left Of The Quad (Back)
  glVertex3f(1.0f, 1.0f, -1.0f);   // Bottom Right Of The Quad (Back)
  glColor3f(0.0f, 0.0f, 1.0f);     // Set The Color To Blue
  glVertex3f(-1.0f, 1.0f, 1.0f);   // Top Right Of The Quad (Left)
  glVertex3f(-1.0f, 1.0f, -1.0f);  // Top Left Of The Quad (Left)
  glVertex3f(-1.0f, -1.0f, -1.0f); // Bottom Left Of The Quad (Left)
  glVertex3f(-1.0f, -1.0f, 1.0f);  // Bottom Right Of The Quad (Left)
  glColor3f(1.0f, 0.0f, 1.0f);     // Set The Color To Violet
  glVertex3f(1.0f, 1.0f, -1.0f);   // Top Right Of The Quad (Right)
  glVertex3f(1.0f, 1.0f, 1.0f);    // Top Left Of The Quad (Right)
  glVertex3f(1.0f, -1.0f, 1.0f);   // Bottom Left Of The Quad (Right)
  glVertex3f(1.0f, -1.0f, -1.0f);  // Bottom Right Of The Quad (Right)
  glEnd();                         // Done Drawing The Quad
  glPopMatrix();
}

void drawTriangle() {
  // glLoadIdentity();
  glMatrixMode(GL_MODELVIEW);
  glColor3f(0.0, 1.0, 0.0);
  glBegin(GL_TRIANGLES);
  glVertex3f(-0.5, -0.5, 0.0);
  glVertex3f(0.5, 0.0, 0.0);
  glVertex3f(0.0, 0.5, 0.0);
  glEnd();
}
void drawAxes() {
  glColor3f(1.0, 0.0, 0.0); // red x
  glBegin(GL_LINES);
  // x aix

  glVertex3f(-4.0, 0.0f, 0.0f);
  glVertex3f(4.0, 0.0f, 0.0f);

  // arrow
  glVertex3f(4.0, 0.0f, 0.0f);
  glVertex3f(3.0, 1.0f, 0.0f);

  glVertex3f(4.0, 0.0f, 0.0f);
  glVertex3f(3.0, -1.0f, 0.0f);
  glEnd();
  glFlush();

  // y
  glColor3f(0.0, 1.0, 0.0); // green y
  glBegin(GL_LINES);
  glVertex3f(0.0, -4.0f, 0.0f);
  glVertex3f(0.0, 4.0f, 0.0f);

  // arrow
  glVertex3f(0.0, 4.0f, 0.0f);
  glVertex3f(1.0, 3.0f, 0.0f);

  glVertex3f(0.0, 4.0f, 0.0f);
  glVertex3f(-1.0, 3.0f, 0.0f);
  glEnd();
  glFlush();

  // z
  glColor3f(0.0, 0.0, 1.0); // blue z
  glBegin(GL_LINES);
  glVertex3f(0.0, 0.0f, -4.0f);
  glVertex3f(0.0, 0.0f, 4.0f);

  // arrow
  glVertex3f(0.0, 0.0f, 4.0f);
  glVertex3f(0.0, 1.0f, 3.0f);

  glVertex3f(0.0, 0.0f, 4.0f);
  glVertex3f(0.0, -1.0f, 3.0f);
  glEnd();
  glFlush();
}
void drawObjects(GLvoid) // Here's Where We Do All The Drawing
{
  drawAxes();
  drawTriangle();
  // drawTriangles();
  // // Done Drawing The Pyramid
  // drawCube();
  drawTeapot();
  glMatrixMode(GL_MODELVIEW);//default param is GL_MODELVIEW
  gluLookAt(Eye.x, Eye.y, Eye.z, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);//eye, at, up
}

void renderScene(void) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0.0, 0.0, 0.0, 0.0);

  drawObjects();

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  //  Set the viewport to be the entire window
  int w = 650;
  int h = 480;
  glViewport(0, 0, w, h);
  //  Set the correct perspective.
  float ratio = 1.0 * w / h;
  gluPerspective(60, ratio, 0.1, 10000); // fovy, ratio, near, far

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(Eye.x, Eye.y, Eye.z, 0.0, 0.0, 0.0, 0.0, 0, 1.0); // eye, at, up
  glutSwapBuffers();
}

void initGL(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE |
                      GLUT_RGBA); // The mode parameter is a Boolean combination
  glutInitWindowPosition(100, 100); //-1,-1 up to the windows manager
  glutInitWindowSize(640, 480);
  glutCreateWindow("Lighting");

  glutDisplayFunc(renderScene);
  glutIdleFunc(renderScene);
  glutReshapeFunc(changeSize);

  glEnable(GL_DEPTH_TEST);
  glClearColor(1.0, 1.0, 1.0, 1.0);
}

int main(int argc, char **argv) {
  initGL(argc, argv);
  glutMainLoop(); // says: we're ready to get in the event processing loop

  return 0;
}
