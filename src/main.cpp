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

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	
	GLFWwindow	*win = initWin();

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		exit(EXIT_FAILURE);

	while (!glfwWindowShouldClose(win))
	{
		glClearColor(0.2f, 0.2f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

		glfwPollEvents();
		glfwSwapBuffers(win);
	}
	return (0);
}
