#include "template.hpp"

void	key_callback(GLFWwindow *win, int key, int scancode, int action, int mods)
{
	(void)win;
	(void)key;
	(void)scancode;
	(void)action;
	(void)mods;

	if (glfwGetKey(win, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(win, GLFW_TRUE);
}

void	cursor_callback(GLFWwindow *win, double xPosIn, double yPosIn)
{
	(void)win;
	(void)xPosIn;
	(void)yPosIn;
}

void	scroll_callback(GLFWwindow *win, double xOffset, double yOffset)
{
	(void)win;
	(void)xOffset;
	(void)yOffset;
}

void	error_callback(int code, const char *description)
{
	(void)code;
	std::cerr << RED << description << RST << std::endl;
	glfwTerminate();
	exit(EXIT_FAILURE);
}

void	framebuffer_size_callback(GLFWwindow *win, int width, int height)
{
	(void)win;
	glViewport(0, 0, width, height);
}
