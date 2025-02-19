/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preparing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad < sbaghdad@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:29:52 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/02/18 18:12:52 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_get_the_index(int value, t_list *list)
{
	while (list)
	{
		if (list->content == value)
			return (list->index);
		list = list->next;
	}
	return (-1);
}

int	ft_find_target(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_b;
	t_list	*tmp_a;
	int		n_big;
	int		min_val;
	int		trgt_indx;

	if (!stack_a || !stack_b || !(*stack_a) || !(*stack_b))
		return (-1);
	(1) && (min_val = ft_get_the_min(*stack_a), tmp_b = *stack_b);
	while (tmp_b)
	{
		(1) && (tmp_a = *stack_a, n_big = ft_get_the_max(*stack_a));
		trgt_indx = ft_get_the_index(min_val, *stack_a);
		if (trgt_indx == -1)
			return (-1);
		while (tmp_a)
		{
			if (tmp_a->content >= tmp_b->content && tmp_a->content <= n_big)
				(1) && (n_big = tmp_a->content, trgt_indx = tmp_a->index);
			tmp_a = tmp_a->next;
		}
		tmp_b->target_index = trgt_indx;
		tmp_b = tmp_b->next;
	}
	return (1);
}

void	ft_start_pushing(t_list **stack_a, t_list **stack_b)
{
	int	mid;
	int	min;
	int	max;

	max = ft_get_the_max(*stack_a);
	min = ft_get_the_min(*stack_a);
	mid = (min + max) / 2;
	while (ft_lstsize(*stack_a) > 3)
	{
		if ((*stack_a)->content > mid)
		{
			ft_pb(stack_a, stack_b);
			if (ft_lstsize(*stack_b) != 1)
				ft_rb(stack_b);
		}
		else
			ft_pb(stack_a, stack_b);
	}
}

void	ft_big_sort(t_list **stack_a, t_list **stack_b)
{
	if (ft_are_they_sorted(*stack_a))
	{
		ft_start_pushing(stack_a, stack_b);
		ft_sort_three(stack_a);
		ft_set_index(stack_a);
		ft_set_index(stack_b);
		if (!ft_find_target(stack_a, stack_b))
			return (ft_lstclear(stack_a));
		if (!ft_start_sorting(stack_a, stack_b))
			return (ft_lstclear(stack_a));
	}
}
