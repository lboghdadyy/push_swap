/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad < sbaghdad@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:27:24 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/02/17 10:32:23 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap_bonus.h"

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
		i++;
	}
	return (number * sign);
}
