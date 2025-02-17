/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad < sbaghdad@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:30:08 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/02/17 23:15:41 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	set_status(t_list *stack)
{
	int	mid;

	if (ft_lstsize(stack) % 2 == 0)
		mid = ft_lstsize(stack) / 2;
	else
		mid = (ft_lstsize(stack) / 2) + 1;
	while (stack)
	{
		if (stack->index >= mid)
			stack->status = 1;
		else
			stack->status = 0;
		stack = stack->next;
	}
}

int	status_index(t_list *list, int index)
{
	while (list)
	{
		if (list->index == index)
			return (list->status);
		list = list->next;
	}
	return (1);
}

void	set_target_status(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	if (!stack_a || !stack_b || !(*stack_a) || !(*stack_b))
		return ;
	tmp_b = *stack_b;
	while (tmp_b)
	{
		tmp_a = *stack_a;
		while (tmp_a && tmp_a->index != tmp_b->target_index)
			tmp_a = tmp_a->next;
		if (tmp_a)
			tmp_b->target_status = tmp_a->status;
		tmp_b = tmp_b->next;
	}
}

int	ft_execute(int i, int trgt, t_list **s_a, t_list **s_b)
{
	if (trgt == -1)
		return (-1);
	while ((*s_b)->index != i || (*s_a)->index != trgt)
	{
		if ((*s_b)->index != i && (*s_a)->index != trgt)
		{
			if (status_index(*s_b, i) && status_index(*s_a, trgt))
				rrr(s_a, s_b);
			else if (!status_index(*s_b, i) && status_index(*s_a, trgt))
				up_down(s_a, s_b);
			else if (!status_index(*s_b, i) && !status_index(*s_a, trgt))
				rr(s_a, s_b);
			else
				down_up(s_a, s_b);
		}
		else
			cont_the_proc(i, trgt, s_a, s_b);
		set_status(*s_a);
		set_status(*s_b);
	}
	pa(s_a, s_b);
	return (1);
}

int	start_sorting(t_list **s_a, t_list **s_b)
{
	int	best;

	while (*s_b)
	{
		set_index(s_b);
		set_index(s_a);
		set_status(*s_b);
		set_status(*s_a);
		find_target(s_a, s_b);
		set_target_status(s_a, s_b);
		best = best_move(*s_a, *s_b);
		if (best == -1)
			return (-1);
		if (!ft_execute(best, get_target(*s_b, best), s_a, s_b))
			return (-1);
	}
	while (are_they_sorted(*s_a))
	{
		if (ft_status_of_min(*s_a))
			rra(s_a);
		else
			ra(s_a);
	}
	return (1);
}
