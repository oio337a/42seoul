/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 17:37:34 by yongmipa          #+#    #+#             */
/*   Updated: 2023/01/05 16:56:02 by yongmipa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include <unistd.h>

static	char	*ft_free(char *ptr)
{
	free(ptr);
	return (NULL);
}

static char	*read_file(int fd, char *buffer, char *backup)
{
	int		read_size;
	char	*temp;

	while (1)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size == 0)
			break ;
		if (read_size == -1)
			return (ft_free(backup));
		buffer[read_size] = '\0';
		temp = backup;
		backup = ft_strjoin(backup, buffer);
		free(temp);
		if (!backup)
			return (NULL);
		if (ft_strchr(backup, '\n'))
			break ;
	}
	if (backup[0] == '\0')
		return (ft_free(backup));
	free(buffer);
	return (backup);
}

static char	*substring(char **backup)
{
	char	*line;
	char	*temp;
	int		i;

	i = 0;
	while ((*backup)[i] != '\n' && (*backup)[i] != '\0')
		i++;
	line = ft_substr(*backup, 0, i);
	if (line && (*backup)[i] == '\n' && (*backup)[i + 1] != '\0')
	{
		temp = *backup;
		*backup = ft_substr(*backup, i + 1, ft_strlen(*backup) - i - 1);
		free(temp);
		if (!*backup)
			return (ft_free(line));
	}
	else
	{
		free(*backup);
		*backup = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*backup;

	if (!backup)
	{
		backup = ft_strdup("");
		if (!backup)
			return (NULL);
	}
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
	{
		free(backup);
		backup = NULL;
		return (NULL);
	}
	backup = read_file(fd, buffer, backup);
	if (!backup)
		return (ft_free(buffer));
	line = substring(&backup);
	return (line);
}
