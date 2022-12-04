# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 16:19:35 by isojo-go          #+#    #+#              #
#    Updated: 2022/12/04 18:13:23 by isojo-go         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile structure:

NAME		=	pipex
INC_DIR		=	inc/
SRC_DIR		=	src/
BONUS_DIR	=	bonus/
LIBFT_DIR	=	libft/libft.a
LIBFT		=	libft

# Source Files:

SRC_FILES	=	ft_pipex.c ft_pipex_utils.c
SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			= 	$(SRC:.c=.o)

# Bonus Source Files:

BONUS_FILES	=	ft_pipex_bonus.c ft_pipex_utils_bonus.c
SRC_B		=	$(addprefix $(BONUS_DIR), $(BONUS_FILES))
OBJ_B		= 	$(SRC_B:.c=.o)

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
			@$(CC) $(FLAGS) $(OBJ) $(LIBFT_DIR) -I$(INC_DIR) -o $(NAME)
			@echo "$(GREEN)pipex compiled!$(DEF_COLOR)"

bonus:		$(LIBFT) $(OBJ_B)
			@$(CC) $(FLAGS) $(OBJ_B) $(LIBFT_DIR) -I$(INC_DIR) -o $(NAME)
			@echo "$(GREEN)pipex (bonus) compiled!$(DEF_COLOR)"

$(LIBFT):
			@make -C ./libft

.c.o:
			@echo "$(BLUE)Compiling: $< $(DEF_COLOR)"
			@$(CC) $(FLAGS) -I$(INC_DIR) -c $< -o $(<:.c=.o)

clean:
			@$(RM) $(OBJ) $(OBJ_B)
			@echo "$(YELLOW)$(OBJ) file removed.$(DEF_COLOR)"
			@echo "$(YELLOW)$(OBJ_B) file removed.$(DEF_COLOR)"
			@make clean -C ./libft

fclean:		clean
			@make fclean -C ./libft
			@$(RM) $(NAME)
			@echo "$(RED)$(NAME) removed!$(DEF_COLOR)"

re:			fclean all

.PHONY:		all clean fclean re libft bonus