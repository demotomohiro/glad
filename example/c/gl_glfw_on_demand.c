// This example requires you to generate glad with the --on-demand option and optionally --loader.
// gcc -o gl_glfw_on_demand example/c/gl_glfw_on_demand.c build/src/gl.c -Ibuild/include -ldl -lglfw
#include <stdlib.h>
#include <stdio.h>

#include <glad/gl.h>

#include <GLFW/glfw3.h>


const GLuint WIDTH = 800, HEIGHT = 600;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

int main(void) {
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "[glad] GL with GLFW", NULL, NULL);
    glfwMakeContextCurrent(window);

    glfwSetKeyCallback(window, key_callback);

    // If glad is generated with the --loader and --on-demand option
    // you don't have to call any glad function.
    // It is recommended to use the loader provided by your context creation library
    // instead of the glad loader.
#ifndef GLAD_GL_LOADER
    gladSetGLOnDemandLoader(glfwGetProcAddress);
#endif

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        glClearColor(0.7f, 0.9f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
    }

    glfwTerminate();

    return 0;
}
