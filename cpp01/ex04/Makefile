# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/14 23:11:43 by cmaginot          #+#    #+#              #
#    Updated: 2022/05/11 09:59:34 by cmaginot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=sed_is_for_looser

SRCS=main.cpp Switch.cpp
OBJS=$(SRCS:.cpp=.o)
INCLUDES=Switch.hpp

CC=clang++
CFLAGS=-Wall -Wextra -Werror -std=c++98 -g3

RM=rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $< -I $(INCLUDES)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
	