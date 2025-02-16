/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handling.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad < sbaghdad@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:29:39 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/02/16 20:01:35 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_list_size(char **array)
{
	int	index;

	index = 0;
	while (array[index])
	{
		index++;
	}
	return (index);
}

long long	getting_number(char *string, int *index)
{
	int			index1;
	char		number[30];
	long long	value;

	index1 = 0;
	while (string[*index] == 32)
		(*index)++;
	while (string[*index] && string[*index] != 32)
	{
		number[index1++] = string[*index];
		(*index)++;
	}
	number[index1] = '\0';
	value = ft_atoi(number);
	return (value);
}

t_list	*create_linked_list(char **args ,int args_count)
{
	long long	value;
	t_list		*tmp;
	int			index;
	t_list		*lst;

	lst = NULL;
	index = 0;
	while (index < args_count)
	{
		value = ft_atoi(args[index]);
		if (value < -2147483648 || value > 2147483647)
			return (NULL);
		tmp = ft_lstnew(value);
		if (!tmp)
			return (ft_lstclear(&lst), NULL);
		ft_lstadd_back(&lst, tmp);
		index++;
	}
	return (lst);
}

int	are_they_sorted(t_list *list)
{
	int	i;

	i = list->content;
	list = list->next;
	while (list)
	{
		if (i > list->content)
			return (1);
		else
			i = list->content;
		list = list->next;
	}
	return (0);
}

int	handel_this(char	**args, t_list **stack_a, t_list **stack_b)
{
	int		args_count;

	args_count = ft_list_size(args);
	if (args_count == 0)
		return (-1);
	*stack_a = create_linked_list(args, args_count);
	if (!*stack_a)
		return (-1);
	if (duplicate_args(*stack_a))
		return (ft_lstclear(stack_a), -1);
	if (are_they_sorted(*stack_a))
	{
		if (args_count == 2)
			sa(stack_a);
		else if (args_count == 3)
			sort_three(stack_a);
		else if (args_count == 4)
			sort_four(stack_a, stack_b);
		else if (args_count == 5)
			sort_five(stack_a, stack_b);
		else
			just_sort(stack_a, stack_b);
	}
	ft_lstclear(stack_a);
	return (1);
}
