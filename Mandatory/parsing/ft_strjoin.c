/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad < sbaghdad@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:30:22 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/02/18 19:08:06 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

size_t	ft_whole_size(char **array, int size)
{
	int		index;
	size_t	count;

	count = 0;
	index = 0;
	if (!array)
		return (0);
	while (index < size)
	{
		count += ft_strlen(array[index]) + 1;
		index++;
	}
	return (count);
}

int	ft_contains_number(char *s)
{
	int	index;

	index = 0;
	while (s[index])
	{
		while (s[index] == 32 && s[index])
			index++;
		if (!ft_strchr("0123456789+-", s[index]) || !s[index])
		{
			return (0);
		}
		index++;
	}	
	return (1);
}

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
	int	i;
	int	l;

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
	i = 1;
	if (size <= 0)
		return (NULL);
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
