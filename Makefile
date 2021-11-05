# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hamza <hamza@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/24 19:04:38 by hmellahi          #+#    #+#              #
#    Updated: 2021/11/05 01:21:54 by hamza            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CLANG = clang++

FLAGS = --std=c++11 #-Wall -Werror

NAME = a.out

SRC = tests/red_black_tree.cpp

all: $(NAME)

$(NAME): ${SRC}
	$(CLANG) $(FLAGS) -I src -I utils ${SRC} -o $(NAME)

san :
	$(CLANG) $(FLAGS) -I src -I utils  -fsanitize=address -g ${SRC} -o $(NAME)
clean:

fclean: clean
	rm -rf $(NAME)

re: fclean all
