#include "GLFW/glfw3.h"
#include <bits/stdc++.h>


std::vector<Snow> vec;

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (action != GLFW_RELEASE) return;
    if (key == GLFW_KEY_D)
    {
        // finish create one shape

    }
}

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
    {
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);

    }
}

int main()
{
    srand(time(0));
    // 初始化 GLFW
    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // 创建一个窗口
    GLFWwindow* window = glfwCreateWindow(800, 600, "Snow simulation", nullptr, nullptr);
    if (!window)
    {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    // 设置上下文
    glfwMakeContextCurrent(window);

    // 设置键盘和鼠标回调
    glfwSetKeyCallback(window, keyCallback);
    glfwSetMouseButtonCallback(window, mouseButtonCallback);

    // 主循环
    while (!glfwWindowShouldClose(window))
    {
        // 清除屏幕
        glClear(GL_COLOR_BUFFER_BIT);

        // 在这里添加绘制代码...

        // 交换前后缓冲区
        glfwSwapBuffers(window);

        // 处理事件
        glfwPollEvents();
    }

    // 终止 GLFW
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
