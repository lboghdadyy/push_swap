#include "../push_swap.h"

void	free_tab(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static	size_t	count_words(char const *s, char c)
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

static int	ft_check(char *str, char **s)
{
	if (!str)
	{
		free_tab(s);
		return (0);
	}
	return (1);
}

static	size_t	index_it(int i, const char *str, char c)
{
	while (str[i] == c && str[i])
		i++;
	return (i);
}

char	**ft_split(char *s, char c)
{
	char	**str;
	size_t	i;
	size_t	r;
	size_t	j;

	if (!s)
		return (NULL);
	str = (char **)(malloc(sizeof(char *) * (count_words(s, c) + 1)));
	if (!str)
		return (free(str), NULL);
	(1) && (i = 0, j = 0);
	while (s[i])
	{
		i = index_it(i, s, c);
		if (s[i] != c && s[i])
		{
			r = i;
			while (s[i] != c && s[i])
				i++;
			str[j] = ft_substr(s, r, i - r);
			if (!ft_check(str[j++], str))
				return (NULL);
		}
	}
	return (str[j] = NULL, str);
}