/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small_numb.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad < sbaghdad@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:30:05 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/02/17 19:28:29 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_list **list)
{
	int	max;

	if (are_they_sorted(*list))
	{
		max = get_the_max(*list);
		if ((*list)->content == max)
			ra(list);
		else if ((*list)->next->content == max)
			rra(list);
		if ((*list)->content > (*list)->next->content)
			sa(list);
	}
}

int	index_of_min(t_list *list)
{
	int	index;
	int	min;

	min = get_the_min(list);
	index = 0;
	while (list)
	{
		if (list->content == min)
			return (index);
		list = list->next;
		index++;
	}
	return (index);
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int		min;
	int		index;

	while (ft_lstsize(*stack_a) > 3)
	{
		min = get_the_min(*stack_a);
		index = index_of_min(*stack_a);
		while ((*stack_a)->content != min)
		{
			if (index >= ft_lstsize(*stack_a) / 2)
				rra(stack_a);
			else
				ra(stack_a);
		}
		pb(stack_a, stack_b);
	}
	sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_four(t_list **stack_a, t_list **stack_b)
{
	int		min;
	int		index;

	if (are_they_sorted(*stack_a))
	{
		min = get_the_min(*stack_a);
		index = index_of_min(*stack_a);
		if (index > 2)
			while ((*stack_a)->content != min)
				rra(stack_a);
		else
			while ((*stack_a)->content != min)
				ra(stack_a);
		pb(stack_a, stack_b);
		sort_three(stack_a);
		pa(stack_a, stack_b);
	}
}


void	set_index(t_list **stack)
{
	t_list	*tmp;
	int		index;

	tmp = *stack;
	index = 0;
	while (tmp)
	{
		tmp->index = index;
		index++;
		tmp = tmp->next;
	}
}
