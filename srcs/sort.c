#include "../push_swap.h"

int		ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*temp;

	count = 0;
	temp = (t_list*)lst;
	while (temp)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

void    sort_it(t_list  **list)
{
    int     len;

    len = ft_lstsize(*list);
    if (len == 3)
        sort_three(*list);
    if (len == 5)
        sort_five(*list);
}