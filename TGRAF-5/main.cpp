#include <GLFW/glfw3.h>

//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//    glViewport(0, 0, width, height);
//}

int main(void)
{
    GLFWwindow* window;

    uint16_t width=800, height=600;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Tell OpenGL the size of the rendering window */
    glViewport(0, 0, width, height);
    /* Change the viewport size if the window is resized by the user */
    //glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glViewport(0, 0, width, height);
        glOrtho(0, width, 0, height, -1, 1);

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

        glColor3f(0.0f, 0.0f, 1.0f); //blue color
        glBegin(GL_TRIANGLES);
        glVertex2i(100, 100);
        glVertex2i(200, 100);
        glVertex2i(100, 200);
        glEnd();



        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}