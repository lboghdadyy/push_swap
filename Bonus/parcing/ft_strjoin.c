/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad <sbaghdad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:30:22 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/02/10 17:11:11 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad <sbaghdad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:30:22 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/02/10 17:01:30 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

char	*ft_strchr(char *s, int c)
{
	while ((*s != '\0') && (*s != c))
	{
		s++;
	}
	if (*s == c)
	{
		return ((char *)s);
	}
	return (NULL);
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
			return (0);
		index++;
	}	
	return (1);
}

char	*ft_strjoin(int size, char **strs, char sep)
{
	char	*s;
	int		i;
	int		j;
	int		c;

	if (!strs)
		return (NULL);
	s = malloc(sizeof(strs));
	if (!s)
		return (NULL);
	(1) && (i = 0, c = 0);
	while (i < size)
	{
		j = 0;
		if (strs[i][0] == '\0' || !ft_contains_number(strs[i]))
			return (free(s), NULL);
		while (strs[i][j] != '\0')
			s[c++] = strs[i][j++];
		s[c++] = sep;
		i++;
	}
	s[c] = '\0';
	return (s);
}
