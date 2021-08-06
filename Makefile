# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmellahi <hmellahi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/24 19:04:38 by hmellahi          #+#    #+#              #
#    Updated: 2021/07/09 21:50:59 by hmellahi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CLANG = clang++

FLAGS = --std=c++11 -Wall -Werror

NAME = a.out

SRC = red_black_tree.cpp

all: $(NAME)

$(NAME): ${SRC}
	$(CLANG) $(FLAGS) ${SRC} -o $(NAME)

san :
	$(CLANG) $(FLAGS) ${SRC} -fsanitize=address -g -o $(NAME)
clean:

fclean: clean
	rm -rf $(NAME)

re: fclean all
