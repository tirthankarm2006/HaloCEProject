#include <main2.hpp>
#include <iostream>
#include "settingsWindow.h"
#include "gameWindow.h"

createSettingsWindow window1(800, 600, "GameSettings");

int main()
{
    window1.generateWindow();
    window1.makeWindowContext();
    window1.setFrameBufferSizeCallbackWindow();
    window1.setBgColor(glm::vec4(0.5, 0.1, 1.0, 0.2));
    window1.startWindowLoop(window1.window);
    glfwTerminate();

    if (window1.createGameWindowOrNot) {
        createGameWindow gameWindow(1280, 720, "Game");
        gameWindow.generateWindow();
        gameWindow.makeWindowContext();
        gameWindow.setFrameBufferSizeCallbackWindow();
        gameWindow.setBgColor(glm::vec4(0.5, 0.7, 0.9, 0.2));
        gameWindow.startWindowLoop(gameWindow.window);
    }

    glfwTerminate();
    return 0;
}
