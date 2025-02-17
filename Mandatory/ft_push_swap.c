/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad < sbaghdad@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:30:11 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/02/17 11:33:06 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	char	**args;
	int		status;
	t_list	*stack_a = NULL;
	t_list	*stack_b = NULL;

	if(ac >= 2)
	{
		args = checking_arguments(ac, av);
		if (!args)
		{
			write (2, "Error\n", 6);
			return (1);
		}
		status = handel_this(args, &stack_a, &stack_b);
		if (status == -1)
		{
			write (2, "Error\n", 6);
			return (1);
		}
	}
}
