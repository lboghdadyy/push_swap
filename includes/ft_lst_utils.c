#include "push_swap.h"

t_list	*ft_lstnew(int value)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = value;
	new->next = NULL;
    new->previous = NULL;
	return (new);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstclear(t_list **lst)
{
	t_list *aux;

	if (!*lst)
		return ;
	while (*lst)
	{
		aux = (*lst)->next;
		free (*lst);
		*lst = aux;
	}
	*lst = NULL;
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *last;

	if (!alst || !new)
		return ;
	last = ft_lstlast(*alst);
	if (*alst)
	{
		last->next = new;
		new->previous = last;
	}
	else
	{
		*alst = new;
		new->previous = NULL;
	}
	new->next = NULL;
}