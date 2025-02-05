#include "../includes/push_swap.h"

int	get_the_max(t_list *lst)
{
	int	max;

	max = lst->content;
	while (lst)
	{
		if (lst->content > max)
			max = lst->content;
		lst = lst->next;
	}
	return (max);
}

int	get_the_min(t_list *list)
{
	int	min;

	min = list->content;
	list = list->next;
	while (list)
	{
		if (list->content < min)
			min = list->content;
		list = list->next;
	}
	return (min);
}
