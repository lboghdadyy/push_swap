/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad < sbaghdad@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:30:08 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/03/02 15:13:44 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_set_status(t_list *stack)
{
	int	mid;

	if (!stack)
		return ;
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

int	ft_index_st(t_list *list, int index)
{
	while (list)
	{
		if (list->index == index)
			return (list->status);
		list = list->next;
	}
	return (1);
}

void	ft_set_target_status(t_list **stack_a, t_list **stack_b)
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
		return (0);
	while ((*s_b)->index != i || (*s_a)->index != trgt)
	{
		if ((*s_b)->index != i && (*s_a)->index != trgt)
		{
			if (ft_index_st(*s_b, i) == 1 && ft_index_st(*s_a, trgt) == 1)
				ft_rrr(s_a, s_b);
			else if (ft_index_st(*s_b, i) == 0 && ft_index_st(*s_a, trgt) == 1)
				ft_up_down(s_a, s_b);
			else if (ft_index_st(*s_b, i) == 0 && ft_index_st(*s_a, trgt) == 0)
				ft_rr(s_a, s_b);
			else
				ft_down_up(s_a, s_b);
		}
		else
			ft_cont_the_proc(i, trgt, s_a, s_b);
		ft_set_status(*s_a);
		ft_set_status(*s_b);
	}
	ft_pa(s_a, s_b);
	return (1);
}

int	ft_start_sorting(t_list **s_a, t_list **s_b)
{
	int	best;

	while (*s_b)
	{
		ft_set_index(s_b);
		ft_set_index(s_a);
		ft_set_status(*s_b);
		ft_set_status(*s_a);
		ft_find_target(s_a, s_b);
		ft_set_target_status(s_a, s_b);
		best = ft_best_move(*s_a, *s_b);
		if (best == -1)
			return (ft_lstclear(s_a), ft_lstclear(s_b), -1);
		if (!ft_execute(best, ft_get_target(*s_b, best), s_a, s_b))
			return (ft_lstclear(s_a), ft_lstclear(s_b), -1);
	}
	while (ft_are_they_sorted(*s_a))
	{
		if (ft_status_of_min(*s_a))
			ft_rra(s_a);
		else
			ft_ra(s_a);
	}
	return (1);
}
