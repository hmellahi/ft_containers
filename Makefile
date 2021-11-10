# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hamza <hamza@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/24 19:04:38 by hmellahi          #+#    #+#              #
#    Updated: 2021/11/10 04:26:05 by hamza            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CLANG = clang++

FLAGS = --std=c++98 -Wall -Werror -Werror

NAME = a.out

SRC = tests/main.cpp
# SRC = main2.cpp

all: $(NAME)

$(NAME): ft
	
ft: ${SRC}
	$(CLANG) $(FLAGS) -I src -I utils -D NS ${SRC} -o $(NAME)

std :
	$(CLANG) $(FLAGS) -I src -I utils ${SRC} -o $(NAME)

clean:

fclean: clean
	rm -rf $(NAME)

re: fclean all
