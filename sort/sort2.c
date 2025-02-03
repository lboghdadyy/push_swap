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

int get_the_index(int value, t_list *list)
{
    while (list)
    {
        if (list->content == value)
            return list->index;
        list = list->next;
    }
    return -1;
}

void find_target(t_list **stack_a, t_list **stack_b)
{
    t_list *tmp_b;
    t_list *tmp_a;
    int nearest_big;
    int min_value;
    int target_index;

    if (!stack_a || !stack_b || !(*stack_a) || !(*stack_b))
        return;

    min_value = get_the_min(*stack_a);
    tmp_b = *stack_b;

    while (tmp_b)
    {
        tmp_a = *stack_a;
        nearest_big = get_the_max(*stack_a);
        target_index = get_the_index(min_value, *stack_a);

        while (tmp_a)
        {
            if (tmp_a->content >= tmp_b->content && tmp_a->content <= nearest_big)
            {
                nearest_big = tmp_a->content;
                target_index = tmp_a->index;
            }
            tmp_a = tmp_a->next;
        }
        tmp_b->target_index = target_index;
        tmp_b = tmp_b->next;
    }
}

void start_pushing(t_list **stack_a, t_list **stack_b)
{
    int mid = (get_the_min(*stack_a) + get_the_max(*stack_a)) / 2;

    while (ft_lstsize(*stack_a) > 3)
    {
        if ((*stack_a)->content > mid)
        {
            pb(stack_a, stack_b);
            if (ft_lstsize(*stack_b) > 1)
                rb(stack_b);  // Rotate only if stack_b has more than 1 element
        }
        else
            pb(stack_a, stack_b);
    }
}

void set_index(t_list **stack)
{
    t_list *tmp;
    int index = 0;

    tmp = *stack;
    while (tmp)
    {
        tmp->index = index;
        index++;
        tmp = tmp->next;
    }
}

void just_sort(t_list **stack_a)
{
    t_list *stack_b = NULL;

    if (are_they_sorted(*stack_a))
    {
        start_pushing(stack_a, &stack_b);
        sort_three(stack_a);
        set_index(stack_a);
        set_index(&stack_b);
        find_target(stack_a, &stack_b);
        start_sorting(stack_a, &stack_b);
    }
}
