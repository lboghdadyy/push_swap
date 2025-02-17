# Compiler and Flags
CC=cc
CFLAGS=-Wall -Wextra -Werror -fsanitize=address -g3
RM=rm -rf
SRCS=Mandatory/ft_push_swap.c Mandatory/sort/ft_handling.c Mandatory/parsing/ft_checking.c Mandatory/parsing/ft_split.c Mandatory/parsing/ft_strjoin.c Mandatory/parsing/ft_substr.c Mandatory/includes/ft_atoi.c Mandatory/includes/ft_lst_utils.c \
		Mandatory/instructions/ft_push.c Mandatory/instructions/ft_reverse_rotate.c Mandatory/instructions/ft_rotat.c Mandatory/instructions/ft_swap.c Mandatory/sort/ft_sort_small_numb.c Mandatory/sort/ft_preparing.c Mandatory/sort/ft_sorting.c \
		Mandatory/sort/ft_countinue_the_proccess.c Mandatory/sort/ft_best_move.c Mandatory/sort/ft_shortcuts.c Mandatory/sort/ft_min_max_of_array.c Mandatory/parsing/ft_check_dup.c Mandatory/sort/ft_min_status.c
B_SRCS=Bonus/get_next_line/get_next_line_utils.c Bonus/get_next_line/get_next_line.c Bonus/instructions/ft_push_bonus.c Bonus/instructions/ft_reverse_rotate_bonus.c Bonus/instructions/ft_rotat_bonus.c Bonus/instructions/ft_swap_bonus.c \
		Bonus/parsing/ft_atoi_bonus.c Bonus/parsing/ft_check_dup_bonus.c Bonus/parsing/ft_checking_bonus.c Bonus/parsing/ft_handling_bonus.c Bonus/parsing/ft_instructions_lst_utils_bonus.c Bonus/parsing/ft_lst_utils_bonus.c \
		Bonus/parsing/ft_split_bonus.c Bonus/parsing/ft_strjoin_bonus.c Bonus/parsing/ft_substr_bonus.c Bonus/ft_getting_instructions_bonus.c Bonus/ft_push_swap_bonus.c
HEADER=includes/push_swap.h
NAME=push_swap
OBJ=$(SRCS:.c=.o)
BONUS_HEADER= Bonus/push_swap_bonus.h
B_OBJ=$(B_SRCS:.c=.o)
BONUS_NAME=checker
all: $(NAME)

bonus : $(BONUS_NAME)

$(BONUS_NAME) : $(B_OBJ)
	$(CC) $(CFLAGS)  $(B_OBJ) -o $@

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
