# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/30 12:37:50 by rpinchas          #+#    #+#              #
#    Updated: 2024/04/30 16:58:58 by rpinchas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := megaphone

COMP := c++ -g
FLAGS := -Wall -Werror -Wextra -std=c++98

SRC := megaphone.cpp
OBJ_DIR := ./obj
OBJ := $(SRC:%.cpp=$(OBJ_DIR)/%.o)

# colors
GREEN		='\033[32m'
YELLOW		='\033[33m'
BLUE		='\033[34m'
GRAY		='\033[237m'
XXX			='\033[2m'
CURSIVE		='\033[3m'
RESET		='\033[0m'

all: $(NAME)

$(NAME): $(OBJ) 
		$(COMP) $(FLAGS) $< -o $@
		@echo $(GREEN)"Program is ready" $(RESET)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(COMP) $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo $(GRAY)$(CURSIVE)$(XXX)"Object files successfully removed!" $(RESET)
	@echo $(YELLOW)"> Clean" $(RESET)

fclean: clean
	@rm -rf $(NAME)
	@echo $(GRAY)$(CURSIVE)$(XXX)"Executables successfully removed!" $(RESET)
	@echo $(YELLOW)"> All clean" $(RESET)

re: fclean all

.PHONY:	all clean fclean re