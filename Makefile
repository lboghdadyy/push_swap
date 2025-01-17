CC=cc
CFLAGS=-Wall -Wextra -Werror
#name
NAME=push_swap
#src files
SRC=srcs/ft_split.c srcs/push_swap_utils.c push_swap_main.c
HEADER=header/push_swap.h
#object files
OBJ=$(SRC:.c=.o)

RM = rm -rf


all : $(NAME)

$(NAME) : $(OBJ)
    $(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o : %.c $(HEADER)
    $(CC) $(CFLAGS) $(SRC) -c $< -o $@

clean :
    $(RM) $(OBJ)

fclean : clean
    $(RM) $(NAME)
