/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_numb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad <sbaghdad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:30:05 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/02/06 10:37:25 by sbaghdad         ###   ########.fr       */
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
		{
			sa(list);
			ra(list);
		}
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

void	sort_five(t_list **list)
{
	int		min;
	t_list	*stack_b;
	int		index;

	stack_b = NULL;
	(1) && (min = get_the_min(*list), index = index_of_min(*list));
	if (index >= 3)
	{
		while ((*list)->content != min)
			rra(list);
	}
	else
	{
		while ((*list)->content != min)
			ra(list);
	}
	pb(list, &stack_b);
	min = get_the_min(*list);
	while ((*list)->content != min)
		ra(list);
	pb(list, &stack_b);
	sort_three(list);
	pa(list, &stack_b);
	pa(list, &stack_b);
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
