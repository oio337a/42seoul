# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/03 15:23:57 by yongmipa          #+#    #+#              #
#    Updated: 2023/04/20 17:27:12 by yongmipa         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL := all

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread
SRCS = 	main.c utils.c validate.c actions.c philos.c

NAME = philo

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $^ -o $@

RM = rm -rf

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)
	
re : 
	make fclean
	make all

.PHONY: all clean fclean re