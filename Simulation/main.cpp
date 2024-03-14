#include <iostream>
#include <GLFW/glfw3.h>
#include "circle.h"
#include "ball.h"

using namespace std;

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1000, 1000, "Simulation", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    
    Circle circle(0.0f, 0.0f, 0.5f, 0.05f);

    Ball ball(0.0f, 0.0f, 0.1f);

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        
		circle.Draw();
        
	
		ball.Tick(&circle);
	
		ball.Draw();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

