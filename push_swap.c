/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad <sbaghdad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:30:11 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/02/06 10:30:12 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	main(int ac, char **av)
{
	char	*args;
	int		status;

	args = checking_arguments(ac, av);
	if (args == NULL)
		return (1);
	status = handel_this(args);
	if (status == -1)
	{
		write (2, "Error\n", 7);
		return (1);
	}
}
