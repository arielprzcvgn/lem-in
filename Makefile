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

NAME	=	lem_in

SRC_DIR =	./sources
INC_DIR =	./includes
LIB_DIR	=	./libft

INC_NAME=	lem_in.h
SRC_NAME=	lem_in.c pathsfinder.c suurballe.c print_result.c \
			parsing.c parse_fill.c parse_tools.c li_free.c
LIB_NAME=	libft.a

INC		=	$(addprefix $(INC_DIR)/, $(INC_NAME))
SRC		=	$(addprefix $(SRC_DIR)/, $(SRC_NAME))
OBJ		=	$(SRC:.c=.o)
LIB		=	$(addprefix $(LIB_DIR)/, $(LIB_NAME))

CC		=	gcc
FLAGS	=	-g -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIB_DIR)
	@$(CC) $(FLAGS) $(OBJ) $(LIB) -o $(NAME)
	@echo "\033[1;32mLem_in is ready.\033[0m"

clean:
	@rm -f $(OBJ) $(LIB)
	$(MAKE) -C $(LIB_DIR) clean
	@echo "\033[1;31mObject files and libft has been deleted.\033[0m"

fclean: clean
	@rm -f $(NAME)
	$(MAKE) -C $(LIB_DIR) fclean
	@echo "\033[1;31mLem_in has been deleted.\033[0m"

re: fclean all

norme:
	@echo "\033[1;33mNorminette\033[0m"
	@norminette $(INC) $(SRC)
	$(MAKE) -C $(LIB_DIR) fclean