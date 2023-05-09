/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:09:44 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/05/09 15:13:23 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

//get_line
char	*get_line(int fd, char *buffer, char *relic, int *read_byte)
{
	char	*tmp;

	*read_byte = 1;
	//printf("")
	while (*read_byte > 0 && (!relic || !ft_strchr(relic, '\n')))
	{
		*read_byte = read(fd, buffer, BUFFER_SIZE);
		if (*read_byte == -1)
			return (0x0);
		buffer[*read_byte] = '\0';
		if (!relic)
			relic = ft_strdup("");
		tmp = relic;
		relic = ft_strjoin(relic, buffer);
		free(tmp);
		tmp = 0x0;
		if (ft_strchr(buffer, '\n') || !*read_byte)
			break;
	}
	return (relic);
}

//get_relic

char	*get_relic(char *line)
{
	char	*relic;
	int		pos;

	//search for \n, (trucate line ?) and put the tail in relic
	pos = 0;
	while (line[pos] && line[pos] != '\n')
		pos++;
	if (!pos && !line[pos])
		return (0x0);
	relic = ft_substr(line, pos + 1, BUFFER_SIZE + 1);
	if (line[pos])
		line[pos + 1] = '\0';
	return (relic);
}

void	free_all(void *buffer, void *line, void *relic)
{
	if (buffer)
		free(buffer);
	if (line)
		free(line);
	if (relic)
		free(relic);
}

char	*get_next_line(int fd)
{
	static char	*relic;
	char		*line;
	char		*buffer;
	int		read_byte;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0x0);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0x0);
	line = get_line(fd, buffer, relic, &read_byte);
	if (!line)
	{
		free_all(buffer, line, relic);
		return (0x0);
	}
	relic = get_relic(line);
	if (!read_byte && !relic)   //not sure it always works
	{
		free_all(buffer, line, relic);
		return (0x0);
	}
	free_all(buffer, 0x0, 0x0);
	return (line);
}

