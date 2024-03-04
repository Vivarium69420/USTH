#include <GL/gl.h>
#include <GL/glut.h>

void display() { /* Handler for window-repaint event. Called back when the
                    window first appears and whenever the window needs to be
                    re-painted. */
  glClearColor(0.0f, 0.0f, 0.0f,
               1.0f);           // Set background color to black and opaque
  glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)

  glBegin(GL_TRIANGLES);
  glVertex3f(-0.5f, -0.4f, -1.0f);
  glVertex3f(0.5f, -0.4f, -1.0f);
  glVertex3f(0.0f, 1.0f, -1.0f);
  glEnd();
  glFlush(); // Render now
}

int main(int argc, char **argv) {
  glutInit(&argc, argv); // Initialize GLUT
  glutInitWindowSize(
      640, 480); // Set the window's initial width & height - non-square
  glutInitWindowPosition(50,
                         50); // Position the window's initial top-left corner
  glutCreateWindow("Model Transform"); // Create window with the given title
  glutDisplayFunc(
      display);   // Register callback handler for window re-paint event
  glutMainLoop(); // Enter the infinite event-processing loop
  return 0;
}
