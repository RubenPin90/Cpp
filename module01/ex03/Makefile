# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/30 16:48:59 by rpinchas          #+#    #+#              #
#    Updated: 2024/05/30 23:42:32 by rpinchas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := unnecessary_violence

COMP := c++ -g
FLAGS := -Wall -Werror -Wextra -std=c++98

SRC := HumanA.cpp \
		HumanB.cpp \
		Weapon.cpp \
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
		echo -n "\r\t   ["; \
		for i in $$(seq 1 $(COMPILED_FILES)); do echo -n $(GREEN)"====="$(RESET); done; \
		for i in $$(seq $$(($(COMPILED_FILES) + 1)) $(TOTAL_FILES)); do echo -n $(GREEN)"====="$(RESET); done; \
		echo -n "] 100%"; fi
	@sleep 0.3
	@echo "\n\n" $(GREEN)"\t    Program is ready!\n" $(RESET)
	@rm -f .title_printed

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(COMP) $(FLAGS) -c $< -o $@
	@$(eval COMPILED_FILES=$(shell echo $$(($(COMPILED_FILES) + 1))))
	@if [ ! -f .title_printed ]; then \
		touch .title_printed; \
		echo $(BLUE)"\t+-+-+-+ +-+-+ +-+ +-+-+-+-+" $(RESET); \
		echo $(BLUE)"\t|C|+|+| |0|1| |/| |E|X|0|3|" $(RESET); \
		echo $(BLUE)"\t+-+-+-+ +-+-+ +-+ +-+-+-+-+" $(RESET); \
		echo ""; fi
	@echo -n "\r\t   ["
	@for i in $$(seq 1 $(COMPILED_FILES)); do echo -n $(GREEN)"====="$(RESET); done
	@for i in $$(seq $$(($(COMPILED_FILES) + 1)) $(TOTAL_FILES)); do echo -n "     "; done
	@echo -n "] $$(($(COMPILED_FILES) * 100 / $(TOTAL_FILES)))%"

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