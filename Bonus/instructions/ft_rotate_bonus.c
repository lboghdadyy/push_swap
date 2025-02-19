/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad < sbaghdad@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:30:45 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/02/19 15:47:20 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	ft_rotate(t_list **list)
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

void	ft_ra(t_list **stack)
{
	ft_rotate(stack);
}

void	ft_rb(t_list **stack)
{
	ft_rotate(stack);
}

void	ft_rr(t_list **stack_a, t_list **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
}
