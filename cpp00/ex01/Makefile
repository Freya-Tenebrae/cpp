# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/14 23:11:43 by cmaginot          #+#    #+#              #
#    Updated: 2022/04/11 20:36:31 by cmaginot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=has_been_phonebook

SRCS=main.cpp PhoneBook.cpp Contact.cpp
OBJS=$(SRCS:.cpp=.o)
INCLUDES=PhoneBook.hpp Contact.hpp

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