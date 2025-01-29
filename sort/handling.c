#include "../includes/push_swap.h"

int     how_many(char   *string)
{
	int count;
	int index;

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

int getting_number(char *string, int *index)
{
	int index1 = 0;
	char number[20];
	long value;

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
	return (int)value;
}

t_list  *create_linked_list(char *args, int args_count)
{
	int     value;
	t_list	*lst;
	t_list	*tmp;
	int		index;
	int		index1 = 0;

	index = 0;
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

int	are_they_sorted(t_list *list)
{
	int i;

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

int    handel_this(char    *args)
{
	t_list	*lst;
	int     args_count;

	args_count = how_many(args);
	if (args_count == 0)
		return (-1);
	lst = create_linked_list(args, args_count);
	if(duplicate_args(lst))
		return (-1);
	if (args_count == 2)
	{
		
			sa(&lst);
	}

	else if (args_count == 3)
		sort_three(&lst);
	else if(args_count == 4)
		sort_four(&lst);
	else if(args_count == 5)
		sort_five(&lst);
	return (1);
}