/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad <sbaghdad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:29:37 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/02/13 22:50:20 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	char	*args;
	char	*line;
	char	**instructions;
	t_list	*stack_a;
	t_list	*stack_b = NULL;
	
	if (ac >= 2)
	{
		args = checking_arguments(ac, av);
		if (args == NULL)
		{
			write (2, "Error\n", 7);
			return (1);
		}
		if (handel_this(&stack_a, args) == -1)
		{
			write (2, "Error\n", 7);
			return (1);
		}
		instructions = malloc(sizeof(char *) * 5500);
		if (!instructions)
			return (free(args), 1);
		while (1)
		{
			line = get_next_line(0);
			
			if(!line)
				break;
			printf("%s", line);
			if (getting_instructions(&stack_a, &stack_a, line, instructions) == -1)
			{
				write (2, "Error\n", 7);
				return (free_tab(instructions), ft_lstclear(&stack_a), ft_lstclear(&stack_b), 1);
			}
		}
		// printf("are they sorted --> %d", are_they_sorted(&stack_a));
		// if (are_they_sorted(&stack_a) == 1 && ft_lstsize(stack_b) == 0)
		// 	write(1, "OK\n", 3);
		// else
		// 	write(1, "KO\n", 3);	
	}
	return (0);
}
