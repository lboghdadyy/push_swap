/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad < sbaghdad@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:30:38 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/02/17 10:31:36 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap_bonus.h"

void	swap(t_list **stack)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	tmp2 = (*stack)->next;
	tmp->next = tmp2->next;
	tmp2->next = tmp;
	*stack = tmp2;
}

void	sa(t_list **stack)
{
	swap(stack);
}

void	sb(t_list **stack)
{
	swap(stack);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}
