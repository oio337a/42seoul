/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 22:45:54 by yongmipa          #+#    #+#             */
/*   Updated: 2022/07/25 22:51:34 by yongmipa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static	char	*ft_free(char *ptr)
{
	free(ptr);
	return (NULL);
}

static char	*read_line(int fd, char *buffer, char *backup)
{
	int		read_size;
	char	*temp;

	read_size = 1;
	while (read_size)
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
	return (backup);
}

static char	*substr_one_line(char *temp)
{
	char	*line;
	int		i;

	if (temp == NULL)
		return (NULL);
	if (temp[0] == '\0')
		return (NULL);
	i = 0;
	while (temp[i] != '\n' && temp[i] != '\0')
		i++;
	line = ft_substr(temp, 0, i + 1);
	return (line);
}

static char	*substr_backup(char *temp, char **line)
{
	char	*backup;
	int		i;

	if (temp == NULL)
		return (NULL);
	if (temp[0] == '\0')
		return (ft_free(temp));
	i = 0;
	while (temp[i] != '\n' && temp[i] != '\0')
		i++;
	if (temp[i] == '\0' || temp[i + 1] == '\0')
		return (ft_free(temp));
	backup = ft_substr(temp, i + 1, ft_strlen(temp) - i - 1);
	if (!backup)
	{
		free(*line);
		*line = NULL;
		return (ft_free(temp));
	}
	free(temp);
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*temp;
	char		*line;
	static char	*backup[OPEN_MAX];

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (!backup[fd])
	{
		backup[fd] = ft_strdup("");
		if (!backup[fd])
			return (ft_free(buffer));
	}
	temp = read_line(fd, buffer, backup[fd]);
	free(buffer);
	line = substr_one_line(temp);
	backup[fd] = substr_backup(temp, &line);
	return (line);
}
