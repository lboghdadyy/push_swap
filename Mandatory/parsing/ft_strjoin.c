/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad < sbaghdad@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:30:22 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/02/19 18:16:29 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

size_t	ft_strlen(char	*str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_length(char **str, char *sep, int size)
{
	int		i;
	size_t	l;

	i = 0;
	l = 0;
	while (i < size)
	{
		l += ft_strlen(str[i]);
		i++;
	}
	l += ft_strlen(sep) * (size - 1);
	return (l);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		i;

	str = NULL;
	i = 0;
	if (size <= 0)
	{
		str = malloc(sizeof(char) * 1);
		*str = '\0';
		return (str);
	}
	str = malloc(sizeof(char) * ft_length(strs, sep, size) + 1);
	if (!str)
		return (str);
	str[i] = '\0';
	while (i < size)
	{
		ft_strcat(str, strs[i]);
		if (i < size - 1)
			ft_strcat(str, sep);
		i++;
	}
	return (str);
}
