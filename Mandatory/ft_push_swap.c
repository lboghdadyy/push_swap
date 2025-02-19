/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad < sbaghdad@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:30:11 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/02/19 17:35:45 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	main(int ac, char **av)
{
	char	**args;
	int		status;
	t_list	*stack_a;
	t_list	*stack_b;

	if (ac >= 2)
	{
		stack_a = NULL;
		stack_b = NULL;
		args = ft_checking_arguments(ac, av);
		if (!args)
		{
			write (2, "Error\n", 6);
			return (1);
		}
		status = ft_pre_sort(args, &stack_a, &stack_b);
		if (status == -1)
		{
			write (2, "Error\n", 6);
			return (1);
		}
	}
}
