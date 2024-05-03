# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/27 21:33:35 by rpinchas          #+#    #+#              #
#    Updated: 2023/12/27 21:33:36 by rpinchas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook
CC = c++ -g
FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = phonebook.cpp
OBJ_F = obj/
OBJ = $(addprefix $(OBJ_F), $(SRC:%.cpp=%.o))

# colors
GREEN		='\033[32m'
YELLOW		='\033[33m'
BLUE		='\033[34m'
GRAY		='\033[237m'
XXX			='\033[2m'
CURSIVE		='\033[3m'
RESET		='\033[0m'

all: $(NAME)

$(NAME): $(OBJ_F) $(OBJ)
	@$(CC) $(FLAGS) -o $@ $(OBJ)
	@echo $(GREEN)"Program is ready" $(RESET)

$(OBJ_F)%.o: %.cpp
	@$(CC) $(FLAGS) -c -o $@ $<

$(OBJ_F):
	@mkdir -p $@

clean:
	@rm -rf $(OBJ_F)
	@echo $(GRAY)$(CURSIVE)$(XXX)"Object files successfully removed!" $(RESET)
	@echo $(YELLOW)"> Clean" $(RESET)

fclean: clean
	@rm -rf $(NAME)
	@echo $(GRAY)$(CURSIVE)$(XXX)"Executables successfully removed!" $(RESET)
	@echo $(YELLOW)"> All clean" $(RESET)

re: fclean all

.PHONY:	all clean fclean re
