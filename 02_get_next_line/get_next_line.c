/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:12:03 by yongmipa          #+#    #+#             */
/*   Updated: 2022/07/25 18:47:44 by yongmipa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_free(char *ptr)
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
	}
	
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*temp;
	char		*line;
	static char	*backup;

	if (BUFFER_SIZE < 1)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!backup)
	{
		backup = ft_strdup("");
		if (!backup)
			return (NULL);
	}
	temp = read_line(fd, buffer, backup);
	free(buffer);
	line = substr_one_line(temp);
	backup = substr_backup(temp, &line);
	return (line);
}
