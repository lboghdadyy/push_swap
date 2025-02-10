/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad <sbaghdad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:29:39 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/02/10 15:44:17 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

int	how_many(char *string)
{
	int	count;
	int	index;

	index = 0;
	count = 0;
	while (string[index])
	{
		while (string[index] == 32 && string[index])
			index++;
		if (string[index] && string[index] != 32)
		{
			count++;
			while (string[index] && string[index] != 32)
				index++;
		}
	}
	return (count);
}

int	getting_number(char *string, int *index)
{
	int		index1;
	char	number[20];
	long	value;

	index1 = 0;
	while (string[*index] == 32)
		(*index)++;
	while (string[*index] && string[*index] != 32)
	{
		if (index1 >= 19)
			return (0);
		number[index1++] = string[*index];
		(*index)++;
	}
	number[index1] = '\0';
	value = ft_atoi(number);
	return (value);
}

t_list	*create_linked_list(char *args, int args_count)
{
	int		value;
	t_list	*lst;
	t_list	*tmp;
	int		index;
	int		index1;

	(1) && (index = 0, index1 = 0);
	lst = NULL;
	while (index < args_count)
	{
		value = getting_number(args, &index1);
		if (value > 2147483647 || value < -2147483648)
		{
			write(1, "error\n", 7);
			return (NULL);
		}
		tmp = ft_lstnew(value);
		if (!tmp)
			return (ft_lstclear(&lst), NULL);
		ft_lstadd_back(&lst, tmp);
		index++;
	}
	return (lst);
}

int	handel_this(t_list **stack_a, char	*args)
{
	int		args_count;

	args_count = how_many(args);
	if (args_count == 0)
		return (-1);
	*stack_a = create_linked_list(args, args_count);
	if (duplicate_args(*stack_a) || !stack_a)
		return (ft_lstclear(stack_a), -1);
	return (1);
}
