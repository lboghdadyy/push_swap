/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad <sbaghdad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:30:50 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/02/06 10:30:51 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse_rotate(t_list **list)
{
	t_list	*last;
	t_list	*new_last;

	if (!list || !*list || !(*list)->next)
		return ;
	last = ft_lstlast(*list);
	new_last = last->previous;
	new_last->next = NULL;
	last->previous = NULL;
	last->next = *list;
	(*list)->previous = last;
	*list = last;
}

void	rra(t_list **stack)
{
	reverse_rotate(stack);
	write(1, "rra\n", 4);
}

void	rrb(t_list **stack)
{
	reverse_rotate(stack);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}
