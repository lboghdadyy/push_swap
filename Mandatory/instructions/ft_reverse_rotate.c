/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad < sbaghdad@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:30:50 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/02/18 12:32:55 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_reverse_rotate(t_list **list)
{
	t_list	*last;
	t_list	*new_last;

	if (!list || !*list || !(*list)->next)
		return ;
	new_last = *list;
	while (new_last->next && new_last->next->next)
		new_last = new_last->next;
	last = new_last->next;
	new_last->next = NULL;
	last->next = *list;
	*list = last;
}

void	ft_rra(t_list **stack)
{
	ft_reverse_rotate(stack);
	write(1, "rra\n", 4);
}

void	ft_rrb(t_list **stack)
{
	ft_reverse_rotate(stack);
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}
