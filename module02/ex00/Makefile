# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/30 16:48:59 by rpinchas          #+#    #+#              #
#    Updated: 2024/06/05 18:48:39 by rpinchas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := First_Orthodox_Class

COMP := c++ -g
FLAGS := -Wall -Werror -Wextra -std=c++98 -pedantic

SRC :=	Fixed.cpp \
		main.cpp
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

TOTAL_FILES := $(words $(SRC))
COMPILED_FILES := 0

all: $(NAME)


$(NAME): $(OBJ) 
	@$(COMP) $(FLAGS) $^ -o $@
	@if [ $(COMPILED_FILES) -ne $(TOTAL_FILES) ]; then \
		echo -n "\r\t      ["; \
		for i in $$(seq 1 $(COMPILED_FILES)); do echo -n $(GREEN)"===="$(RESET); done; \
		for i in $$(seq $$(($(COMPILED_FILES) + 1)) $(TOTAL_FILES)); do echo -n $(GREEN)"===="$(RESET); done; \
		echo -n "] 100%"; fi
	@sleep 0.3
	@echo "\n\n" $(GREEN)"\t    Program is ready!\n" $(RESET)

$(OBJ_DIR)/%.o: %.cpp msg
	@mkdir -p $(dir $@)
	@$(COMP) $(FLAGS) -c $< -o $@
	@$(eval COMPILED_FILES=$(shell echo $$(($(COMPILED_FILES) + 1))))
	@echo -n "\r\t      ["
	@for i in $$(seq 1 $(COMPILED_FILES)); do echo -n $(GREEN)"===="$(RESET); done
	@for i in $$(seq $$(($(COMPILED_FILES) + 1)) $(TOTAL_FILES)); do echo -n "     "; done
	@echo -n "] $$(($(COMPILED_FILES) * 100 / $(TOTAL_FILES)))%"

.INTERMEDIATE: msg
msg: 
	@echo $(BLUE)"\t+-+-+-+ +-+-+ +-+ +-+-+-+-+" $(RESET);
	@echo $(BLUE)"\t|C|+|+| |0|2| |/| |E|X|0|0|" $(RESET);
	@echo $(BLUE)"\t+-+-+-+ +-+-+ +-+ +-+-+-+-+\n" $(RESET);

clean:
	@rm -rf $(OBJ_DIR)
	@echo $(GRAY)$(CURSIVE)$(XXX)"Object files and Output file successfully removed!" $(RESET)
	@echo $(YELLOW)"> Clean" $(RESET)

fclean: clean
	@rm -rf $(NAME)
	@echo $(GRAY)$(CURSIVE)$(XXX)"Executables successfully removed!" $(RESET)
	@echo $(YELLOW)"> All clean" $(RESET)

re: fclean all

.PHONY:	all clean fclean re