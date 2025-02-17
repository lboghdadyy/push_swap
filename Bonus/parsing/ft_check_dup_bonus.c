/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dup_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad < sbaghdad@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:33:36 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/02/17 10:31:47 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap_bonus.h"

int	duplicate_args(t_list *list)
{
	t_list	*outer;
	t_list	*inner;

	outer = list;
	while (outer)
	{
		inner = outer->next;
		while (inner)
		{
			if (outer->content == inner->content)
				return (1);
			inner = inner->next;
		}
		outer = outer->next;
	}
	return (0);
}
