/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shortcuts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad < sbaghdad@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:29:58 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/02/18 18:14:50 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_down_up(t_list **stack_a, t_list **stack_b)
{
	ft_rrb(stack_b);
	ft_ra(stack_a);
}

void	ft_up_down(t_list **stack_a, t_list **stack_b)
{
	ft_rb(stack_b);
	ft_rra(stack_a);
}
