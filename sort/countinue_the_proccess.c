#include "../includes/push_swap.h" 

void   continue_the_procc(int index, int target, t_list **stack_a, t_list **stack_b)
{
    if ((*stack_b)->index != index)
    {
        while ((*stack_b)->index != index)
        {
            if(status_index(*stack_b, index))
                rrb(stack_b);
            else
                rb(stack_b);
        }
    }
    if ((*stack_a)->index != target)
    {
        while ((*stack_a)->index != target)
        {
            if(status_index(*stack_a, target))
                rra(stack_a);
            else
                ra(stack_a);
        }
    }
}