#include <GLFW/glfw3.h>
#include <cmath>

void drawSun(float centerX, float centerY, float radius, float red, float green, float blue);
void drawCircledCloud1(float red, float green, float blue);
void drawCircledCloud2(float red, float green, float blue);
void drawCircledLake(float red, float green, float blue);
void drawSimpleBeach(float red, float green, float blue);

void renderInitialScene(GLFWwindow* window) {
    glClearColor(0.7f, 0.8f, 1.0f, 0.5f);
    glClear(GL_COLOR_BUFFER_BIT);

    drawSun(0.9f, 0.85f, 0.2f, 1.0f, 1.0f, 0.0f); // Centered at (0,0) with radius 0.5

    drawSimpleBeach(0.0863f, 0.3686f, 0.0157f);
    drawCircledLake(0.05f, 0.0f, 0.3f);
    
    drawCircledCloud1(0.05f, 0.0f, 0.3f);
    drawCircledCloud2(0.05f, 0.0f, 0.3f);

    glfwSwapBuffers(window);
    glfwPollEvents();

}

void renderColorChangedScene(GLFWwindow* window) {
    glClearColor(0.7f, 0.8f, 1.0f, 0.5f);
    glClear(GL_COLOR_BUFFER_BIT);

    drawSun(0.9f, 0.85f, 0.2f, 1.0f, 0.0f, 0.0f); // Centered at (0,0) with radius 0.5

    drawCircledCloud1(1.0f, 0.75f, 0.8f);
    drawCircledCloud2(1.0f, 0.75f, 0.8f);

    drawSimpleBeach(0.6f, 0.3f, 0.0f);
    drawCircledLake(1.0f, 0.75f, 0.8f);

    glfwSwapBuffers(window);
    glfwPollEvents();
}

void renderDeletingSunScene(GLFWwindow* window) {
    glClearColor(0.7f, 0.8f, 1.0f, 0.5f);
    glClear(GL_COLOR_BUFFER_BIT);

    drawSun(0.9f, 0.85f, 0.2f, 0.7f, 0.8f, 1.0f); // Centered at (0,0) with radius 0.5
    
    drawCircledCloud1(1.0f, 0.75f, 0.8f);
    drawCircledCloud2(1.0f, 0.75f, 0.8f);

    drawSimpleBeach(0.6f, 0.3f, 0.0f);
    drawCircledLake(1.0f, 0.75f, 0.8f);

    glfwSwapBuffers(window);
    glfwPollEvents();
}

void renderDeletingCloudsScene(GLFWwindow* window) {
    glClearColor(0.7f, 0.8f, 1.0f, 0.5f);
    glClear(GL_COLOR_BUFFER_BIT);

    drawSun(0.9f, 0.85f, 0.2f, 0.7f, 0.8f, 1.0f); // Centered at (0,0) with radius 0.5
    
    drawCircledCloud1(0.7f, 0.8f, 1.0f);
    drawCircledCloud2(0.7f, 0.8f, 1.0f);

    drawSimpleBeach(0.6f, 0.3f, 0.0f);
    drawCircledLake(1.0f, 0.75f, 0.8f);

    glfwSwapBuffers(window);
    glfwPollEvents();
}

void renderDeletingBeachScene(GLFWwindow* window) {
    glClearColor(0.7f, 0.8f, 1.0f, 0.5f);
    glClear(GL_COLOR_BUFFER_BIT);

    drawSun(0.9f, 0.85f, 0.2f, 0.7f, 0.8f, 1.0f); // Centered at (0,0) with radius 0.5
    
    drawCircledCloud1(0.7f, 0.8f, 1.0f);
    drawCircledCloud2(0.7f, 0.8f, 1.0f);

    drawSimpleBeach(0.7f, 0.8f, 1.0f);
    drawCircledLake(1.0f, 0.75f, 0.8f);

    glfwSwapBuffers(window);
    glfwPollEvents();
}

void renderDeletingLakeScene(GLFWwindow* window) {
    glClearColor(0.7f, 0.8f, 1.0f, 0.5f);
    glClear(GL_COLOR_BUFFER_BIT);

    drawSun(0.9f, 0.85f, 0.2f, 0.7f, 0.8f, 1.0f); // Centered at (0,0) with radius 0.5
    
    drawCircledCloud1(0.7f, 0.8f, 1.0f);
    drawCircledCloud2(0.7f, 0.8f, 1.0f);

    drawSimpleBeach(0.7f, 0.8f, 1.0f);
    drawCircledLake(0.7f, 0.8f, 1.0f);


    glfwSwapBuffers(window);
    glfwPollEvents();
}


