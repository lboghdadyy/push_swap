/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_lst_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad <sbaghdad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:05:30 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/02/15 15:49:12 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

t_instructions	*ft_last_instruction(t_instructions *lst)
{
    if (!lst)
    {
        // printf("hh\n");
        return (NULL);
    }
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void    add_instruction_back(t_instructions **alst, t_instructions *new)
{
    t_instructions	*last;

	if (!alst || !new)
		return ;
	last = ft_last_instruction(*alst);
	if (*alst)
		last->next = new;
	else
		*alst = new;
	new->next = NULL;
}

t_instructions	*ft_new_instr(char *line)
{
	t_instructions	*new;

	new = malloc(sizeof(t_instructions));
	if (!new)
		return (NULL);
	new->instr = line;
	new->next = NULL;
	return (new);
}

int	ft_instr_size(t_instructions *list)
{
	int count = 0;

	if (!list)
		return (-1);
	while (list)
	{
		count++;
		list = list->next;
	}
	return (count);
}

void	ft_clear_instructions(t_instructions **lst)
{
	t_instructions	*aux;

	if (!*lst)
		return ;
	while (*lst)
	{
		aux = (*lst)->next;
        free ((*lst)->instr);
		free (*lst);
		*lst = aux;
	}
	*lst = NULL;
}