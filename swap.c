#include "push_swap.h"

void    swap(t_list **ls, char c)
{
    int     value;
    t_list  *list;

    list = (*ls)->next;
    value =  list->value;
    list->value = (*ls)->value;
    (*ls)->value = value;
    if(c == 'a')
        ft_putstr("sa");
    else
        ft_putstr("sb");
}