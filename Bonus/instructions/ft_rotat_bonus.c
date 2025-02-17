/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotat_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad < sbaghdad@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:30:45 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/02/17 10:31:32 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap_bonus.h"

void	rotat(t_list **list)
{
	t_list	*tmp;
	t_list	*last;

	if (!list || !*list || !(*list)->next)
		return ;
	tmp = *list;
	*list = (*list)->next;
	last = ft_lstlast(*list);
	last->next = tmp;
	tmp->next = NULL;
}



void	ra(t_list **stack)
{
	rotat(stack);
}

void	rb(t_list **stack)
{
	rotat(stack);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotat(stack_a);
	rotat(stack_b);
}
