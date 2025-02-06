/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad <sbaghdad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:29:14 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/02/06 10:29:20 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	best_move(t_list *stack_a, t_list *stack_b)
{
	int		count_b;
	int		count_a;
	t_list	*tmp;
	int		index;
	int		count;

	(1) && (tmp = stack_b, index = -1, count = 5000);
	while (tmp)
	{
		if (tmp->status)
			count_b = ft_lstsize(stack_b) - tmp->index;
		else
			count_b = tmp->index;
		if (tmp->target_status)
			count_a = ft_lstsize(stack_a) - tmp->target_index;
		else
			count_a = tmp->target_index;
		if (count_a + count_b < count)
		{
			count = count_a + count_b;
			index = tmp->index;
		}
		tmp = tmp->next;
	}
	return (index);
}

int	get_target(t_list *list, int index)
{
	while (list->index != index)
		list = list->next;
	if (list->index == index)
		return (list->target_index);
	else
		return (-1);
}
