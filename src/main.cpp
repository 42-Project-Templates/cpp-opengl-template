#include "template.hpp"

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;

	GLFWwindow	*win = initWin();

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		handle_error(GLAD_INIT_ERR);

	while (!glfwWindowShouldClose(win))
	{
		glClearColor(0.2f, 0.2f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

		glfwPollEvents();
		glfwSwapBuffers(win);
	}
	return (0);
}
