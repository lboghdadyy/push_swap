/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small_numb.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad < sbaghdad@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:30:05 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/03/02 15:10:01 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_three(t_list **list)
{
	int	max;

	if (ft_are_they_sorted(*list))
	{
		max = ft_get_the_max(*list);
		if ((*list)->content == max)
			ft_ra(list);
		else if ((*list)->next->content == max)
			ft_rra(list);
		if ((*list)->content > (*list)->next->content)
			ft_sa(list);
	}
}

int	ft_index_of_min(t_list *list)
{
	int	index;
	int	min;

	min = ft_get_the_min(list);
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

void	ft_sort_five(t_list **stack_a, t_list **stack_b)
{
	int		min;
	int		index;

	while (ft_lstsize(*stack_a) > 3)
	{
		min = ft_get_the_min(*stack_a);
		index = ft_index_of_min(*stack_a);
		while ((*stack_a)->content != min)
		{
			if (index >= ft_lstsize(*stack_a) / 2)
				ft_rra(stack_a);
			else
				ft_ra(stack_a);
		}
		ft_pb(stack_a, stack_b);
	}
	ft_sort_three(stack_a);
	while (*stack_b)
		ft_pa(stack_a, stack_b);
}

void	ft_set_index(t_list **stack)
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
