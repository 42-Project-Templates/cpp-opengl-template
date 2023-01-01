#include "template.hpp"

GLFWwindow	*initWin(void)
{
	glfwSetErrorCallback(error_callback);
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

	GLFWwindow	*win = glfwCreateWindow(WIDTH, HEIGHT, "Window", NULL, NULL);
	glfwMakeContextCurrent(win);

	glfwSetFramebufferSizeCallback(win, framebuffer_size_callback);
	glfwSetKeyCallback(win, key_callback);
	glfwSetCursorPosCallback(win, cursor_callback);
	glfwSetScrollCallback(win, scroll_callback);

#ifdef __APPLE__
	glfwSetInputMode(win, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
#endif
	return (win);
}
