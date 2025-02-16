/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad < sbaghdad@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:30:26 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/02/16 18:17:46 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_tab(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free (str);
}

static size_t	ft_countword(char const *s, char c)
{
	size_t	count;

	if (!*s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

char	**ft_split(char *s, char c)
{
	char	**lst;
	size_t	word_len;
	int		i;
	char	*tmp;

	lst = malloc((ft_countword(s, c) + 1) * sizeof(char *));
	if (!s || !lst)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				word_len = ft_strlen(s);
			else
				word_len = ft_strchr(s, c) - s;
			tmp = ft_substr(s, 0, word_len);
			if (!tmp)
				return (free_tab(lst), NULL);
			lst[i++] = tmp;
			s += word_len;
		}
	}
	lst[i] = NULL;
	return (lst);
}
