#include "../includes/push_swap.h"

void    push(t_list **stack1, t_list **stack2)
{
    t_list  *tmp;

    if (!stack1 || !*stack1) 
        return ;
    tmp = *stack1; 
    *stack1 = (*stack1)->next; 
    if (*stack1) 
        (*stack1)->previous = NULL;
    tmp->next = *stack2;
    if (*stack2) 
        (*stack2)->previous = tmp;
    *stack2 = tmp; 
}


void    pa(t_list **stack_a, t_list **stack_b)
{
    push(stack_b, stack_a);
    write(1, "pa\n", 3);
}

void    pb(t_list **stack_a, t_list **stack_b)
{
    push(stack_a, stack_b);
    write(1, "pb\n", 3);
}