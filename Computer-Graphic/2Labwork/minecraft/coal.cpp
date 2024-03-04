#include <iostream>
#include <stdlib.h>

#include <GL/glew.h>
#include <GL/glut.h>
#include <SOIL/SOIL.h> // For loading texture

using namespace std;
struct Vector3f {
  float x, y, z;
  Vector3f(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
};

Vector3f Eye(4, 4, 5);

void changeSize(int w, int h) {
  if (h == 0)
    h = 1; // Prevent a divide by zero, when window is too short
  float ratio = 1.0 * w / h;

  // Reset the coordinate system before modifying
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  glViewport(0, 0, w, h);

  gluPerspective(60, ratio, 0.1, 10000);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(Eye.x, Eye.y, Eye.z, 0.0, 0.0, 0.0, 0.0, 0, 1.0);
}

GLuint texture;

void configTexture() {
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
                  GL_LINEAR_MIPMAP_LINEAR);
  glGenerateMipmap(GL_TEXTURE_2D);
}

int loadTexture() {
  texture = SOIL_load_OGL_texture("diamond_base.png", SOIL_LOAD_AUTO,
                                  SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);

  if (texture == 0) {
    std::cout << "SOIL loading error: " << SOIL_last_result() << std::endl;
    return false;
  }

  configTexture();

  return true;
}

void drawCube() {
  glPushMatrix(); // Reset The Current Modelview Matrix
  glTranslatef(0.0f, 0.0f, 0.0f);

  glBegin(GL_QUADS);
  glTexCoord2f(1.0, 0.0);
  glVertex3f(1.0f, 1.0f, -1.0f); // Top Right Of The Quad (Top)
  glTexCoord2f(0.0, 0.0);
  glVertex3f(-1.0f, 1.0f, -1.0f); // Top Left Of The Quad (Top)
  glTexCoord2f(0.0, 1.0);
  glVertex3f(-1.0f, 1.0f, 1.0f); // Bottom Left Of The Quad (Top)
  glTexCoord2f(1.0, 1.0);
  glVertex3f(1.0f, 1.0f, 1.0f); // Bottom Right Of The Quad (Top)

  glTexCoord2f(1.0, 0.0);
  glVertex3f(1.0f, -1.0f, 1.0f); // Top Right Of The Quad (Bottom)
  glTexCoord2f(0.0, 0.0);
  glVertex3f(-1.0f, -1.0f, 1.0f); // Top Left Of The Quad (Bottom)
  glTexCoord2f(0.0, 1.0);
  glVertex3f(-1.0f, -1.0f, -1.0f); // Bottom Left Of The Quad (Bottom)
  glTexCoord2f(1.0, 1.0);
  glVertex3f(1.0f, -1.0f, -1.0f); // Bottom Right Of The Quad (Bottom)

  glTexCoord2f(0.0, 0.0);
  glVertex3f(1.0f, 1.0f, 1.0f); // Top Right Of The Quad (Front)
  glTexCoord2f(1.0, 0.0);
  glVertex3f(-1.0f, 1.0f, 1.0f); // Top Left Of The Quad (Front)
  glTexCoord2f(1.0, 1.0);
  glVertex3f(-1.0f, -1.0f, 1.0f); // Bottom Left Of The Quad (Front)
  glTexCoord2f(0.0, 1.0);
  glVertex3f(1.0f, -1.0f, 1.0f); // Bottom Right Of The Quad (Front)

  glTexCoord2f(1.0, 0.0);
  glVertex3f(1.0f, -1.0f, -1.0f); // Top Right Of The Quad (Back)
  glTexCoord2f(0.0, 0.0);
  glVertex3f(-1.0f, -1.0f, -1.0f); // Top Left Of The Quad (Back)
  glTexCoord2f(0.0, 1.0);
  glVertex3f(-1.0f, 1.0f, -1.0f); // Bottom Left Of The Quad (Back)
  glTexCoord2f(1.0, 1.0);
  glVertex3f(1.0f, 1.0f, -1.0f); // Bottom Right Of The Quad (Back)

  glTexCoord2f(0.0, 0.0);
  glVertex3f(-1.0f, 1.0f, 1.0f); // Top Right Of The Quad (Left)
  glTexCoord2f(1.0, 0.0);
  glVertex3f(-1.0f, 1.0f, -1.0f); // Top Left Of The Quad (Left)
  glTexCoord2f(1.0, 1.0);
  glVertex3f(-1.0f, -1.0f, -1.0f); // Bottom Left Of The Quad (Left)
  glTexCoord2f(0.0, 1.0);
  glVertex3f(-1.0f, -1.0f, 1.0f); // Bottom Right Of The Quad (Left)

  glTexCoord2f(0.0, 0.0);
  glVertex3f(1.0f, 1.0f, -1.0f); // Top Right Of The Quad (Right)
  glTexCoord2f(1.0, 0.0);
  glVertex3f(1.0f, 1.0f, 1.0f); // Top Left Of The Quad (Right)
  glTexCoord2f(1.0, 1.0);
  glVertex3f(1.0f, -1.0f, 1.0f); // Bottom Left Of The Quad (Right)
  glTexCoord2f(0.0, 1.0);
  glVertex3f(1.0f, -1.0f, -1.0f); // Bottom Right Of The Quad (Right)
  glEnd();                        // Done Drawing The Quad
  glPopMatrix();
}

