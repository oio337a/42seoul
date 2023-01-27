
NAME		= push_swap

CC			= cc
FLAGS		= -Wall -Wextra
AR			= ar rcs
RM			= rm -f

INCS_DIR	= ./includes/
SRCS_DIR	= ./src/
LIB_DIR		= ./libft/

LIB_NAME	= ./libft/libft.a
INCS		= -I includes

SRC			=	command_push.c command_reverse_rotate.c command_rotate.c command_swap.c \
				error.c get_pivot.c greedy_algorithm1.c greedy_algorithm2.c main.c push_atoi.c \
				que_data.c que_set.c validation.c greedy_algorithm3.c three_ac.c algorithm_utils.c 

SRCS		=	$(addprefix $(SRCS_DIR), $(SRC))
LIBS		=	$(addprefix $(LIB_DIR), $(LIB_NAME))
OBJS		=	$(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIB_DIR)
	$(CC) -o $(NAME) $(OBJS) -L $(LIB_DIR) -lft -I $(INCS_DIR)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

clean :
	make -C $(LIB_DIR) clean
	$(RM) $(OBJS)

fclean : clean
	make -C $(LIB_DIR) fclean
	$(RM) $(NAME)

re : fclean all

PHONY	: all clean fclean re