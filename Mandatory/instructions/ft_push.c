/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad < sbaghdad@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:30:54 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/02/24 10:03:40 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_list **stack1, t_list **stack2)
{
	t_list	*tmp;

	if (!stack1 || !(*stack1) || !stack2)
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
	write(1, "pa\n", 3);
}

void	ft_pb(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
}
