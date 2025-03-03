/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handling.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad < sbaghdad@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:29:39 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/03/02 15:25:04 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_list_size(char **array)
{
	int	index;

	index = 0;
	if (!array)
		return (0);
	while (array[index])
	{
		index++;
	}
	return (index);
}

long long	ft_getting_number(char *string, int *index)
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

t_list	*ft_create_linked_list(char **args, int args_count)
{
	long long	value;
	t_list		*tmp;
	int			index;
	t_list		*lst;

	(1) && (lst = NULL, index = 0);
	if (!args)
		return (NULL);
	while (index < args_count)
	{
		value = ft_atoi(args[index]);
		if (value == 2147483648)
			return (ft_free_tab(args), ft_lstclear(&lst), NULL);
		tmp = ft_lstnew(value);
		if (!tmp)
			return (ft_lstclear(&lst), ft_free_tab(args), NULL);
		ft_lstadd_back(&lst, tmp);
		index++;
	}
	return (lst);
}

int	ft_are_they_sorted(t_list *list)
{
	int	i;

	if (!list)
		return (1);
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

int	ft_pre_sort(char	**args, t_list **stack_a, t_list **stack_b)
{
	int		args_count;

	args_count = ft_list_size(args);
	if (args_count == 0)
		return (ft_free_tab(args), -1);
	*stack_a = ft_create_linked_list(args, args_count);
	if (!*stack_a)
		return (-1);
	if (ft_duplicate_args(*stack_a))
		return (ft_lstclear(stack_a), ft_free_tab(args), -1);
	ft_free_tab(args);
	if (ft_are_they_sorted(*stack_a))
	{
		if (args_count == 2)
			ft_sa(stack_a);
		else if (args_count == 3)
			ft_sort_three(stack_a);
		else if (args_count == 5 || args_count == 4)
			ft_sort_five(stack_a, stack_b);
		else
			ft_big_sort(stack_a, stack_b);
	}
	ft_lstclear(stack_a);
	return (1);
}
