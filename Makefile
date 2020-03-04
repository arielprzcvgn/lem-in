# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ariperez <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/13 14:43:48 by ariperez          #+#    #+#              #
#    Updated: 2020/01/06 19:17:46 by ariperez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re main norme

NAME	=	lem-in

SRC_DIR =	./srcs
LIB_DIR	=	./libft

INC_NAME=	lem-in.h libftprintf.h get_next_line.h
NAME_SRC=	lem-in.c init.c visu.c li_free.c
NAME_LIB=	ft_atoi.c ft_memcpy.c ft_putchar.c ft_strcmp.c ft_strnew.c speci_c.c speci_s.c\
			ft_bzero.c ft_memmove.c ft_putstr.c ft_strcpy.c ft_strsplit.c speci_d_i.c speci_u.c\
			ft_conv_base.c ft_memset.c ft_putstr_fd.c ft_strdup.c get_next_line.c speci_f.c speci_x.c\
			ft_itoa.c ft_power.c ft_strcat.c ft_strjoinfree.c pfparsing.c speci_o.c\
			ft_memalloc.c ft_printf.c ft_strclr.c ft_strlen.c pftools.c speci_p.c ft_strchr.c

SRC		=	$(addprefix $(SRC_DIR)/, $(NAME_SRC))
LIB		=	$(addprefix $(LIB_DIR)/, $(NAME_LIB))
OBJ		=	$(SRC:.c=.o)
OBJ_LIB	=	$(LIB:.c=.o)

CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ_LIB) $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) $(OBJ_LIB) -o $(NAME)
	@echo "\033[1;32mLem-in is ready.\033[0m"

clean:
	@rm -f $(OBJ) $(OBJ_LIB)
	@echo "\033[1;31mObject files has been deleted.\033[0m"

fclean: clean
	@rm -f $(NAME)
	@rm -f debug
	@echo "\033[1;31mLem-in has been deleted.\033[0m"

re: fclean all

norme:
	@echo "\033[1;33mNorminette\033[0m"
	@norminette $(INC) $(SRC) $(LIB)

debug:
	@$(CC) -g $(FLAGS) $(SRC) $(LIB) -o debug
	@echo "\033[1;32mLem-in debug is ready.\033[0m"