void drawAxes() {
  glColor3f(1.0, 0.0, 0.0); // red x
  glBegin(GL_LINES);
  // x aix

  glVertex3f(-2.0, 0.0f, 0.0f);
  glVertex3f(4.0, 0.0f, 0.0f);

  // arrow
  glVertex3f(4.0, 0.0f, 0.0f);
  glVertex3f(3.5, 0.5f, 0.0f);

  glVertex3f(4.0, 0.0f, 0.0f);
  glVertex3f(3.5, -0.5f, 0.0f);
  glEnd();
  glFlush();

  // y
  glColor3f(0.0, 1.0, 0.0); // green y
  glBegin(GL_LINES);
  glVertex3f(0.0, -2.0f, 0.0f);
  glVertex3f(0.0, 4.0f, 0.0f);

  // arrow
  glVertex3f(0.0, 4.0f, 0.0f);
  glVertex3f(0.5, 3.5f, 0.0f);

  glVertex3f(0.0, 4.0f, 0.0f);
  glVertex3f(-0.5, 3.5f, 0.0f);
  glEnd();
  glFlush();

  // z
  glColor3f(0.0, 0.0, 1.0); // blue z
  glBegin(GL_LINES);
  glVertex3f(0.0, 0.0f, -2.0f);
  glVertex3f(0.0, 0.0f, 4.0f);

  // arrow
  glVertex3f(0.0, 0.0f, 4.0f);
  glVertex3f(0.0, 0.5f, 3.5f);

  glVertex3f(0.0, 0.0f, 4.0f);
  glVertex3f(0.0, -0.5f, 3.5f);
  glEnd();
  glFlush();
}

void drawObjects(GLvoid) // Here's Where We Do All The Drawing
{
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, texture);

  // drawAxes();
  drawCube();

  glDisable(GL_TEXTURE_2D);
}

void renderScene(void) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0.0, 0.0, 0.0, 0.0);

  drawObjects();

  glutSwapBuffers();
}

void initGL(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE |
                      GLUT_RGBA); // The mode parameter is a Boolean combination
  glutInitWindowPosition(100, 100); //-1,-1 up to the windows manager
  glutInitWindowSize(640, 480);
  glutCreateWindow("A Textured cube");

  glewExperimental = 1;
  GLenum err = glewInit();
  if (err != GLEW_OK) {
    // Problem: glewInit failed, something is seriously wrong.
    std::cout << "glewInit failed: " << glewGetErrorString(err) << std::endl;
    exit(1);
  }

  loadTexture();
  glutDisplayFunc(renderScene);
  glutIdleFunc(renderScene);
  glutReshapeFunc(changeSize);

  glEnable(GL_DEPTH_TEST);
  glClearColor(1.0, 1.0, 1.0, 1.0);
}

int main(int argc, char **argv) {
  initGL(argc, argv);
  glutMainLoop();

  return 0;
}
