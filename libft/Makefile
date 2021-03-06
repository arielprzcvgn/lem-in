# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ariperez <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/14 10:42:18 by ariperez          #+#    #+#              #
#    Updated: 2019/04/02 19:44:35 by ariperez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re norme

NAME    =   libft.a

INC_DIR =   ./includes
SRC_DIR =   ./srcs/test
OBJ_DIR =   ./objs

MEM_D	=	memory
MEM_N	=	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
			ft_memchr.c ft_memcmp.c ft_memalloc.c ft_memdel.c

CHAR_D	=	char
CHAR_N	=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		   	ft_toupper.c ft_tolower.c

LST_D	=	list
LST_N	=	ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
			ft_lstmap.c

MATH_D	=	math
MATH_N	=	ft_sqrt.c ft_power.c ft_atoi.c ft_itoa.c ft_conv_base.c

PUT_D	=	put
PUT_N	=	ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c \
			ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_puttab.c

STR_D	=	string
STR_N	=	ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c \
			ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c \
			ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_strnew.c ft_strdel.c \
			ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
			ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c \
			ft_strsplit.c ft_strsplitcharset.c ft_strjoinfree.c

GNL_D	=	gnl
GNL_N	=	get_next_line.c

PRINT_D	=	ft_printf
PRINT_N	=	ft_printf.c printf_parsing.c printf_tools.c speci_d_i.c speci_o.c \
			speci_s.c speci_x.c speci_c.c speci_p.c speci_u.c speci_f.c

INC_NAME=   libft.h libftprintf.h
SRC_NAME=	$(MEM_N) $(CHAR_N) $(LST_N) $(MATH_N) $(PUT_N) $(STR_N) $(GNL_N) $(PRINT_N)
OBJ_NAME=   $(SRC_NAME:.c=.o)

INC     =   $(addprefix $(INC_DIR)/, $(INC_NAME))
SRC     =   $(addprefix $(SRC_DIR)/, $(SRC_NAME))
OBJ     =   $(addprefix $(OBJ_DIR)/, $(OBJ_NAME))


CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror


all:	$(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[1;32mYour library is ready.\033[0m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@echo "\033[1;31mLibft : object files has been deleted.\033[0m"

fclean:	clean
	@rm -f $(NAME)
	@echo "\033[1;31mYour library has been deleted.\033[0m"

re:		fclean all

norme:
	@echo "\033[1;33mNorminette Libft\033[0m"
	@norminette $(INC) $(SRC)
