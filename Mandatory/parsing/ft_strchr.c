/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad < sbaghdad@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:06:02 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/02/18 19:10:22 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	while ((*s != '\0') && (*s != c))
	{
		s++;
	}
	if (*s == c)
		return (s);
	return (NULL);
}
