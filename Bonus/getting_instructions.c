/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getting_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad <sbaghdad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:32:15 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/02/15 15:56:37 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	if (!s1 || !s2)
		return (-1);
	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (-1);
		i++;
	}
	return (1);
}



int	check_instruction(char *line)
{
	if (ft_strcmp(line, "sa\n") == 1)
		return (1);
	else if (ft_strcmp(line, "sb\n") == 1)
		return (1);
	else if (ft_strcmp(line, "ss\n") == 1)
		return (1);
	else if (ft_strcmp(line, "pa\n") == 1)
		return (1);
	else if (ft_strcmp(line, "pb\n") == 1)
		return (1);
	else if (ft_strcmp(line, "ra\n") == 1)
		return (1);
	else if (ft_strcmp(line, "rb\n") == 1)
		return (1);
	else if (ft_strcmp(line, "rr\n") == 1)
		return (1);
	else if (ft_strcmp(line, "rra\n") == 1)
		return (1);
	else if (ft_strcmp(line, "rrb\n") == 1)
		return (1);
	else if (ft_strcmp(line, "rrr\n") == 1)
		return (1);
	else
		return (-1);
}

void	apply_instructions(t_list **stack_a, t_list **stack_b, char *line)
{
	if (ft_strcmp(line, "sa\n") == 1)
		sa (stack_a);
	else if (ft_strcmp(line, "sb\n") == 1)
		sb (stack_b);
	else if (ft_strcmp(line, "ss\n") == 1)
		ss (stack_a, stack_b);
	else if (ft_strcmp(line, "pa\n") == 1)
		pa (stack_a, stack_b);
	else if (ft_strcmp(line, "pb\n") == 1)
		pb (stack_a, stack_b);
	else if (ft_strcmp(line, "ra\n") == 1)
		ra (stack_a);
	else if (ft_strcmp(line, "rb\n") == 1)
		rb (stack_b);
	else if (ft_strcmp(line, "rr\n") == 1)
		rr (stack_a, stack_b);
	else if (ft_strcmp(line, "rra\n") == 1)
		rra (stack_a);
	else if (ft_strcmp(line, "rrb\n") == 1)
		rrb (stack_a);
	else if (ft_strcmp(line, "rrr\n") == 1)
		rrr (stack_a, stack_b);
}