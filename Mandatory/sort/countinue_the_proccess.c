/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countinue_the_proccess.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad <sbaghdad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:29:33 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/02/06 10:29:34 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h" 

void	cont_the_proc(int i, int t, t_list **s_a, t_list **s_b)
{
	if ((*s_b)->index != i)
	{
		while ((*s_b)->index != i)
		{
			if (status_index(*s_b, i))
				rrb(s_b);
			else
				rb(s_b);
		}
	}
	if ((*s_a)->index != t)
	{
		while ((*s_a)->index != t)
		{
			if (status_index(*s_a, t))
				rra(s_a);
			else
				ra(s_a);
		}
	}
}
