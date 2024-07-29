# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/08 19:11:42 by tsaari            #+#    #+#              #
#    Updated: 2024/06/08 19:12:49 by tsaari           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

CXX = g++
CXXFLAGS = -Wall -Wextra

SRCS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean 
