#define _CRT_SECURE_NO_WARNINGS
#include <glut.h>
#include <iostream>

GLfloat angle = 0.0f;
GLuint textureID;
static GLint fogMode; // Fog mode

GLuint LoadTexture(const char* filename) {
    GLuint texture;
    int width, height;
    unsigned char* data;

    FILE* file;
    file = fopen(filename, "rb");

    if (file == NULL) return 0;

    fseek(file, 18, SEEK_SET);
    fread(&width, sizeof(int), 1, file);
    fread(&height, sizeof(int), 1, file);

    int size = width * height * 3;
    data = (unsigned char*)malloc(size);
    if (data == nullptr) {
        std::cerr << "Error allocating memory for texture data" << std::endl;
        fclose(file);
        return -1;
    }

    // Read the texture data
    fseek(file, 54, SEEK_SET); // Skip header
    fread(data, sizeof(unsigned char), size, file);

    // Close the file
    fclose(file);

    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_RGB, GL_UNSIGNED_BYTE, data);
    free(data);

    return texture;
}

void initLighting() {
    // Ambient light
    GLfloat ambientLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);

    // Point light
    glColor3f(1.0f, 0.5f, 0.7f);
    GLfloat pointLight_position[] = { -3.0f, 3.0f, -0.0f, 1.0f };
    GLfloat pointLight_diffuse[] = { 1.0f, 1.0f, 0.0f, 1.0f };
    GLfloat pointLight_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat pointLight_constantAttenuation = 0.1f;
    GLfloat pointLight_linearAttenuation = 0.05f;
    GLfloat pointLight_quadraticAttenuation = 0.01f;
    glLightfv(GL_LIGHT0, GL_POSITION, pointLight_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, pointLight_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, pointLight_specular);
    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, pointLight_constantAttenuation);
    glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, pointLight_linearAttenuation);
    glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, pointLight_quadraticAttenuation);
    glEnable(GL_LIGHT0);

    // Прожекторне джерело світла
    GLfloat spotLight_position[] = { 0.0f, 0.0f, 5.0f, 1.0f };
    GLfloat spotLight_direction[] = { 0.0f, 0.0f, -1.0f };
    GLfloat spotLight_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat spotLight_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat spotLight_cutoff = 30.0f;
    GLfloat spotLight_exponent = 10.0f;
    glLightfv(GL_LIGHT1, GL_POSITION, spotLight_position);
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spotLight_direction);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, spotLight_diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, spotLight_specular);
    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, spotLight_cutoff);
    glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, spotLight_exponent);
    glEnable(GL_LIGHT1);
    printf("Прожектор\n");

    // Віддалене джерело світла
    GLfloat distantLight_direction[] = { 0.0f, -1.0f, 0.0f };
    GLfloat distantLight_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
    GLfloat distantLight_specular[] = { 0.8f, 0.8f, 0.8f, 1.0f };
    glLightfv(GL_LIGHT2, GL_POSITION, distantLight_direction);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, distantLight_diffuse);
    glLightfv(GL_LIGHT2, GL_SPECULAR, distantLight_specular);
    glEnable(GL_LIGHT2);
    printf("Віддалене\n");

    // Ввімкнення освітлення та матеріалів
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, spotLight_specular);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 30.0f);

    // Enable lighting and materials
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
}

void init() {
    glEnable(GL_TEXTURE_2D);
    glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
    glEnable(GL_DEPTH_TEST);

   // glEnable(GL_FOG);

    // Налаштування параметрів туману
    /*GLfloat fogColor[4] = { 0.5, 0.5, 0.5, 1.0 };
    fogMode = GL_EXP;
    glFogi(GL_FOG_MODE, fogMode);
    glFogfv(GL_FOG_COLOR, fogColor);
    glFogf(GL_FOG_DENSITY, 0.1);
    glHint(GL_FOG_HINT, GL_DONT_CARE);
    glFogf(GL_FOG_START, 8.0);
    glFogf(GL_FOG_END, 15.0);*/


    // Load texture
    textureID = LoadTexture("C:\\Users\\Olesia\\Downloads\\bricks_256.bmp");

    if (textureID == 0) {
        std::cerr << "Error loading texture\n";
    }

    glEnable(GL_DEPTH_TEST);
}

void drawCube() {
    glBegin(GL_QUADS);
    // Ліва грань 
    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
    // Права грань 
    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, -1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, -1.0f, 1.0f);
    // Задня грань
    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
    // Передня грань 
    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
    // Верхня грань 
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    // Нижня грань 
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glEnd();
}

void drawPyramid() {
    glBegin(GL_TRIANGLES);
    // База піраміди
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);

    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);

    // Бокові сторони піраміди
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f); // Вершина
    glVertex3f(-1.0f, -1.0f, -1.0f); // Базова вершина 1
    glVertex3f(1.0f, -1.0f, -1.0f); // Базова вершина 2

    glVertex3f(0.0f, 1.0f, 0.0f); // Вершина
    glVertex3f(1.0f, -1.0f, -1.0f); // Базова вершина 2
    glVertex3f(1.0f, -1.0f, 1.0f); // Базова вершина 3

    glVertex3f(0.0f, 1.0f, 0.0f); // Вершина
    glVertex3f(1.0f, -1.0f, 1.0f); // Базова вершина 3
    glVertex3f(-1.0f, -1.0f, 1.0f); // Базова вершина 1

    glVertex3f(0.0f, 1.0f, 0.0f); // Вершина
    glVertex3f(-1.0f, -1.0f, 1.0f); // Базова вершина 1
    glVertex3f(-1.0f, -1.0f, -1.0f); // Базова вершина 2

    glEnd();
}

void display() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Камера
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    glRotatef(angle, 1.0, 1.0, 1.0);

    // Рендеринг куба
    glPushMatrix();
    glTranslatef(0.0, -0.5, 0.0); // Переміщення куба вниз
    drawCube();
    glPopMatrix();

    // Рендеринг піраміди (даху)
    glPushMatrix();
    glTranslatef(0.0, 1.5, 0.0); // Переміщення піраміди вгору
    drawPyramid();
    glPopMatrix();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (GLfloat)w / (GLfloat)h, 1.0f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void update(int value) {
    angle += 0.5f; // Швидкість обертання
    if (angle > 360.0f)
        angle -= 360.0f;
    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutCreateWindow("Textured Rotating Cube");
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutTimerFunc(25, update, 0);
    init();
    initLighting();
    glutMainLoop();

    return 0;
}



