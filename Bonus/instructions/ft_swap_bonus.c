/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad < sbaghdad@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:30:38 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/02/19 10:53:02 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	ft_swap(t_list **stack)
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

void	ft_sa(t_list **stack)
{
	ft_swap(stack);
}

void	ft_sb(t_list **stack)
{
	ft_swap(stack);
}

void	ft_ss(t_list **stack_a, t_list **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
}
