/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad < sbaghdad@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:30:54 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/02/17 10:31:25 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap_bonus.h"

void	push(t_list **stack1, t_list **stack2)
{
	t_list	*tmp;
	
	if (!stack1 || !stack2)
		return ;
	tmp = *stack1;
	*stack1 = (*stack1)->next;
	tmp->next = *stack2;
	*stack2 = tmp;
}


void	pa(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_a);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
}
