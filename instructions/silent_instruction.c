#include "../includes/push_swap.h"

void    silent_ra(t_list **stack)
{
    rotat(stack);
}

void    silent_rb(t_list **stack)
{
    rotat(stack);
}
void	silent_sa(t_list **stack)
{
	swap(stack);
}

void	silent_sb(t_list **stack)
{
	swap(stack);
}

void    silent_rra(t_list **stack)
{
    reverse_rotate(stack);
}

void    silent_rrb(t_list **stack)
{
    reverse_rotate(stack);
}

void    silent_rrr(t_list **stack_a, t_list **stack_b)
{
    reverse_rotate(stack_a);
    reverse_rotate(stack_b);
}

void    silent_rr(t_list **stack_a, t_list **stack_b)
{
    rotat(stack_a);
    rotat(stack_b);
}