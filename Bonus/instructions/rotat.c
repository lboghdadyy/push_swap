/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotat.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad <sbaghdad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:30:45 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/02/13 13:29:17 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	rotat(t_list **list)
{
	t_list	*tmp;
	t_list	*lst;

	if (!list || !*list || !(*list)->next)
		return ;
	tmp = *list;
	*list = (*list)->next;
	(*list)->previous = NULL;
	lst = ft_lstlast(*list);
	tmp->previous = lst;
	lst->next = tmp;
	tmp->next = NULL;
}

void	ra(t_list **stack)
{
	rotat(stack);
	write(1, "ra\n", 3);
}

void	rb(t_list **stack)
{
	rotat(stack);
	write(1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotat(stack_a);
	rotat(stack_b);
	write(1, "rr\n", 3);
}
