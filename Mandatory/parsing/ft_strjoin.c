/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad < sbaghdad@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:30:22 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/02/16 19:13:11 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#include <stdio.h>
char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	while ((*s != '\0') && (*s != c))
	{
		s++;
	}
	if (*s == c)
		return (s);
	return (NULL);
}

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

char	*ft_strcat(char *dest, char	*src)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (dest[count] != '\0')
		count++;
	while (src[i] != '\0')
	{
		dest[count + i] = src[i];
		i++;
	}
	dest[count + i] = '\0';
	return (dest);
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