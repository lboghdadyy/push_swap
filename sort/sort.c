#include "../includes/push_swap.h"

int get_the_max(t_list *lst)
{
    int max;

    max = lst->content;
    while (lst)
    {
        if (lst->content > max)
            max = lst->content;
        lst = lst->next;
    }
    return (max);
}

void    sort_three(t_list **list)
{
    int     max;

    if (are_they_sorted(*list))
    {
        max = get_the_max(*list);
        if ((*list)->content == max)
            ra(list);
        else if ((*list)->next->content == max)
        {
            sa(list);
            ra(list);
        }
        if ((*list)->content > (*list)->next->content)
            sa(list);
    }
}

int     get_the_min(t_list *list)
{
    int min;

    min = list->content;
    list = list->next;
    while (list)
    {
        if (list->content < min)
            min = list->content;
        list = list->next;
    }
    return (min);
}

int     index_of_min(t_list *list)
{
    int index;
    int min;

    min = get_the_min(list);
    index = 1;
    while (list)
    {
        if (list->content == min)
            return (index);
        list = list->next;
        index++;
    }
    return (index);
}

void    sort_five(t_list **list)
{
    int     min;
    t_list  *stack_b;
    int     index;

    if (are_they_sorted(*list))
    {
        stack_b = NULL;
        min = get_the_min(*list);
        index = index_of_min(*list);
        if (index >= 3)
        {
            while ((*list)->content != min)
                rra(list);
        }
        else
        {
            while ((*list)->content != min)
                ra(list);
        }
        pb(list, &stack_b);
        min = get_the_min(*list);
        while ((*list)->content != min)
            ra(list);
        pb(list, &stack_b);
        sort_three(list);
        pa(list, &stack_b);
        pa(list, &stack_b);
    }
}