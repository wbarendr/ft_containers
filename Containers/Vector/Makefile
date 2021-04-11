# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: wester <wester@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2021/01/27 15:44:17 by wester        #+#    #+#                  #
#    Updated: 2021/02/01 16:40:58 by wester        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

RD = "\x1b[31;01"
GR = "\x1b[32;01m"
YL = "\x1b[33;01m"
NO = "\x1b[0m"

NAME = vector

CLANG = clang++

FLAGS = -Wall -Werror -Wextra -pedantic -std=c++98

SRCS = vector.cpp

all: $(NAME)

$(NAME):
		@$(CLANG) $(FLAGS) -o $(NAME) $(SRCS)
		@echo $(GR) "generated executable" $(NO)

clean:

fclean: clean
		@rm -f $(NAME)

re: fclean all

test: re
	@./vector > myoutput.txt
	@-diff output.txt myoutput.txt ; [ $$? -eq 1 ]
