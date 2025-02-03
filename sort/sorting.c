#include "../includes/push_swap.h"
#include <limits.h>
#include <stdio.h>
#include "../includes/push_swap.h"

void set_status(t_list *stack)
{
    int mid;

    if (ft_lstsize(stack) % 2 == 0)
        mid = ft_lstsize(stack) / 2;
    else
        mid = (ft_lstsize(stack) / 2) + 1;
    while (stack)
    {
        if(stack->index >= mid)
            stack->status = 1;
        else
            stack->status = 0;
        stack = stack->next;
    }
}


int status_index(t_list *list, int index)
{
    while (list)
    {
        if (list->index == index)
            return list->status;
        list = list->next;
    }
    return 1;
}
void    ste_target_status(t_list **stack_a, t_list **stack_b)
{
    int mid;
    t_list *tmp;

    if (ft_lstsize(stack) % 2 == 0)
        mid = ft_lstsize(stack) / 2;
    else
        mid = (ft_lstsize(stack) / 2) + 1;
    while ((*stack_b))
    {
        tmp = *stack_a;
        while (tmp->index != (*stack_b)-)
        
        (*stack_b) = (*stack_b)->next;
    }
    
}

int     continue_untill_the_index(t_list **stack, int index)
{
    int     count;

    count = 0;
    while ((*stack)->index != index)
    {
        // printf("hello\n");
        if (status_index(*stack, index))
        {
            silent_rra(stack);
            count++;
        }
        else
        {
            silent_ra(stack);
            count++;
        }
    }
    return (count);
}

int best_move(t_list *stack_a, t_list *stack_b)
{
    t_list  *tmp_stack_a;
    t_list  *tmp_stack_b;
    int     index = -1;
    t_list  *tmp;
    int     count;
    // int     countlesss;
    int     count2 = INT_MAX;

    tmp = stack_b;
    while (tmp)
    {
        tmp_stack_a = duplicate_list(stack_a);
        tmp_stack_b = duplicate_list(stack_b);
        count = 0;
        while (tmp_stack_b && (tmp_stack_b->index != tmp->index) &&
         (tmp_stack_a->index != tmp_stack_b->target_index) && tmp_stack_a)
        {
            if (tmp->status && tmp_stack_b->target_status)
            {
                silent_rrr(&tmp_stack_a, &tmp_stack_b);
                count++;
            }
            else if (!tmp->status && tmp_stack_b->target_status)
            {
                silent_rb(&tmp_stack_b);
                silent_rra(&tmp_stack_a);
                count++;
            }
            else if (!tmp->status && !tmp_stack_b->target_status)
            {
                silent_rr(&tmp_stack_a, &tmp_stack_b);
                count++;
            }
            else if (tmp->status && !tmp_stack_b->target_status)
            {
                silent_rrb(&tmp_stack_b);
                silent_ra(&tmp_stack_a);
                count++;
            }
            set_status(tmp_stack_a);
            set_status(tmp_stack_b);
            if (tmp_stack_b->index == tmp->index && tmp_stack_a->index != tmp->target_index)
                count += continue_untill_the_index(&tmp_stack_a, tmp->target_index);
            else if(tmp_stack_a->index == tmp->target_index && tmp_stack_b->index != tmp->index)
                count += continue_untill_the_index(&tmp_stack_b, tmp->index);
            // printf("count --> {%d}\n", count);
            // printf("index of stack a ---> {%d}\n", tmp_stack_a->index);
            // printf("index of stack b ---> {%d}\n", tmp_stack_b->index);
        }
        ft_lstclear(&tmp_stack_a);
        ft_lstclear(&tmp_stack_b);

        if (count <= count2)
        {
            index = tmp->index;
            count2 = count;
        }
        tmp = tmp->next;
    }
    return (index);
}


void do_this(int index, int target, t_list **stack_a, t_list **stack_b)
{
    if (target == -1)
    {
        printf("error\n");
        exit(0);
    }
    while ((*stack_b)->index != index || (*stack_a)->index != target)
    {
        if ((*stack_b)->index != index && (*stack_a)->index != target)
        {
            if (status_index(*stack_b, index) && status_index(*stack_a, target))
                rrr(stack_a, stack_b);
            else if (!status_index(*stack_b, index) && status_index(*stack_a, target))
            {
                rb(stack_b);
                rra(stack_a);
            }
            else if (status_index(*stack_b, index) && status_index(*stack_a, target))
            {
                rr(stack_a, stack_b);
            }
            else if (status_index(*stack_b, index) && !status_index(*stack_a, target))
            {
                rrb(stack_b);
                ra(stack_a);
            }
        }
        else
            continue_the_procc(index, target, stack_a, stack_b);
        set_status(*stack_a);
        set_status(*stack_b);
    }
    pa(stack_a, stack_b);
}

void print_list(t_list *list)
{
    printf("List Content:\n");
    while (list)
    {
        printf("Content: %d, Index: %d, Target Index: %d, Status: %d, Target Status: %d\n",
               list->content, list->index, list->target_index, list->status, list->target_status);
        list = list->next;
    }
}


int     get_target(t_list *list, int index)
{
    while (list->index != index)
        list = list->next;
    if (list->index == index)
        return (list->target_index);
    else
        return (-1);
}

void start_sorting(t_list **stack_a, t_list **stack_b)
{
    while (*stack_b)
    {
        print_list(*stack_a);
        print_list(*stack_b);
        targ
        int best = best_move(*stack_a, *stack_b);
        printf("the best move is -> {%d}\n", best);
        if (best == -1)
            return;
        do_this(best, get_target(*stack_b, best), stack_a, stack_b);
        set_index(stack_a);
        set_index(stack_b);
        find_target(stack_a, stack_b);
        set_status(*stack_a);
        set_status(*stack_b);
    }

    while ((*stack_a)->index != get_the_index(get_the_min(*stack_a), *stack_a))
        ra(stack_a);
    print_list(*stack_a);
}
