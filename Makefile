# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 16:19:35 by isojo-go          #+#    #+#              #
#    Updated: 2022/11/23 22:26:23 by isojo-go         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile structure:

NAME		=	pipex
INC_DIR		=	inc/
SRC_DIR		=	src/
LIBFT		=	libft/libft.a

# Source Files:

SRC_FILES	=	ft_pipex.c ft_pipex_utils.c
SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			= 	$(SRC:.c=.o)

# Compilation flags:

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

#Colors:

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;31m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

# **************************************************************************** #

all:		$(NAME)

$(NAME):	$(LIBFT) $(OBJ)
			@$(CC) $(FLAGS) $(OBJ) $(LIBFT) -I$(INC_DIR) -o $(NAME)
			@echo "$(GREEN)pipex compiled!$(DEF_COLOR)"

$(LIBFT):
			@make -C ./libft

.c.o:
			@echo "$(BLUE)Compiling: $< $(DEF_COLOR)"
			@$(CC) $(FLAGS) -I$(INC_DIR) -c $< -o $(<:.c=.o)

clean:
			@$(RM) $(OBJ)
			@echo "$(YELLOW)$(OBJ) file removed.$(DEF_COLOR)"
			@make clean -C ./libft

fclean:		clean
			@make fclean -C ./libft
			@$(RM) $(NAME)
			@echo "$(RED)$(NAME) removed!$(DEF_COLOR)"

re:			fclean all

.PHONY:		all clean fclean re libft