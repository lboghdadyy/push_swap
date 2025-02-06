/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad <sbaghdad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:29:52 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/02/06 10:29:53 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_four(t_list **stack_a)
{
	int		min;
	int		index;
	t_list	*stack_b;

	if (are_they_sorted(*stack_a))
	{
		stack_b = NULL;
		min = get_the_min(*stack_a);
		index = index_of_min(*stack_a);
		if (index > 2)
			while ((*stack_a)->content != min)
				rra(stack_a);
		else
			while ((*stack_a)->content != min)
				ra(stack_a);
		pb(stack_a, &stack_b);
		sort_three(stack_a);
		pa(stack_a, &stack_b);
	}
}

int	get_the_index(int value, t_list *list)
{
	while (list)
	{
		if (list->content == value)
			return (list->index);
		list = list->next;
	}
	return (-1);
}

int	find_target(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_b;
	t_list	*tmp_a;
	int		n_big;
	int		min_val;
	int		trgt_indx;

	if (!stack_a || !stack_b || !(*stack_a) || !(*stack_b))
		return (-1);
	(1) && (min_val = get_the_min(*stack_a), tmp_b = *stack_b);
	while (tmp_b)
	{
		(1) && (tmp_a = *stack_a, n_big = get_the_max(*stack_a));
		trgt_indx = get_the_index(min_val, *stack_a);
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

void	start_pushing(t_list **stack_a, t_list **stack_b)
{
	int	mid;

	mid = (get_the_min(*stack_a) + get_the_max(*stack_a)) / 2;
	while (ft_lstsize(*stack_a) > 3)
	{
		if ((*stack_a)->content > mid)
		{
			pb(stack_a, stack_b);
			if (ft_lstsize(*stack_b) > 1)
				rb(stack_b);
		}
		else
			pb(stack_a, stack_b);
	}
}

void	just_sort(t_list **stack_a)
{
	t_list	*stack_b;
	int		ret;

	stack_b = NULL;
	if (are_they_sorted(*stack_a))
	{
		start_pushing(stack_a, &stack_b);
		sort_three(stack_a);
		set_index(stack_a);
		set_index(&stack_b);
		if (!find_target(stack_a, &stack_b))
			return (ft_lstclear(stack_a));
		ret = start_sorting(stack_a, &stack_b);
		if (ret == -1)
			return (ft_lstclear(stack_a));
	}
}
