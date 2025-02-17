/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shortcuts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad < sbaghdad@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:29:58 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/02/17 23:43:46 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	down_up(t_list **stack_a, t_list **stack_b)
{
	rrb(stack_b);
	ra(stack_a);
}

void	up_down(t_list **stack_a, t_list **stack_b)
{
	rb(stack_b);
	rra(stack_a);
}