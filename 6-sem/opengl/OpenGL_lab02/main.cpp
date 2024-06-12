#include <GLFW/glfw3.h>
#include <cmath>
#include <iostream>
#include <chrono>

using namespace std::chrono;

void drawColorfulHouse();
void animateHouse(GLFWwindow* window);

auto lastIterationTime = high_resolution_clock::now();

int main(void)
{
    GLFWwindow* window;
    bool isNotStopped = true;

    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(900, 700, "A house in the circle", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwSetWindowAttrib(window, GLFW_RESIZABLE, GLFW_FALSE);
    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window) && isNotStopped) {

        animateHouse(window);

        glfwSwapBuffers(window);
        glfwPollEvents();

        isNotStopped = false;
    }

    glfwTerminate();
    return 0;
}

void drawColorfulHouse() {
    
    glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_QUADS);
    glVertex2f(-0.1, -0.1); // bottom-left
    glVertex2f(0.2, -0.1); // bottom-right
    glVertex2f(0.2, 0.2);  // top-right
    glVertex2f(-0.1, 0.2);    // top-left
    glEnd();

    glColor3f(0.2f, 1.0f, 0.3f);

    glBegin(GL_TRIANGLES);
    glVertex2f(0.05, 0.35); // top
    glVertex2f(-0.1, 0.2); // bottom-left
    glVertex2f(0.2, 0.2); // bottom-right
    glEnd();

    glColor3f(0.9f, 0.0f, 0.0f);

    glBegin(GL_QUADS);
    glVertex2f(0.0, -0.1);
    glVertex2f(0.1, -0.1);
    glVertex2f(0.1, 0.05);
    glVertex2f(0.0, 0.05);
    glEnd();
}

void animateHouse(GLFWwindow* window) {
    auto currentTime = high_resolution_clock::now();
    auto elapsedTime = duration_cast<duration<double>>(currentTime - lastIterationTime).count();

    if (elapsedTime >= 0.2) {
        lastIterationTime = currentTime;

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        float centerX = 0.0;
        float centerY = 0.0;
        float radius = 0.8;
        float scale = 0.1;

        for (int i = 0; i <= 360; i += 10) {

            float angle = i * 3.1415926f / 180.0f;
            float x = centerX + radius * cos(angle);
            float y = centerY + radius * sin(angle);
            float scale = 1;

            glPushMatrix();

            if (i < 180) {
                scale = 0.1f + 0.9f * (i / 180.0f);
            }
            else {
                scale = 1.0f - 0.9f * ((i - 180) / 180.0f);
            }

            glTranslatef(x, y, 0.0f);
            glScalef(scale, scale, 1.0);

            drawColorfulHouse();

            glPopMatrix();

            glfwSwapBuffers(window);
            glfwPollEvents();

            glfwWaitEventsTimeout(0.2);

            glClear(GL_COLOR_BUFFER_BIT);

        }
    }

}