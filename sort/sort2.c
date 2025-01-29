#include "../includes/push_swap.h"

void    sort_four(t_list **list)
{
    int min;
    int index;
    t_list *l;

    if (are_they_sorted(*list))
    {
        l = NULL;
        min = get_the_min(*list);
        index = index_of_min(*list);
        if (index > 2)
            while ((*list)->content != min)
                rra(list);
        else
            while ((*list)->content != min)
                ra(list);
        pb(list, &l);
        sort_three(list);
        pa(list, &l);
    }
}