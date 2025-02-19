/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad < sbaghdad@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:30:26 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/02/18 18:56:33 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_free_tab(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str && str[i])
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

size_t	word_len(char *s, char c)
{
	size_t	word_len;

	if (!ft_strchr(s, c))
		word_len = ft_strlen(s);
	else
		word_len = ft_strchr(s, c) - s;
	return (word_len);
}

char	**ft_split(char *s, char c)
{
	char	**lst;
	size_t	word_lenght;
	int		i;
	char	*tmp;

	(1) && (i = 0, lst = malloc((ft_countword(s, c) + 1) * sizeof(char *)));
	if (!s || !lst)
		return (0);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			word_lenght = word_len(s, c);
			tmp = ft_substr(s, 0, word_lenght);
			if (!tmp)
				return (ft_free_tab(lst), NULL);
			lst[i++] = tmp;
			s += word_lenght;
		}
	}
	lst[i] = NULL;
	return (lst);
}
