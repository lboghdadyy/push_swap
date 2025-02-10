/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad <sbaghdad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:30:29 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/02/10 20:15:47 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

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
		else if (s[i] == '-' || s[i] == '+')
		{
			if (!ft_isdigit(s[i]) || (s[i - 1] != 32 && s[i - 1]) || !s[i + 1])
				return (0);
			i++;
		}
		else if (ft_isdigit(s[i]))
		{
			if (next_number_size(s, i) > 11)
				return (0);
			i++;
		}
		else
			return (0);
	}
	return (1);
}

char	*checking_arguments(int argc, char **argv)
{
	int		i;
	char	*args;

	i = 0;
	if (argc == 2)
	{
		if (!check_one_arg(argv[1]))
			return (NULL);
		args = argv[1];
	}
	else
	{
		args = ft_strjoin(argc - 1, argv + 1, 32);
		if (!args)
			return (NULL);
		if (!check_one_arg(args))
			return (free(args), NULL);
	}
	return (args);
}

int	duplicate_args(t_list *list)
{
	t_list	*outer;
	t_list	*inner;

	outer = list;
	while (outer)
	{
		inner = outer->next;
		while (inner)
		{
			if (outer->content == inner->content)
				return (1);
			inner = inner->next;
		}
		outer = outer->next;
	}
	return (0);
}
