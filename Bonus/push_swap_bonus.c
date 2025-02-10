/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad <sbaghdad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:29:37 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/02/10 17:11:01 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int ac, char **av)
{
	char	*args;
	int		status;
	t_list	*stack_a;
	// t_list	*stack_b;
	
	args = checking_arguments(ac, av);
	if (args == NULL)
	{
		write (2, "Error\n", 7);
		return (1);
	}
	status = handel_this(&stack_a, args);
	if (status == -1)
	{
		write (2, "Error\n", 7);
		return (1);
	}
}
