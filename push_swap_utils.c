#include "push_swap.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*st;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	st = ft_lstlast(*(lst));
	st->next = new;
	new->next = NULL;
}

void	ft_lstclear(t_list **lst)
{
	t_list	*current;

	if (!lst)
		return ;
	current = *lst;
	while (*lst != NULL)
	{
		*lst = (*lst)->next;
            return ;
        free (lst);
		current = *lst;
	}
	*lst = NULL;
}

t_list	*ft_lstnew(int value)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

t_list *ft_new_lst(char **args, int index)
{
	t_list	*tmp;
	t_list	*lst;
	int		value;

	while (args[index])
	{
		value = ft_atoi(args[index]);
		tmp = ft_lstnew(value);
		if(!tmp)
		{
			ft_lstclear(&lst);
			return (NULL);
		}
		ft_lstadd_back(&lst, tmp);
	}
	return (lst);
}