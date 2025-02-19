/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_instr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad < sbaghdad@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:16:12 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/02/19 16:31:45 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_execute_instr(t_list **stack_a, t_list **stack_b, char *line)
{
	if (ft_strcmp(line, "sa\n") == 1)
		ft_sa (stack_a);
	else if (ft_strcmp(line, "sb\n") == 1)
		ft_sb (stack_b);
	else if (ft_strcmp(line, "ss\n") == 1)
		ft_ss (stack_a, stack_b);
	else if (ft_strcmp(line, "pa\n") == 1)
		ft_pa (stack_a, stack_b);
	else if (ft_strcmp(line, "pb\n") == 1)
		ft_pb (stack_a, stack_b);
	else if (ft_strcmp(line, "ra\n") == 1)
		ft_ra (stack_a);
	else if (ft_strcmp(line, "rb\n") == 1)
		ft_rb (stack_b);
	else if (ft_strcmp(line, "rr\n") == 1)
		ft_rr (stack_a, stack_b);
	else if (ft_strcmp(line, "rra\n") == 1)
		ft_rra (stack_a);
	else if (ft_strcmp(line, "rrb\n") == 1)
		ft_rrb (stack_b);
	else if (ft_strcmp(line, "rrr\n") == 1)
		ft_rrr (stack_a, stack_b);
}

void	ft_apply_instrcutions(t_instr *instrs, t_list **s_a, t_list **s_b)
{
	t_instr	*tmp;

	tmp = instrs;
	while (tmp)
	{
		ft_execute_instr(s_a, s_b, tmp->instr);
		tmp = tmp->next;
	}
}
