#include "../includes/push_swap.h"

void	down_up(t_list **stack_a, t_list **stack_b)
{
	rrb(stack_b);
	ra(stack_a);
}

void	up_down(t_list **stack_a, t_list **stack_b)
{
	rb(stack_b);
	rra(stack_a);
}
