/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 01:24:20 by fwong             #+#    #+#             */
/*   Updated: 2022/06/19 14:25:23 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*cache;
	char		*line;
	ssize_t		red;

	if (BUFFER_SIZE <= 0 || (fd < 0 && fd > 1024))
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	red = 1;
	while (red != 0 && !ft_is_newline(cache))
	{
		red = read(fd, buffer, BUFFER_SIZE);
		if (red == 0 && cache == NULL)
			return (free(buffer), NULL);
		if (red == -1)
			return (free(cache), free(buffer), NULL);
		buffer[red] = '\0';
		cache = ft_strjoin(cache, buffer);
	}
	line = ft_get_line(cache);
	cache = ft_get_endline(cache);
	return (free(buffer), line);
}
