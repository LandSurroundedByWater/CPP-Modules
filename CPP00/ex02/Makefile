# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsaari <tsaari@hive.student.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/08 19:11:42 by tsaari            #+#    #+#              #
#    Updated: 2024/08/08 09:39:55 by tsaari           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = account

CC = c++
CCFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Account.cpp tests.cpp
OBJS = $(SRCS:.cpp=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CCFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean 
