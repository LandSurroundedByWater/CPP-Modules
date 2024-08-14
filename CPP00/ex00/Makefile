# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsaari <tsaari@hive.student.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/08 19:11:42 by tsaari            #+#    #+#              #
#    Updated: 2024/08/07 12:41:48 by tsaari           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

CC = c++
CCFLAGS = -Wall -Wextra -Werror

SRCS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CCFLAGS) -o $@ $^
	@echo "\033[1;32mCompile success!\n\033[0m"

%.o: %.cpp
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean 
