/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checking_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad < sbaghdad@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:30:29 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/02/17 10:31:53 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap_bonus.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	next_number_size(char *string, int index)
{
	int	count;

	count = 0;
		
	while (ft_isdigit(string[index]))
	{
		index++;
		count++;
	}
	return (count);
}

int	check_one_arg(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == 32)
			i++;
		else if (ft_isdigit(s[i]))
		{
			if (next_number_size(s, i) > 12)
				return (0);
			i++;
		}
		else if ((s[i] == '-' || s[i] == '+'))
		{
			if (!ft_isdigit(s[i + 1]) || (i > 0 && s[i - 1] != 32))
				return (0);
			i++;
		}
		else
			return (0);
	}
	return (1);
}

int	is_it_empty(char *arg)
{
	int index;
	int	numbers_count;

	index = 0;
	numbers_count = 0;
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

int	check_multi_arguments(char **array)
{
	int index;

	if (!*array)
		return (0);
	index = 0;
	while (array[index])
	{
		if (check_one_arg(array[index]) == 0 || is_it_empty(array[index]))
			return (0);
		index++;
	}
	return (1);
}

char	**checking_arguments(int argc, char **argv)
{
	int		i;
	char	**array;
	char	*args;

	i = 0;
	if (argc == 2)
	{
		array = ft_split(argv[1], ' ');
		if (check_multi_arguments(array) == 0)
			return (free_tab(array), NULL);
	}
	else
	{
		args = ft_strjoin(argc - 1, argv + 1, " ");
		if (!args)
			return (0);
		array = ft_split(args, ' ');
		if (!array)
			return (0);
		if (check_multi_arguments(argv + 1) == 0)
			return (free_tab(array), free(args), NULL);
		free_tab(array);
		array = argv + 1;
		free(args);
	}
	return (array);
}
