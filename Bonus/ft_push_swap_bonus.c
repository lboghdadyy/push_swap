/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad < sbaghdad@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:29:37 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/02/17 11:05:02 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap_bonus.h"
#include <stdio.h>

void print_list(t_list *head) {
    t_list *current = head;
	if (!head)
		printf("hmm kaya\n");
    while (current) {
        printf("Content: %d,\n",current->content);
        current = current->next;
    }
}

void print_instructions(t_instructions *head) {
    t_instructions *current = head;
    while (current) {
        printf("instructions ---> %s\n", current->instr);
        current = current->next;
    }
}

int	main(int ac, char **av)
{
	char	**args;
	int		status;
	t_list	*stack_a = NULL;
	t_list	*stack_b = NULL;
	t_instructions *instructions = NULL;
	t_instructions	*tmp = NULL;
	char			*line;

	if(ac >= 2)
	{
		args = checking_arguments(ac, av);
		if (!args)
		{
			write (2, "Error\n", 7);
			return (1);
		}
		status = handel_this(args, &stack_a);
		if (status == -1)
		{
			write (2, "Error\n", 7);
			return (1);
		}
		while (1)
		{
			line = get_next_line(0);
			if (!line)
				break;
			if (check_instruction(line) == -1)
			{
				write (2, "Error\n", 6);
				return (ft_clear_instructions(&instructions),1);
			}
			tmp = ft_new_instr(line);
			if(!tmp)
				return (ft_lstclear(&stack_a), ft_clear_instructions(&instructions), 1);
			add_instruction_back(&instructions, tmp);
		}
		printf("list size ---> %d\n", ft_instr_size(instructions));
		while (instructions->next)
		{
			printf("instrr ----> {%s\n", instructions->instr);
			apply_instructions(&stack_a, &stack_b, instructions->instr);
			instructions = instructions->next;
		}
		ft_clear_instructions(&instructions);
		print_list(stack_a);
		if (are_they_sorted(stack_a) != -1 && !stack_b)
		{
			write(1, "OK\n", 3);
			// ft_free_stack(a);
		}
		else
		{
			write(1, "KO\n", 3);
			// ft_free_stack(b);
			// ft_free_stack(a);
		}
	}
	return (0);
}
