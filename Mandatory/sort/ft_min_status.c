/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_status.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad < sbaghdad@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:46:34 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/02/27 15:38:21 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_status_of_min(t_list *stack)
{
	t_list	*tmp;
	int		min;

	if (!stack)
		return (0);
	min = ft_get_the_min(stack);
	tmp = stack;
	while (tmp)
	{
		if (tmp->content == min)
		{
			if (tmp->index >= ((ft_lstsize(stack)) / 2))
				return (1);
			else
				return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}
