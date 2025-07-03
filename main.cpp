#include<windows.h>
#include <GL/gl.h>
#include <GL/glut.h>

// Display callback function to render the shapes
void display(void)
{
    // Clear all pixels (background color)
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw a white rectangle
    glColor3f(1.0f, 1.0f, 1.0f); // Set color to white
    glBegin(GL_QUADS);           // Start drawing a quadrilateral
        glVertex3f(0.1f, 0.1f, 0.0f); // Bottom-left corner
        glVertex3f(0.4f, 0.1f, 0.0f); // Bottom-right corner
        glVertex3f(0.4f, 0.4f, 0.0f); // Top-right corner
        glVertex3f(0.1f, 0.4f, 0.0f); // Top-left corner
    glEnd();                     // End quadrilateral drawing

    // Draw a red triangle
    glColor3f(1.0f, 0.0f, 0.0f); // Set color to red
    glBegin(GL_TRIANGLES);       // Start drawing a triangle
        glVertex3f(0.6f, 0.2f, 0.0f); // Bottom-left corner
        glVertex3f(0.8f, 0.2f, 0.0f); // Bottom-right corner
        glVertex3f(0.7f, 0.5f, 0.0f); // Top corner
    glEnd();                     // End triangle drawing

    // Draw a blue trapezoid
    glColor3f(0.0f, 0.0f, 1.0f); // Set color to blue
    glBegin(GL_QUADS);           // Start drawing a quadrilateral
        glVertex3f(0.2f, 0.6f, 0.0f); // Bottom-left corner
        glVertex3f(0.5f, 0.6f, 0.0f); // Bottom-right corner
        glVertex3f(0.4f, 0.8f, 0.0f); // Top-right corner
        glVertex3f(0.3f, 0.8f, 0.0f); // Top-left corner
    glEnd();                     // End quadrilateral drawing

    // Draw a green pentagon
    glColor3f(0.0f, 1.0f, 0.0f); // Set color to green
    glBegin(GL_POLYGON);         // Start drawing a polygon
        glVertex3f(0.7f, 0.6f, 0.0f); // Bottom-left corner
        glVertex3f(0.9f, 0.6f, 0.0f); // Bottom-right corner
        glVertex3f(0.85f, 0.75f, 0.0f); // Mid-right corner
        glVertex3f(0.75f, 0.85f, 0.0f); // Top corner
        glVertex3f(0.65f, 0.75f, 0.0f); // Mid-left corner
    glEnd();                     // End polygon drawing

    glFlush(); // Start processing buffered OpenGL routines
}

// Initialize OpenGL settings
void init(void)
{
    // Set the background (clear) color to black
    glClearColor(0.0, 0.0, 0.0, 0.0);

    // Set up the projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Set the orthographic projection (2D view)
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
    // Initialize GLUT
    glutInit(&argc, argv);

    // Set the display mode (single buffer and RGB colors)
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // Set the initial window size (600x600 pixels)
    glutInitWindowSize(600, 600);

    // Set the initial window position on the screen
    glutInitWindowPosition(100, 100);

    // Create the window with a title
    glutCreateWindow("Basic Shapes in OpenGL");

    // Initialize OpenGL settings
    init();

    // Register the display callback function
    glutDisplayFunc(display);

    // Enter the GLUT main loop
    glutMainLoop();

    return 0; // ISO C requires main to return int
}
