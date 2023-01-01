NAME := template

LDFLAGS :=
LDLIBS :=

INCS := include

SRC_DIR := src
BUILD_DIR := .build

SRCS := main.cpp

OBJS := $(SRCS:%.cpp=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

CXX := c++
CXXFLAGS := -Wall -Werror -Wextra
CPPFLAGS := $(addprefix -I, $(INCS)) -MMD -MP

RM := rm -rf

all: $(NAME)

debug: CXXFLAGS += -g -DDEBUG
debug: all

memory: CXXFLAGS += -fsanitize=memory -fsanitize-memory-track-origins=2 -fPIE -pie -fno-omit-frame-pointer -g
memory: re

address: CXXFLAGS += -fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all -fsanitize=float-divide-by-zero -fsanitize=float-cast-overflow -fno-sanitize=null -fno-sanitize=alignment -g
address: re

$(NAME): $(BUILD_DIR) $(OBJS)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS) $(LDLIBS)

$(BUILD_DIR):
	@test -d $@ || mkdir -p $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(BUILD_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re debug memory address thread
