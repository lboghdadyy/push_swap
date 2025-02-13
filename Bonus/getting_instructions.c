/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getting_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad <sbaghdad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:32:15 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/02/13 13:39:40 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

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
	if (!ft_strcmp(line, "sa\n"))
		return (1);
	else if (!ft_strcmp(line, "sb\n"))
		return (1);
	else if (!ft_strcmp(line, "ss\n"))
		return (1);
	else if (!ft_strcmp(line, "pa\n"))
		return (1);
	else if (!ft_strcmp(line, "pb\n"))
		return (1);
	else if (!ft_strcmp(line, "ra\n"))
		return (1);
	else if (!ft_strcmp(line, "rb\n"))
		return (1);
	else if (!ft_strcmp(line, "rr\n"))
		return (1);
	else if (!ft_strcmp(line, "rra\n"))
		return (1);
	else if (!ft_strcmp(line, "rrb\n"))
		return (1);
	else if (!ft_strcmp(line, "rrr\n"))
		return (1);
	else
		return (-1);
}

void	apply_instructions(t_list **stack_a, t_list **stack_b, char *line)
{
	if (!ft_strcmp(line, "sa\n"))
		sa (stack_a);
	else if (!ft_strcmp(line, "sb\n"))
		sb (stack_b);
	else if (!ft_strcmp(line, "ss\n"))
		ss (stack_a, stack_b);
	else if (!ft_strcmp(line, "pa\n"))
		pa (stack_a, stack_b);
	else if (!ft_strcmp(line, "pb\n"))
		pb (stack_a, stack_b);
	else if (!ft_strcmp(line, "ra\n"))
		ra (stack_a);
	else if (!ft_strcmp(line, "rb\n"))
		rb (stack_b);
	else if (!ft_strcmp(line, "rr\n"))
		rr (stack_a, stack_b);
	else if (!ft_strcmp(line, "rra\n"))
		rra (stack_a);
	else if (!ft_strcmp(line, "rrb\n"))
		rrb (stack_a);
	else if (!ft_strcmp(line, "rrr\n"))
		rrr (stack_a, stack_b);
}


int	getting_instructions(t_list **s_a, t_list **s_b, char *line, char **ins)
{
	static  int index;
	char		*tmp;

	if (!line || !ins)
		return (-1);
	tmp = ft_strdup(line);
	if (!tmp)
		return (-1);
	if (!check_instruction(line))
		return (free_tab(ins), -1);
	ins[index] = tmp;
	apply_instructions(s_a, s_b, line);
	index++;
	return (1);
}