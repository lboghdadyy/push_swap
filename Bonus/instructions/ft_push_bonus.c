/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad < sbaghdad@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:30:54 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/02/19 10:52:44 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	push(t_list **stack1, t_list **stack2)
{
	t_list	*tmp;

	if (!stack1 || !(*stack1))
		return ;
	tmp = *stack1;
	*stack1 = (*stack1)->next;
	tmp->next = NULL;
	if (!(*stack2))
		*stack2 = tmp;
	else
	{
		tmp->next = *stack2;
		*stack2 = tmp;
	}
}

void	ft_pa(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_a);
}

void	ft_pb(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
}
