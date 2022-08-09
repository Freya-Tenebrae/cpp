# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/14 23:11:43 by cmaginot          #+#    #+#              #
#    Updated: 2022/08/09 15:25:08 by cmaginot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=animal

SRCS=main.cpp Animal.cpp Cat.cpp Dog.cpp Brain.cpp
OBJS=$(SRCS:.cpp=.o)
INCS=Animal.hpp Cat.hpp Dog.hpp Brain.hpp

CC=clang++
CFLAGS=-Wall -Wextra -Werror -std=c++98 -g3
INCLUDES=$(addprefix -I , $(INCS))

RM=rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean 
	make all