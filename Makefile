# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/23 14:57:27 by maria-j2          #+#    #+#              #
#    Updated: 2025/08/17 14:19:30 by maria-j2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the file
NAME = push_swap

# Compiler and compilation flags
CC = cc
CFLAGS = -Wall -Werror -Wextra -g

# Create library and delete files
AR = ar rcs
RM = rm -f

# Directory for source and object files
SRCS_DIR = .
OBJ_DIR = obj

# Source files and object files
SRC_FILES = \
    calculate_costs.c \
	ft_split.c \
    index_handling.c \
    main.c \
    movements.c \
    push.c \
    rev_rotate.c \
    rotate.c \
    sorting.c \
    stack_a_creation.c \
    stack_b_operations.c \
    swap.c \
    utils.c \
    verification_checks.c

# Add the source directory path to each source file
SRC = $(addprefix $(SRCS_DIR)/, $(SRC_FILES))

OBJS = $(SRC_FILES:%.c=$(OBJ_DIR)/%.o)

# Header file
INCLUDE = lib_push_swap.h

# Rule to create the executable
$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# Create object directory
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Compile .c files to .o files
$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c $(INCLUDE)
	$(CC) $(CFLAGS) -c -o $@ $<

# Indicates that everything to the rignt are commands and not files
.PHONY: all clean fclean re

# Default rule that compiles everything
# target: dependencies
# commands
all: $(NAME)

# Rule to delete all created object files
clean:
	$(RM) -r $(OBJ_DIR)

# Delete all .o and .a files
fclean: clean
	$(RM) $(NAME)

re: fclean all
	clear
	