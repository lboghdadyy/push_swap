/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad < sbaghdad@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:33:11 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/02/19 16:34:48 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return (-1);
		s1++;
		s2++;
	}
	return (1);
}

int	ft_check_instruction(char *line)
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

int	get_instructions(t_list **s_a, t_list **s_b)
{
	char	*line;
	t_instr	*instrs;
	t_instr	*tmp;

	instrs = NULL;
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (ft_check_instruction(line) == -1)
		{
			write (2, "Error\n", 6);
			return (free(line), ft_clear_instructions(&instrs), -1);
		}
		tmp = ft_new_instr(line);
		if (!tmp)
			return (ft_clear_instructions(&instrs), free(line), -1);
		add_instruction_back(&instrs, tmp);
	}
	ft_apply_instrcutions(instrs, s_a, s_b);
	return (ft_clear_instructions(&instrs), 1);
}

int	main(int ac, char **av)
{
	char	**args;
	t_list	*stack_a;
	t_list	*stack_b;

	if (ac >= 2)
	{
		(1) && (stack_a = NULL, stack_b = NULL);
		args = ft_checking_arguments(ac, av);
		if (!args)
			return (write (2, "Error\n", 6), 1);
		if (ft_convert(args, &stack_a) == -1)
			return (write (2, "Error\n", 6), 1);
		if (!get_instructions(&stack_a, &stack_b))
			return (ft_lstclear(&stack_a), 1);
		if (!ft_are_they_sorted(stack_a) && !stack_b)
			write(1, "OK\n", 3);
		else
		{
			write(1, "KO\n", 3);
			if (stack_b)
				ft_lstclear(&stack_b);
		}
		ft_lstclear(&stack_a);
	}
}
