#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>

typedef struct s_list
{
    struct list_t *next;
    int value;
} t_list;

int     ft_atoi(char *str);
char	**ft_split(char *s, char c);
void	ft_lstclear(t_list **lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(int value);
void	free_tab(char **str);
t_list  *ft_new_lst(char **args, int index);
void    ft_putstr(char  *str);

#endif