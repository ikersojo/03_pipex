# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/09 15:28:36 by isojo-go          #+#    #+#              #
#    Updated: 2022/11/22 22:27:05 by isojo-go         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Key variable and files definitions:

NAME		=	libft.a
INCLUDES	=	inc/
SRC_DIR		=	src/
CC			=	gcc
CCFLAGS		=	-Wall -Wextra -Werror
AR			=	ar rc
RM			=	rm -f


# Source Files:

SRC_FILES	=	ft_is/ft_isalnum.c ft_is/ft_isalpha.c ft_is/ft_isascii.c \
				ft_is/ft_isdigit.c ft_is/ft_isprint.c ft_is/ft_isspace.c \
				ft_is/ft_ischarset.c ft_is/ft_isline.c ft_is/ft_isint.c \
				ft_is/ft_is_samesign.c \
				ft_lst/ft_lstnew.c ft_lst/ft_lstadd_front.c \
				ft_lst/ft_lstsize.c ft_lst/ft_lstlast.c \
				ft_lst/ft_lstadd_back.c ft_lst/ft_lstdelone.c \
				ft_lst/ft_lstclear.c ft_lst/ft_lstiter.c \
				ft_lst/ft_lstmap.c \
				ft_mem/ft_bzero.c ft_mem/ft_calloc.c ft_mem/ft_memccpy.c \
				ft_mem/ft_memchr.c ft_mem/ft_memcmp.c ft_mem/ft_memcpy.c \
				ft_mem/ft_memmove.c ft_mem/ft_memset.c \
				ft_put/ft_putchar_fd.c ft_put/ft_putunbr_fd.c \
				ft_put/ft_putnbr_fd.c ft_put/ft_putstr_fd.c \
				ft_put/ft_putuhexnbr_fd.c \
				ft_str/ft_split.c ft_str/ft_strchr.c ft_str/ft_strdup.c \
				ft_str/ft_striteri.c ft_str/ft_strjoin.c ft_str/ft_strlcat.c \
				ft_str/ft_strlcpy.c ft_str/ft_strlen.c ft_str/ft_strmapi.c \
				ft_str/ft_strncmp.c ft_str/ft_strnstr.c ft_str/ft_strrchr.c \
				ft_str/ft_strtrim.c ft_str/ft_substr.c ft_str/ft_strcat.c \
				ft_str/ft_strcmp.c \
				ft_to/ft_abs.c ft_to/ft_atoi.c ft_to/ft_itoa.c ft_to/ft_max.c \
				ft_to/ft_toupper.c ft_to/ft_tolower.c ft_to/ft_digitcount.c\
				ft_printf/ft_printf.c \
				ft_gnl/ft_gnl.c \
				ft_intlst/ft_args_to_intlst.c ft_intlst/ft_intlst_addback.c \
				ft_intlst/ft_intlst_free.c ft_intlst/ft_intlst_last.c \
				ft_intlst/ft_intlst_new.c ft_intlst/ft_intlst_print.c \
				ft_intlst/ft_intlst_before_last.c \
				ft_intlst/ft_intlst_issorted.c ft_intlst/ft_intlst_minval.c\
				ft_intlst/ft_intlst_maxval.c ft_intlst/ft_intlst_size.c \
				ft_intlst/ft_intlst_isrevsorted.c

SRC	=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ	=	$(SRC:.c=.o)


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

$(NAME):	$(OBJ)
			@$(AR) $(NAME) $(OBJ)
			@echo "$(GREEN)extended libft compiled!$(DEF_COLOR)"
			@echo "$(CYAN)             w                  8          8    8 w 8     d8b  w   "
			@echo ".d88b Yb dP w8ww .d88b 8d8b. .d88 .d88b .d88    8 w 88b.  8'  w8ww "
			@echo "8.dP'  \`8.   8   8.dP' 8P Y8 8  8 8.dP' 8  8    8 8 8  8 w8ww  8   "
			@echo "\`Y88P dP Yb  Y8P \`Y88P 8   8 \`Y88 \`Y88P \`Y88    8 8 88P'  8    Y8P "
			@echo "                                                               $(DEF_COLOR)"

.c.o:
			@echo "$(BLUE)Compiling: $< $(DEF_COLOR)"
			@$(CC) $(CCFLAGS) -I$(INCLUDES) -c $< -o $(<:.c=.o)

clean:
			@$(RM) $(OBJ)
			@echo "$(YELLOW)Object files removed.$(DEF_COLOR)"

fclean:		clean
			@$(RM) $(NAME)
			@echo "$(RED)$(NAME) removed!$(DEF_COLOR)"

re:			fclean all

.PHONY:		all clean fclean re