#include "template.hpp"

void	handle_error(int error)
{
	std::cerr << RED;
	if (error == GLAD_INIT_ERR)
		std::cerr << "ERROR: Failed to initialize GLAD\n";
	std::cerr << RST;
	exit(EXIT_FAILURE);
}
