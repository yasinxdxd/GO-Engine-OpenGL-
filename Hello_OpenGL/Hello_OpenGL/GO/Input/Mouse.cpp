#include "Mouse.h"
#include <GLFW/glfw3.h>

namespace go
{

    Vec2d& Mouse::getPosition(void)
    {
        return m_position;
    }

    GObool Mouse::isMousePressed(go::Mouse::MouseButton button)
    {
        m_button = button;
        return is_mouse_pressed;
    }

    GObool Mouse::isMouseReleased(go::Mouse::MouseButton button)
    {
        m_button = button;
        return !is_mouse_pressed;
    }


    //callbacks:
    void Mouse::cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
    { }

    void Mouse::mouse_button_callback(GLFWwindow* window, GOint button, GOint action, GOint mods)
    {
        switch (m_button)
        {
        case Left:
            if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
                Mouse::is_mouse_pressed = true;
            else
                Mouse::is_mouse_pressed = false;
            break;
        case Right:
            if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
                Mouse::is_mouse_pressed = true;
            else
                Mouse::is_mouse_pressed = false;
            break;
        }
    }
}