int main(void)
{
    GLFWwindow* window;

    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(900, 700, "Nature", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwSetWindowAttrib(window, GLFW_RESIZABLE, GLFW_FALSE);
    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window))
    {
        renderInitialScene(window);

        glfwSetTime(0.0);
        while (glfwGetTime() < 5.0) {
            glfwPollEvents();
        }
        
        renderColorChangedScene(window);

        glfwSetTime(0.0);
        while (glfwGetTime() < 5.0) {
            glfwPollEvents();
        }

        renderDeletingSunScene(window);

        glfwSetTime(0.0);
        while (glfwGetTime() < 2.0) {
            glfwPollEvents();
        }

        renderDeletingCloudsScene(window);

        glfwSetTime(0.0);
        while (glfwGetTime() < 2.0) {
            glfwPollEvents();
        }

        renderDeletingBeachScene(window);

        glfwSetTime(0.0);
        while (glfwGetTime() < 2.0) {
            glfwPollEvents();
        }

        renderDeletingLakeScene(window);
        glfwSetTime(0.0);
        while (glfwGetTime() < 2.0) {
            glfwPollEvents();
        }

        break;
    }

    glfwTerminate();
    return 0;
}


void drawSun(float centerX, float centerY, float radius, float red, float green, float blue) {
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(red, green, blue); // Set color to yellow
    // Center vertex
    glVertex2f(centerX, centerY);
    // Vertices forming a circle
    for (int i = 0; i <= 360; i += 10) {
        float angle = i * 3.1415926f / 180.0f;
        float x = centerX + radius * cos(angle);
        float y = centerY + radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}

void drawSimpleBeach(float red, float green, float blue) {
    glColor3f(red, green, blue);
    glBegin(GL_QUADS);
    glVertex2f(-1.0, -1.0); // Bottom-left vertex
    glVertex2f(1.0, -1.0);  // Bottom-right vertex
    glVertex2f(1.0, 0.0);   // Top-right vertex
    glVertex2f(-1.0, 0.0);  // Top-left vertex
    glEnd();
}

void drawCircledCloud1(float red, float green, float blue) {
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(red, green, blue); // Set color to yellow
    // Center vertex

    float centerX = -0.7;
    float centerY = 0.8;
    float radius = 0.15;

    glVertex2f(centerX, centerY);
    // Vertices forming a circle
    for (int i = 0; i <= 360; i += 10) {
        float angle = i * 3.1415926f / 180.0f;
        float x = centerX + radius * cos(angle);
        float y = centerY + radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();

    centerX = -0.5;
    centerY = 0.8;
    radius = 0.1;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(red, green, blue); // Set color to yellow
    // Center vertex
    glVertex2f(centerX, centerY);
    // Vertices forming a circle
    for (int i = 0; i <= 360; i += 10) {
        float angle = i * 3.1415926f / 180.0f;
        float x = centerX + radius * cos(angle);
        float y = centerY + radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();

    centerX = -0.5;
    centerY = 0.8;
    radius = 0.1;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(red, green, blue); // Set color to yellow
    // Center vertex
    glVertex2f(centerX, centerY);
    // Vertices forming a circle
    for (int i = 0; i <= 360; i += 10) {
        float angle = i * 3.1415926f / 180.0f;
        float x = centerX + radius * cos(angle);
        float y = centerY + radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();

    centerX = -0.65;
    centerY = 0.7;
    radius = 0.1;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(red, green, blue); // Set color to yellow
    // Center vertex
    glVertex2f(centerX, centerY);
    // Vertices forming a circle
    for (int i = 0; i <= 360; i += 10) {
        float angle = i * 3.1415926f / 180.0f;
        float x = centerX + radius * cos(angle);
        float y = centerY + radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();

    centerX = -0.55;
    centerY = 0.7;
    radius = 0.1;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(red, green, blue); // Set color to yellow
    // Center vertex
    glVertex2f(centerX, centerY);
    // Vertices forming a circle
    for (int i = 0; i <= 360; i += 10) {
        float angle = i * 3.1415926f / 180.0f;
        float x = centerX + radius * cos(angle);
        float y = centerY + radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();

    centerX = -0.45;
    centerY = 0.7;
    radius = 0.1;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(red, green, blue); // Set color to yellow
    // Center vertex
    glVertex2f(centerX, centerY);
    // Vertices forming a circle
    for (int i = 0; i <= 360; i += 10) {
        float angle = i * 3.1415926f / 180.0f;
        float x = centerX + radius * cos(angle);
        float y = centerY + radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}

void drawCircledCloud2(float red, float green, float blue) {
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(red, green, blue); // Set color to yellow
    // Center vertex

    float centerX = 0.0;
    float centerY = 0.8;
    float radius = 0.1;

    glVertex2f(centerX, centerY);
    // Vertices forming a circle
    for (int i = 0; i <= 360; i += 10) {
        float angle = i * 3.1415926f / 180.0f;
        float x = centerX + radius * cos(angle);
        float y = centerY + radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();

    centerX = 0.15;
    centerY = 0.8;
    radius = 0.1;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(red, green, blue); // Set color to yellow
    // Center vertex
    glVertex2f(centerX, centerY);
    // Vertices forming a circle
    for (int i = 0; i <= 360; i += 10) {
        float angle = i * 3.1415926f / 180.0f;
        float x = centerX + radius * cos(angle);
        float y = centerY + radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();

    centerX = -0.1;
    centerY = 0.7;
    radius = 0.1;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(red, green, blue); // Set color to yellow
    // Center vertex
    glVertex2f(centerX, centerY);
    // Vertices forming a circle
    for (int i = 0; i <= 360; i += 10) {
        float angle = i * 3.1415926f / 180.0f;
        float x = centerX + radius * cos(angle);
        float y = centerY + radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();

    centerX = 0.0;
    centerY = 0.7;
    radius = 0.1;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(red, green, blue); // Set color to yellow
    // Center vertex
    glVertex2f(centerX, centerY);
    // Vertices forming a circle
    for (int i = 0; i <= 360; i += 10) {
        float angle = i * 3.1415926f / 180.0f;
        float x = centerX + radius * cos(angle);
        float y = centerY + radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();

    centerX = 0.1;
    centerY = 0.7;
    radius = 0.1;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(red, green, blue); // Set color to yellow
    // Center vertex
    glVertex2f(centerX, centerY);
    // Vertices forming a circle
    for (int i = 0; i <= 360; i += 10) {
        float angle = i * 3.1415926f / 180.0f;
        float x = centerX + radius * cos(angle);
        float y = centerY + radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();

    centerX = 0.2;
    centerY = 0.7;
    radius = 0.1;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(red, green, blue); // Set color to yellow
    // Center vertex
    glVertex2f(centerX, centerY);
    // Vertices forming a circle
    for (int i = 0; i <= 360; i += 10) {
        float angle = i * 3.1415926f / 180.0f;
        float x = centerX + radius * cos(angle);
        float y = centerY + radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}

void drawCircledLake(float red, float green, float blue) {
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(red, green, blue); // Set color to yellow
    // Center vertex

    float centerX = -0.5;
    float centerY = -0.5;
    float radius = 0.3;

    glVertex2f(centerX, centerY);
    // Vertices forming a circle
    for (int i = 0; i <= 360; i += 10) {
        float angle = i * 3.1415926f / 180.0f;
        float x = centerX + radius * cos(angle);
        float y = centerY + radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();

    centerX = -0.2;
    centerY = -0.6;
    radius = 0.2;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(red, green, blue); // Set color to yellow
    // Center vertex
    glVertex2f(centerX, centerY);
    // Vertices forming a circle
    for (int i = 0; i <= 360; i += 10) {
        float angle = i * 3.1415926f / 180.0f;
        float x = centerX + radius * cos(angle);
        float y = centerY + radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();

    centerX = -0.2;
    centerY = -0.4;
    radius = 0.2;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(red, green, blue); // Set color to yellow
    // Center vertex
    glVertex2f(centerX, centerY);
    // Vertices forming a circle
    for (int i = 0; i <= 360; i += 10) {
        float angle = i * 3.1415926f / 180.0f;
        float x = centerX + radius * cos(angle);
        float y = centerY + radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();

    centerX = 0.0;
    centerY = -0.5;
    radius = 0.3;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(red, green, blue); // Set color to yellow
    // Center vertex
    glVertex2f(centerX, centerY);
    // Vertices forming a circle
    for (int i = 0; i <= 360; i += 10) {
        float angle = i * 3.1415926f / 180.0f;
        float x = centerX + radius * cos(angle);
        float y = centerY + radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();

    centerX = 0.3;
    centerY = -0.5;
    radius = 0.3;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(red, green, blue); // Set color to yellow
    // Center vertex
    glVertex2f(centerX, centerY);
    // Vertices forming a circle
    for (int i = 0; i <= 360; i += 10) {
        float angle = i * 3.1415926f / 180.0f;
        float x = centerX + radius * cos(angle);
        float y = centerY + radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}


