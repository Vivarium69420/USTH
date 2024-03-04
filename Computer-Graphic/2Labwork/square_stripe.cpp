#include <iostream>
#include <stdlib.h>

#include <GL/glew.h>
#include <GL/glut.h>
#include <SOIL/SOIL.h> // For loading texture

struct Vector3f {
  float x, y, z;
  Vector3f(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
};

Vector3f Eye(0, -1, 0.5);

void changeSize(int w, int h) {
  if (h == 0)
    h = 1;
  float ratio = 1.0 * w / h;

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  glViewport(0, 0, w, h);

  gluPerspective(60, ratio, 0.1, 10000);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(Eye.x, Eye.y, Eye.z, 0, 0, 0, 0, 1, 0);
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
  texture = SOIL_load_OGL_texture("stripe.jpg", SOIL_LOAD_AUTO,
                                  SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);

  if (texture == 0) {
    std::cout << "SOIL loading error: " << SOIL_last_result() << std::endl;
    return false;
  }

  configTexture();

  return true;
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  gluLookAt(Eye.x, Eye.y, Eye.z, 0, 0, 0, 0, 1, 0);

  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, texture);
  // CCW (counter clockwise)
  glBegin(GL_POLYGON);

  glTexCoord2f(0.0, 1.0);
  glVertex3f(-0.5, -0.5, 0.0); // Bottom-left
  glTexCoord2f(1.0, 1.0);
  glVertex3f(0.5, -0.5, 0.0); // Bottom-right
  glTexCoord2f(1.0, 0.0);
  glVertex3f(0.5, 3.5, 0.0); // Top-right
  glTexCoord2f(0.0, 0.0);
  glVertex3f(-0.5, 3.5, 0.0); // Top-left
  glEnd();

  glFlush();
  glDisable(GL_TEXTURE_2D);
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

  glutInitWindowPosition(80, 80);
  glutInitWindowSize(400, 400);
  glutCreateWindow("A texture mapped square");

  glewExperimental = 1;
  GLenum err = glewInit();
  if (err != GLEW_OK) {
    // Problem: glewInit failed, something is seriously wrong.
    std::cout << "glewInit failed: " << glewGetErrorString(err) << std::endl;
    exit(1);
  }

  loadTexture();
  glutDisplayFunc(display);
  glutReshapeFunc(changeSize);

  glEnable(GL_DEPTH_TEST);

  glutMainLoop();
}
