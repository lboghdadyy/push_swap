/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checking.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad < sbaghdad@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:30:29 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/03/02 13:17:04 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_check_one_arg(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == 32)
			i++;
		else if (ft_isdigit(s[i]) && s[i])
			i++;
		else if ((s[i] == '-' || s[i] == '+') && s[i])
		{
			if ((!ft_isdigit(s[i + 1]) || (i > 0 && s[i - 1] != 32)) && s[i])
				return (0);
			i++;
		}
		else
			return (0);
	}
	return (1);
}

int	ft_is_it_empty(char *arg)
{
	int	index;
	int	numbers_count;

	index = 0;
	numbers_count = 0;
	if (!arg)
		return (1);
	while (arg[index])
	{
		if (ft_isdigit(arg[index]))
			numbers_count++;
		index++;
	}
	if (numbers_count != 0)
		return (0);
	else
		return (1);
}

int	ft_check_multi_arguments(char **array)
{
	int	index;

	if (!array || !*array)
		return (0);
	index = 0;
	while (array[index])
	{
		if (ft_check_one_arg(array[index]) == 0 || ft_is_it_empty(array[index]))
			return (0);
		index++;
	}
	return (1);
}

char	**ft_checking_arguments(int argc, char **argv)
{
	int		i;
	char	**array;
	char	*args;

	i = 0;
	if (argc == 2)
	{
		array = ft_split(argv[1], ' ');
		if (ft_check_multi_arguments(array) == 0)
			return (ft_free_tab(array), NULL);
	}
	else
	{
		if (ft_check_multi_arguments(argv + 1) == 0)
			return (0);
		args = ft_strjoin(argc - 1, argv + 1, " ");
		if (!args)
			return (NULL);
		array = ft_split(args, ' ');
		if (!array)
			return (free(args), NULL);
		free(args);
	}
	return (array);
}
