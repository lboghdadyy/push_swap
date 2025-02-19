/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad < sbaghdad@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:37:11 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/02/19 15:47:03 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_instr	*ft_last_instruction(t_instr *lst)
{
	if (!lst)
	{
		return (lst);
	}
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	add_instruction_back(t_instr **alst, t_instr *new)
{
	t_instr	*last;

	if (!alst || !new)
		return ;
	last = ft_last_instruction(*alst);
	if (!last)
	{
		*alst = new;
		return ;
	}
	if (*alst)
		last->next = new;
	else
		*alst = new;
	new->next = NULL;
}

t_instr	*ft_new_instr(char *line)
{
	t_instr	*new;

	new = malloc(sizeof(t_instr));
	if (!new)
		return (NULL);
	new->instr = line;
	new->next = NULL;
	return (new);
}

int	ft_instr_size(t_instr *list)
{
	int	count;

	count = 0;
	if (!list)
		return (-1);
	while (list)
	{
		count++;
		list = list->next;
	}
	return (count);
}

void	ft_clear_instructions(t_instr **lst)
{
	t_instr	*aux;

	if (!*lst)
		return ;
	while (*lst)
	{
		aux = (*lst)->next;
		free ((*lst)->instr);
		free (*lst);
		*lst = aux;
	}
}
