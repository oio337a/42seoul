# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/17 19:56:17 by yongmipa          #+#    #+#              #
#    Updated: 2023/03/24 16:57:06 by suhwpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
FLAGS = -Wall -Wextra -Werror
SRCS = ft_memcmp.c ft_memmove.c ft_bzero.c ft_memchr.c ft_memcpy.c \
       ft_memset.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c \
       ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c \
       ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c \
       ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
       ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
       ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c  \
       ft_safe_malloc.c \
       ft_lstnew.c \
       ft_lstadd_front.c \
       ft_lstsize.c \
       ft_lstlast.c \
       ft_lstadd_back.c \
       ft_lstdelone.c \
       ft_lstclear.c \
       ft_lstiter.c \
       ft_lstmap.c \
       ft_free.c ft_strcmp.c get_next_line.c
OBJS = $(SRCS:%.c=%.o)
BOBJS = $(BSRCS:%.c=%.o)
ifdef WITH_BONUS
    OBJ_FILES = $(OBJS) $(BOBJS)
else
    OBJ_FILES = $(OBJS)
endif

all : $(NAME)
%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@
$(NAME) : $(OBJ_FILES)
	ar rcs $@ $^
bonus :
	make WITH_BONUS=1 all
clean : 
	rm -f $(OBJS) $(BOBJS)
fclean : clean
	rm -f $(NAME)
re : fclean all
.PHONY: all bonus clean fclean re
