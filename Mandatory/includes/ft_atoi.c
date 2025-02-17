/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad < sbaghdad@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:27:24 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/02/17 11:10:09 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	ft_atoi(char *s)
{
	long	number;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	number = 0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		number = (number * 10) + (s[i] - 48);
		if (number * sign > 2147483647
			|| number * sign  < -2147483648)
			return (2147483648);
		i++;
	}
	return (number * sign);
}
