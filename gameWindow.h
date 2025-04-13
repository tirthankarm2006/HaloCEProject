#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include<glm.hpp>
#include<iostream>

void framebuffer_size_callback_game(GLFWwindow* window, int width, int height);

class createGameWindow {
public:
    unsigned int width;
    unsigned int height;
    GLFWwindow* window;
    const char* windowName;
    glm::vec4 bgColor;

    createGameWindow(unsigned int width, unsigned int height, const char* windowName) {
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        this->width = width;
        this->height = height;
        this->windowName = windowName;
    }

    void startWindowLoop(GLFWwindow* window) {
        while (!glfwWindowShouldClose(window))
        {
            processInput(window);

            glClearColor(bgColor.x, bgColor.y, bgColor.z, bgColor.w);
            glClear(GL_COLOR_BUFFER_BIT);

            glfwSwapBuffers(window);
            glfwPollEvents();
        }
    }

    void generateWindow() {
        GLFWwindow* window = glfwCreateWindow(width, height, windowName, NULL, NULL);
        this->window = window;
        if (window == NULL)
        {
            std::cout << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
        }
    }

    void makeWindowContext() {
        glfwMakeContextCurrent(window);
    }

    void setFrameBufferSizeCallbackWindow() {
        glfwSetFramebufferSizeCallback(window, framebuffer_size_callback_game);
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cout << "Failed to initialize GLAD" << std::endl;
        }
    }

    void setBgColor(glm::vec4 color) {
        bgColor = color;
    }

private:
    void processInput(GLFWwindow* window)
    {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, true);
        }
    }
};

void framebuffer_size_callback_game(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}



