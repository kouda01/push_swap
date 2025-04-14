NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./includes

SRCS_DIR = src
STACK_DIR = $(SRCS_DIR)/stack
OPERATIONS_DIR = $(SRCS_DIR)/operations
PARSING_DIR = $(SRCS_DIR)/parsing
SORT_DIR = $(SRCS_DIR)/sort
OBJ_DIR = obj

# Find all source files
SRC_FILES := \
	$(wildcard $(SRCS_DIR)/*.c) \
	$(wildcard $(STACK_DIR)/*.c) \
	$(wildcard $(OPERATIONS_DIR)/*.c) \
	$(wildcard $(PARSING_DIR)/*.c) \
	$(wildcard $(SORT_DIR)/*.c)

# Generate corresponding object file paths
OBJ_FILES := $(SRC_FILES:%.c=$(OBJ_DIR)/%.o)

# Create directory structure for object files
OBJ_DIRS := $(sort $(dir $(OBJ_FILES)))

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIRS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIRS):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re