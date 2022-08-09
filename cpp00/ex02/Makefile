# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/14 23:11:43 by cmaginot          #+#    #+#              #
#    Updated: 2022/08/09 14:23:26 by cmaginot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=account

SRCS=Account.cpp tests.cpp
OBJS=$(SRCS:.cpp=.o)
INCS=Account.hpp

CC=clang++
CFLAGS=-Wall -Wextra -Werror -std=c++98 -g3
INCLUDES=$(addprefix -I , $(INCS))

RM=rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean 
	make all