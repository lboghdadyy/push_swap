# Compiler and Flags
CC=cc
CFLAGS=-Wall -Wextra -Werror 
RM=rm -rf
SRCS=Mandatory/push_swap.c Mandatory/sort/handling.c Mandatory/parcing/checking.c Mandatory/parcing/ft_split.c Mandatory/parcing/ft_strjoin.c Mandatory/parcing/substr.c Mandatory/includes/ft_atoi.c Mandatory/includes/ft_lst_utils.c \
		Mandatory/instructions/push.c Mandatory/instructions/reverse_rotate.c Mandatory/instructions/rotat.c Mandatory/instructions/swap.c Mandatory/sort/sort_small_numb.c Mandatory/sort/preparing.c Mandatory/sort/sorting.c \
		Mandatory/sort/countinue_the_proccess.c Mandatory/sort/best_move.c Mandatory/sort/shortcuts.c Mandatory/sort/min_max_of_array.c
B_SRCS=Bonus/parcing/checking.c  Bonus/parcing/ft_atoi.c  Bonus/parcing/ft_split.c  Bonus/parcing/ft_strjoin.c  Bonus/parcing/handling.c  Bonus/parcing/substr.c \
		Bonus/push_swap_bonus.c Bonus/parcing/ft_lst_utils.c Bonus/instructions/push.c Bonus/instructions/reverse_rotate.c Bonus/instructions/rotat.c \
		Bonus/instructions/swap.c Bonus/getting_instructions.c Bonus/gnl/get_next_line.c  Bonus/gnl/get_next_line_utils.c
HEADER=includes/push_swap.h
NAME=push_swap
OBJ=$(SRCS:.c=.o)
BONUS_HEADER= Bonus/push_swap_bonus.h
B_OBJ=$(B_SRCS:.c=.o)
BONUS_NAME=checker
all: $(NAME)

bonus : $(BONUS_NAME)

$(BONUS_NAME) : $(B_OBJ)
	$(CC) $(CFLAGS) $(B_OBJ) -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c $(HEADER) 
	$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o: bonus/%.c  ./Bonus/push_swap_bonus.h
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJ) $(B_OBJ)

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re
