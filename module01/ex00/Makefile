# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/30 08:56:37 by rpinchas          #+#    #+#              #
#    Updated: 2024/06/02 23:47:10 by rpinchas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME := Zombie

COMP := c++ -g
FLAGS := -Wall -Werror -Wextra -std=c++98 -pedantic

SRC := Zombie.cpp \
		newZombie.cpp \
		randomChump.cpp \
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
	@echo " -->" $(GREEN)"Program is ready!" $(RESET)
	@sleep 1
	@echo "\n"
	@echo $(BLUE)"       ::::::::                                   :::::::    :::                :::          :::::::::: :::    :::  :::::::   :::::::" $(RESET)
	@echo $(BLUE)"     :+:    :+:     :+:           :+:           :+:   :+: :+:+:               :+:           :+:        :+:    :+: :+:   :+: :+:   :+:" $(RESET)
	@echo $(BLUE)"    +:+            +:+           +:+           +:+   +:+   +:+              +:+            +:+         +:+  +:+  +:+   +:+ +:+   +:+" $(RESET)
	@echo $(BLUE)"   +#+       +#++:++#++:++ +#++:++#++:++      +#+   +:+   +#+             +#+             +#++:++#     +#++:+   +#+   +:+ +#+   +:+" $(RESET)  
	@echo $(BLUE)"  +#+            +#+           +#+           +#+   +#+   +#+            +#+              +#+         +#+  +#+  +#+   +#+ +#+   +#+" $(RESET)  
	@echo $(BLUE)" #+#    #+#     #+#           #+#           #+#   #+#   #+#           #+#               #+#        #+#    #+# #+#   #+# #+#   #+#" $(RESET)   
	@echo $(BLUE)"  #######                                   #######  #######        ###                ########## ###    ###  #######   #######" $(RESET)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(COMP) $(FLAGS) -c $< -o $@
	@$(eval COMPILED_FILES=$(shell echo $$(($(COMPILED_FILES) + 1))))
	@echo -n "\rCompiling: ["
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