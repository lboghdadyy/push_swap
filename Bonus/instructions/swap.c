/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad <sbaghdad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:30:38 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/02/13 13:29:23 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	swap(t_list **stack)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	tmp2 = (*stack)->next;
	tmp->next = tmp2->next;
	if (tmp2->next)
		tmp2->next->previous = tmp;
	tmp2->previous = NULL;
	tmp2->next = tmp;
	tmp->previous = tmp2;
	*stack = tmp2;
}

void	sa(t_list **stack)
{
	swap(stack);
	write(1, "sa\n", 3);
}

void	sb(t_list **stack)
{
	swap(stack);
	write(1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}
