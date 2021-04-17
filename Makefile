# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: wester <wester@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2021/04/13 18:07:51 by wester        #+#    #+#                  #
#    Updated: 2021/04/14 09:22:56 by wester        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = vector
NAME1 = list
NAME2 = map
# NAME3 = stack
# NAME3 = queu

RED = "\033[0;31m"
GREEN = "\033[0;32m"
YELLOW = "\033[0;33m"
BLUE = "\033[0;34m"
END = "\033[0m"

UTILS 	=	Traits RandomAccessIterator BiDirectionalIterator
CATCH 	=	catch main
MAP 	=	map mapnode pair
LIST	=	List Node
VECTOR	= 	Vector
# STACK	= 
# QUEU	=

CC 		= clang++
FLAGS 	= -Wall -Werror -Wextra --std=c++98
FLAGS2	= -Wall -Werror -Wextra --std=c++14

UTILS1  = $(UTILS:%=%.hpp)
CATCH1  = $(CATCH:%=%.cpp)
MAP1  = $(MAP:%=%.hpp)
LIST1  = $(LIST:%=%.hpp)
VECTOR1  = $(VECTOR:%=%.hpp)

UTILS2 = $(addprefix Additionals/,$(UTILS1))
CATCH2 = $(addprefix catch2/,$(CATCH1))
MAP2 = $(addprefix Containers/Map/,$(MAP1))
LIST2 = $(addprefix Containers/List/,$(LIST1))
VECTOR2 = $(addprefix Containers/Vector/,$(VECTOR1))

all:

vector: $(NAME)

$(NAME):
	@$(CC) $(FLAGS2) -o $(NAME) $(CATCH2) $(UTILS2) $(VECTOR2)
	@echo $(GREEN) COMPILED VECTOR $(END)

list: $(NAME1)

$(NAME1):
	@$(CC) $(FLAGS2) $(CATCH2) $(UTILS2) $(LIST2) catch2/list_catch.cpp
	@echo $(GREEN) COMPILED LIST $(END)

map: $(NAME2)

$(NAME2):
	@$(CC) $(FLAGS2) $(CATCH2) $(UTILS2) $(MAP2) catch2/map_catch.cpp
	@echo $(GREEN) COMPILED MAP $(END)

clean:
	@rm -f $(NAME)
	@rm -f $(NAME1)
	@rm -f $(NAME2)
	@echo $(YELLOW) CLEANED $(END)

fclean: clean

re: fclean all