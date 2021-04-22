# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: wester <wester@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2021/04/13 18:07:51 by wester        #+#    #+#                  #
#    Updated: 2021/04/22 16:46:30 by wester        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = vector
NAME1 = list
NAME2 = map
NAME3 = stack
NAME4 = queue
NAME5 = testall
NAME6 = all

RED = "\033[0;31m"
GREEN = "\033[0;32m"
YELLOW = "\033[0;33m"
BLUE = "\033[0;34m"
END = "\033[0m"

UTILS 	=	Traits RandomAccessIterator BiDirectionalIterator
CATCH 	=	catch main vector_catch list_catch map_catch stack_catch queue_catch
CATCHO 	=	catch.o main.o
MAP 	=	map mapnode pair
LIST	=	List Node
VECTOR	= 	Vector
STACK	= 	Stack
QUEUE	=	Queue

CC 		= clang++
FLAGS 	= -Wall -Werror -Wextra --std=c++98
FLAGS2	= -Wall -Werror -Wextra --std=c++14

UTILS1  = $(UTILS:%=%.hpp)
CATCH1  = $(CATCH:%=%.cpp)
CATCHOO  = $(CATCH:%=%.o)
MAP1  = $(MAP:%=%.hpp)
LIST1  = $(LIST:%=%.hpp)
VECTOR1  = $(VECTOR:%=%.hpp)
STACK1  = $(STACK:%=%.hpp)
QUEUE1  = $(QUEUE:%=%.hpp)

UTILS2 = $(addprefix Additionals/,$(UTILS1))
CATCH2 = $(addprefix catch2/,$(CATCH1))
MAP2 = $(addprefix Containers/Map/,$(MAP1))
LIST2 = $(addprefix Containers/List/,$(LIST1))
VECTOR2 = $(addprefix Containers/Vector/,$(VECTOR1))
STACK2 = $(addprefix Containers/Stack/,$(STACK1))
QUEUE2 = $(addprefix Containers/Queue/,$(QUEUE1))

all:$(NAME6)

$(NAME6):
	$(CC) $(FLAGS2) $(CATCH2) -o $(NAME6)
	
runall: alltest $(NAME5)
	@./$(NAME5)

$(NAME5):
	@$(CC) $(FLAGS2) $(CATCHOO) -o $(NAME5)

alltest: catch vector list map stack queue

vector: catch $(NAME)

$(NAME):
	@$(CC) $(FLAGS2) $(CATCH2) vector_catch.o -o $(NAME)
	@echo $(GREEN) COMPILED VECTOR $(END)

catch: $(CATCHO)

$(CATCHO):
	@$(CC) $(FLAGS2) $(CATCH2) -c
	@echo $(GREEN) COMPILED CATCH2 $(END)

list: catch $(NAME1)

$(NAME1):
	@$(CC) $(FLAGS2) $(CATCHO) list_catch.o -o $(NAME1)
	@echo $(GREEN) COMPILED LIST $(END)

map: catch $(NAME2)

$(NAME2):
	@$(CC) $(FLAGS2) $(CATCHO) map_catch.o -o $(NAME2) 
	@echo $(GREEN) COMPILED MAP $(END)

stack: catch $(NAME3)

$(NAME3):
	@$(CC) $(FLAGS2) $(CATCHO) stack_catch.o -o $(NAME3)
	@echo $(GREEN) COMPILED STACK $(END)
	
queue: catch $(NAME4)

$(NAME4):
	@$(CC) $(FLAGS2) $(CATCHO) queue_catch.o -o $(NAME4)
	@echo $(GREEN) COMPILED QUEUE $(END)

robijn:
	@$(CC) $(FLAGS2) $(CATCH2) $(UTILS2) $(LIST2) tests/iterator_test.cpp
	
tim:
	@$(CC) $(FLAGS2) $(CATCH2) $(UTILS2) $(LIST2) TEST/stack_test.cpp
	
clean:
	@rm -f $(CATCHOO) catch
	@echo $(YELLOW) CLEANED $(END)
	

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME1)
	@rm -f $(NAME2)
	@rm -f $(NAME3)
	@rm -f $(NAME4)
	@rm -f $(NAME5)
	@rm -f $(NAME6)

re: fclean all
