# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/02 14:25:53 by yongmipa          #+#    #+#              #
#    Updated: 2023/03/29 17:07:18 by suhwpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell

CC			= cc
CFLAGS		= -Wall -Wextra -Wextra
RFLAGS		= -lreadline
LFLAGS		= -L${HOME}/.brew/opt/readline/lib
IFLAGS		= -I${HOME}/.brew/opt/readline/include

AR			= ar
ARFLAGS		= -rcs
RM			= rm -f

INCS_DIR	= ./includes/
SRCS_DIR	= ./src/
BUILTINS_DIR= ./src/builtin/

LIB_DIR		= ./libft

LIB_NAME	= ./libft/libft.a

INCS		= -I includes

SRC			=	list_utils.c path_utils.c main.c delete_quote.c tokenize.c \
				tokenize_utils.c envp_utils.c token_access_utils.c err_print_utils.c \
				init_envp.c shell_utils.c err_print.c dollar.c find_dollar.c token_access_utils2.c token_access_utils3.c\
				token_access.c syntax.c syntax_utils.c delete_quote_util.c heredoc.c signal.c heredoc_utils.c heredoc_utils2.c
BUILTIN		=	ft_export.c ft_unset.c ft_builtin.c ft_cd.c ft_echo.c ft_env.c \
				ft_exit.c ft_pwd.c

SRCS		=	$(addprefix $(SRCS_DIR), $(SRC))
LIBS		=	$(addprefix $(LIB_DIR), $(LIB_NAME))
BUILTINS	=	$(addprefix $(BUILTINS_DIR), $(BUILTIN))
OBJS		=	$(SRCS:.c=.o) $(BUILTINS:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIB_DIR)
	$(CC) $(CFLAGS) $(RFLAGS) $(LFLAGS) -o $(NAME) $(OBJS) $(LIB_NAME)

clean :
	make -C $(LIB_DIR) clean
	$(RM) $(OBJS)

fclean : clean
	make -C $(LIB_DIR) fclean
	$(RM) $(NAME)

re :
	make fclean
	make all

PHONY	: all clean fclean re
