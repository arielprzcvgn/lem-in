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
OBJ_DIR	=	./objects

INC_NAME=	lem_in.h
SRC_NAME=	lem_in.c pathsfinder.c suurballe.c print_result.c \
			parsing.c parse_fill.c parse_tools.c li_free.c
LIB_NAME=	libft.a
OBJ_NAME=	$(SRC_NAME:.c=.o)

INC		=	$(addprefix $(INC_DIR)/, $(INC_NAME))
SRC		=	$(addprefix $(SRC_DIR)/, $(SRC_NAME))
OBJ		=	$(addprefix $(OBJ_DIR)/, $(OBJ_NAME))
LIB		=	$(addprefix $(LIB_DIR)/, $(LIB_NAME))

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
DEBUG	=	-g

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIB_DIR)
	$(CC) $(DEBUG) $(FLAGS) $(OBJ) $(LIB) -o $(NAME)
	@echo "\033[1;32mLem_in is ready.\033[0m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(DEBUG) $(CFLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJ) $(LIB)
	@$(MAKE) -C $(LIB_DIR) clean
	@echo "\033[1;31mObject files and libft has been deleted.\033[0m"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIB_DIR) fclean
	@echo "\033[1;31mLem_in has been deleted.\033[0m"

re: fclean all

norme:
	#@$(MAKE) -C $(LIB_DIR) norme
	@echo "\033[1;33mNorminette Lem_in\033[0m"
	@norminette $(INC) $(SRC)