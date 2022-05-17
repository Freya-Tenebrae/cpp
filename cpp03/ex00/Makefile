# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/14 23:11:43 by cmaginot          #+#    #+#              #
#    Updated: 2022/05/17 14:38:48 by cmaginot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=a.out

SRCS=main.cpp ClapTrap.cpp
OBJS=$(SRCS:.cpp=.o)
INCLUDES=ClapTrap.hpp

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
	