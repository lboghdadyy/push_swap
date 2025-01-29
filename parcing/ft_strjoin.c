#include "../includes/push_swap.h"

char	*ft_strjoin(int size, char **strs, char sep)
{
	char	*s;
	int		i;
	int		j;
	int		c;

	s = malloc(sizeof(strs));
	i = 0;
	c = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			s[c++] = strs[i][j++];
		}
		s[c++] = sep;
		i++;
	}
	s[c] = '\0';
	return (s);
}