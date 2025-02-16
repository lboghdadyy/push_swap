/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotat.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad <sbaghdad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:30:45 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/02/15 14:52:59 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

// void	rotat(t_list **list)
// {
// 	t_list	*tmp;
// 	t_list	*last;

// 	if (!list || !*list || !(*list)->next)
// 		return ;
// 	tmp = *list;
// 	*list = (*list)->next;
// 	last = ft_lstlast(*list);
// 	last->next = tmp;
// 	tmp->next = NULL;
// }

void	rotat(t_list	**list)
{
	t_list	*tmp;

	if (!*list || !(*list)->next)
		return ;
	tmp = *list;
	*list = ft_lstlast(*list);
	(*list)->next = tmp;
	*list = tmp->next;
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
