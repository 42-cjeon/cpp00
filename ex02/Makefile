# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/03 14:42:04 by cjeon             #+#    #+#              #
#    Updated: 2022/03/12 19:10:37 by cjeon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CXXFLAGS = -std=c++98 -pedantic -Wall -Wextra -Werror

NAME = main
SRCS = Account.cpp tests.cpp
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean :
	rm -f $(OBJS)
	rm -f test.log origin.log

fclean : clean
	rm -f $(NAME)

re : fclean all

test : $(NAME)
	$(shell ./$(NAME) | cut -c 19- > test.log)
	$(shell cut -c 19- 19920104_091532.log > origin.log)
	diff origin.log test.log

.PHONY : all clean fclean re test