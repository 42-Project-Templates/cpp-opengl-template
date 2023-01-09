#pragma once

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "colors.h"
#include "Shader.hpp"

#define WIDTH 800
#define HEIGHT 600

enum e_err
{
	GLAD_INIT_ERR
};

/* window_handling.cpp */
GLFWwindow	*initWin(void);

/* events_handling.cpp */
void	key_callback(GLFWwindow *win, int key, int scancode, int action, int mods);
void	cursor_callback(GLFWwindow *win, double xPosIn, double yPosIn);
void	scroll_callback(GLFWwindow *win, double xOffset, double yOffset);
void	error_callback(int code, const char *description);
void	framebuffer_size_callback(GLFWwindow *win, int width, int height);

/* error_handling.cpp */
void	handle_error(int error);

/* load_textures.cpp */
GLuint	loadTexture(std::string path);
