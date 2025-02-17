/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad < sbaghdad@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:30:50 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/02/17 10:31:29 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap_bonus.h"

void	reverse_rotate(t_list **list)
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

void	rra(t_list **stack)
{
	reverse_rotate(stack);
}

void	rrb(t_list **stack)
{
	reverse_rotate(stack);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
