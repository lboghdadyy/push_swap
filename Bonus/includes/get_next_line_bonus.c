/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad < sbaghdad@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 19:37:47 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/02/19 12:12:23 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

char	*get_it(int fd, char *readed)
{
	char	*buffer;
	int		bytes;
	char	*tmp;

	bytes = 1;
	while (!ft_strchr(readed, '\n'))
	{
		buffer = malloc(2);
		if (!buffer)
			return (free(readed), NULL);
		bytes = read(fd, buffer, 1);
		if (bytes == 0 && readed)
			return (free(buffer), readed);
		else if ((bytes == 0 && !readed) || bytes == -1)
			return (free(buffer), free(readed), NULL);
		buffer[bytes] = '\0';
		tmp = ft_strjoin_gnl(readed, buffer);
		free (readed);
		free (buffer);
		readed = tmp;
	}
	return (readed);
}

char	*get_next_line(int fd)
{
	char		*line;

	if (fd > 1024 || fd < 0)
		return (NULL);
	line = NULL;
	line = get_it(fd, line);
	if (!line)
		return (NULL);
	return (line);
}
