NAME := template

OS := $(shell uname)
ifeq ($(OS), Linux)
	LDFLAGS := -Llibs/glfw/build/src
	LDLIBS := -lglfw3 -lm -lX11 -lpthread -lXrandr -lXi -ldl
else
	LDFLAGS := -Llibs/glfw/lib-universal
	LDLIBS := -lglfw3 -lm -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo
endif

INCS := include libs/glad/include libs/glfw/include libs/glm

SRC_DIR := src
CSRC_DIR := libs/glad/src
BUILD_DIR := .build

SRCS := main.cpp \
		window_handling.cpp \
		events_handling.cpp \
		error_handling.cpp

CSRCS := glad.c

OBJS := $(SRCS:%.cpp=$(BUILD_DIR)/%.o)
OBJS += $(CSRCS:%.c=$(BUILD_DIR)/%.o)

DEPS := $(OBJS:.o=.d)

CC := gcc
CFLAGS := -Wall -Werror -Wextra -std=c99

CXX := c++
CXXFLAGS := -Wall -Werror -Wextra -std=c++11
CPPFLAGS := $(addprefix -I, $(INCS)) -MMD -MP

RM := rm -rf

all: $(NAME)

debug: CXXFLAGS += -g -DDEBUG
debug: all

memory: CXXFLAGS += -fsanitize=memory -fsanitize-memory-track-origins=2 -fPIE -pie -fno-omit-frame-pointer -g
memory: re

address: CXXFLAGS += -fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all -fsanitize=float-divide-by-zero -fsanitize=float-cast-overflow -fno-sanitize=null -fno-sanitize=alignment -g
address: re

print-%: ; @echo $* = $($*)

$(NAME): $(BUILD_DIR) $(OBJS)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS) $(LDLIBS)

$(BUILD_DIR):
	@test -d $@ || mkdir -p $@

$(BUILD_DIR)/%.o: $(CSRC_DIR)/%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

download_libs:
ifeq ($(OS), Linux)
	curl -L https://github.com/glfw/glfw/releases/download/3.3.8/glfw-3.3.8.zip -o libs/glfw.zip
	unzip libs/glfw.zip -d libs/glfw
	mv libs/glfw/*/* libs/glfw
	cmake -S libs/glfw -B libs/glfw/build
	make -C libs/glfw/build
else
	curl -L https://github.com/glfw/glfw/releases/download/3.3.8/glfw-3.3.8.bin.MACOS.zip -o libs/glfw.zip
	unzip libs/glfw.zip -d libs/glfw
	mv libs/glfw/*/* libs/glfw
endif

	curl -L https://github.com/g-truc/glm/releases/download/0.9.9.8/glm-0.9.9.8.zip -o libs/glm.zip

	unzip libs/glad.zip -d libs/glad
	unzip libs/glm.zip -d libs

delete_libs:
	$(RM) libs/glfw* libs/glm* libs/glad

clean:
	$(RM) $(BUILD_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re debug memory address thread
