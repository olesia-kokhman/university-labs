#define _CRT_SECURE_NO_WARNINGS

#include <glut.h>
#include <math.h>
#include <iostream>

GLuint textureID;
GLfloat angle = 0.0f;
GLfloat speed_rotate = 1.0f;
bool light_on = true;

GLfloat objectPosition[] = { 0.0f, 0.0f, 0.0f }; // Початкові координати об'єкта
GLfloat objectVelocity[] = { 0.03f, 0.04f, 0.03f }; // Швидкості переміщення об'єкта
GLfloat speed_move = 0.3f;


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


void init() {
    glEnable(GL_TEXTURE_2D);
    glClearColor(0.8f, 0.8f, 0.8f, 1.0f);


    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);


    GLfloat light0_position[] = { -0.0f, 0.0f, -2.0f, 1.0f };  // Змінено z-координату на -10.0f
    GLfloat light0_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat light0_ambient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    GLfloat light0_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };

    glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular);


    GLfloat material_ambient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    GLfloat material_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
    GLfloat material_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat material_shininess = 32.0f;

    glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular);
    glMaterialf(GL_FRONT, GL_SHININESS, material_shininess);

    // Завантаження текстури
    textureID = LoadTexture("C:\\Users\\Olesia\\Downloads\\bricks_256.bmp"); // Замініть шлях до вашого файлу

    if (textureID == 0) {
        std::cerr << "Помилка завантаження текстури\n";
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

    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    glTranslatef(objectPosition[0], objectPosition[1], objectPosition[2]);
    glRotatef(-30, 0.0, 0.0, 1.0);
    glRotatef(angle, 0.0, 1.0, 0.0);
    glBindTexture(GL_TEXTURE_2D, textureID);

    GLUquadricObj* quadric = gluNewQuadric();
    gluQuadricTexture(quadric, GL_TRUE);
    
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

void update(int value) {
    angle += speed_rotate;
    if (angle > 360) {
        angle -= 360;
    }

    // Оновлення координат об'єкта
    for (int i = 0; i < 3; ++i) {
        objectPosition[i] += objectVelocity[i];

        // Відбиття від обмежувальних площин
        if (objectPosition[i] > 3.0f || objectPosition[i] < -3.0f) {
            objectVelocity[i] = -objectVelocity[i];
        }
    }

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (GLfloat)w / (GLfloat)h, 1.0f, 100.0f);
    //glFrustum(-3,3,-3,3,1,40);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// Функція для обробки подій контекстного меню
void contextMenu(int value) {
    switch (value) {
    case 1: // Змінити швидкості  переміщення

        for (int i = 0; i < 3; i++) {
            objectVelocity[i] >= 0 ? objectVelocity[i] += 0.01 : objectVelocity[i] -= 0.01;
        }
        break;
    case 2: // Змінити швидкості  переміщення

        for (int i = 0; i < 3; i++) {
            objectVelocity[i] <= 0 ? objectVelocity[i] += 0.01 : objectVelocity[i] -= 0.01;
        }
        break;
    case 3:
        speed_rotate += 1.0f;
        break;
    case 4:
        if (speed_rotate > 1)
            speed_rotate -= 1.0f;
        break;
    case 5: // Вмикання/вимикання джерел освітлення

        if (light_on) {
            glDisable(GL_LIGHT0);
            light_on = false;
        }
        else {
            glEnable(GL_LIGHT0);
            light_on = true;
        }
        break;
    }
    glutPostRedisplay();
}

void keyboardFunc(unsigned char key, int x, int y) {
    switch (key) {
    case 27:
        exit(0);
        break;
    }
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutCreateWindow("Textured Rotating Sphere");
    glutFullScreen();
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutTimerFunc(25, update, 0);

    // Створення контекстного меню
    glutCreateMenu(contextMenu);
    glutAddMenuEntry("Change Speeds:+0.1", 1);
    glutAddMenuEntry("Change Speeds:-0.1", 2);
    glutAddMenuEntry("Rotate Speeds:+1.0", 3);
    glutAddMenuEntry("Rotate Speeds:-1.0", 4);
    glutAddMenuEntry("Toggle Lighting", 5);

    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutKeyboardFunc(keyboardFunc);
    init();
    glutMainLoop();

    return 0;
}

