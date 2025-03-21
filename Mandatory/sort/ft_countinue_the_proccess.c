/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countinue_the_proccess.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad < sbaghdad@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:29:33 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/02/18 18:21:18 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h" 

void	ft_cont_the_proc(int i, int t, t_list **s_a, t_list **s_b)
{
	if ((*s_b)->index != i)
	{
		while ((*s_b)->index != i)
		{
			if (ft_index_st(*s_b, i))
				ft_rrb(s_b);
			else
				ft_rb(s_b);
		}
	}
	if ((*s_a)->index != t)
	{
		while ((*s_a)->index != t)
		{
			if (ft_index_st(*s_a, t))
				ft_rra(s_a);
			else
				ft_ra(s_a);
		}
	}
}
