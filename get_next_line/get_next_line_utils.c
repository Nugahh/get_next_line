/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 01:44:59 by fwong             #+#    #+#             */
/*   Updated: 2022/06/13 01:28:14 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *str)
{
	free(str);
	return (NULL);
}

int		ft_is_newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
}

char	*ft_strjoin(char *s1, char *s2);
{
	int		i;
	int		j;
	char	*dest;

	if (!s1)
	{
		s1 = (char *)(malloc(sizeof(char) * 1));
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	dest = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		dest[i++] = s2[j++];
	}
	dest[i] = '\0';
	return (free(s1), dest);
}

char	*ft_get_line(char *str)
{
	size_t	i;
	char	*dest;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	dest = malloc(sizeof(char) * i + 2);
	if (!dest)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		dest[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest); 
}

char	*ft_get_endline(char *str)
{
	size_t	i;
	char	*dest;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	dest = malloc(sizeof(char) * ft_strlen(str) - i + 1)
	if (!dest)
		free(dest);
		return (NULL);
	j = 0;
	while (str[i])
	{
		dest[j] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}