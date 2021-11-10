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

FLAGS = --std=c++98 -Wall -Werror -Werror #-D NS

NAME = a.out

SRC = tests/main.cpp

all: $(NAME)

$(NAME): ${SRC}
	$(CLANG) $(FLAGS) -I src -I utils -D NS ${SRC} -o $(NAME) 
	# ./a.out
	# rm -rf $(NAME)

# a: ${SRC}
# 	$(CLANG) $(FLAGS) -I src -I utils ${SRC} -o $(NAME)
# 	./a.out
# 	rm -rf $(NAME)
	
diff: ${SRC}
	$(CLANG) $(FLAGS) -I src -I utils -D NS ${SRC} -o $(NAME)
	./a.out > 1
	$(CLANG) $(FLAGS) -I src -I utils ${SRC} -o $(NAME)
	./a.out > 2
	diff 1 2
	rm -rf 1 2
	rm -rf $(NAME)


san :
	$(CLANG) $(FLAGS) -I src -I utils  -fsanitize=address -g ${SRC} -o $(NAME)

clean:

fclean: clean
	rm -rf $(NAME)

re: fclean all
