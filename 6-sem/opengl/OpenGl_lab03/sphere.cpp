#include <glut.h>

// Function to set up lighting
void setupLighting() {
    // Enable lighting
    glEnable(GL_LIGHTING);

    // Set up light 0
    glEnable(GL_LIGHT0);
    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    // Set up material properties
    GLfloat mat_ambient[] = { 0.2, 0.2, 0.2, 1.0 }; // Ambient material color
    GLfloat mat_diffuse[] = { 0.8, 0.8, 0.8, 1.0 }; // Diffuse material color
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 }; // Specular material color
    GLfloat mat_shininess[] = { 100.0 }; // Shininess of the material
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}

// Function to display the scene
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    setupLighting(); // Set up lighting

    glEnable(GL_NORMALIZE); // Enable automatic normalization of normals

    glColor3f(1.0, 1.0, 1.0); // White color for the sphere
    glutSolidSphere(1.0, 20, 20); // Display solid sphere

    glDisable(GL_NORMALIZE); // Disable automatic normalization of normals

    glutSwapBuffers();
}

// Function to handle window resizing
void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)width / (double)height, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0); // Move the object back along the z-axis
}

// Function to initialize OpenGL settings
void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // Black background
    glEnable(GL_DEPTH_TEST); // Enable depth testing
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("OpenGL Sphere");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;
}
