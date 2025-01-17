#include "push_swap.h"

void    rotat(t_list **stack, char c)
{
    int value;
    t_list  *tmp;
    t_list  *new;

    tmp = (*stack);
    value = (*stack)->value;
    new = ft_lstnew(value);
    ft_lstadd_back(stack, new);
    *stack = (*stack)->next;
    free(tmp);
    if (c == 'a')
        ft_putstr("ra");
    if (c == 'b')
        ft_putstr("rb");
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

void    reverse_rotat(t_list **stack, char  c)
{
    t_list  *tmp;
    int     value;

    tmp = 
}