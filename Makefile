# Compiler and Flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
SRCS = push_swap.c sort/handling.c parcing/checking.c parcing/ft_split.c parcing/ft_strjoin.c parcing/substr.c includes/ft_atoi.c includes/ft_lst_utils.c \
		instructions/push.c instructions/reverse_rotate.c instructions/rotat.c instructions/swap.c sort/sort_small_numb.c sort/preparing.c sort/sorting.c \
		sort/countinue_the_proccess.c sort/best_move.c sort/shortcuts.c sort/min_max_of_array.c 

HEADER = includes/push_swap.h
NAME = push_swap
OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ $(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c $(HEADER)
	@ $(CC) $(CFLAGS) -c $< -o $@

clean:
	@ $(RM) $(OBJ)

fclean: clean
	@ $(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
