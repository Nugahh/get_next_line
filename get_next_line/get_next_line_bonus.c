/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 01:24:20 by fwong             #+#    #+#             */
/*   Updated: 2022/06/19 14:25:28 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*cache[1024];
	char		*line;
	ssize_t		red;

	if (BUFFER_SIZE <= 0 || (fd < 0 && fd > 1024))
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	red = 1;
	while (red != 0 && !ft_is_newline(cache[fd]))
	{
		red = read(fd, buffer, BUFFER_SIZE);
		if (red == 0 && cache[fd] == NULL)
			return (free(buffer), NULL);
		if (red == -1)
			return (free(cache[fd]), free(buffer), NULL);
		buffer[red] = '\0';
		cache[fd] = ft_strjoin(cache[fd], buffer);
	}
	line = ft_get_line(cache[fd]);
	cache[fd] = ft_get_endline(cache[fd]);
	return (free(buffer), line);
}
