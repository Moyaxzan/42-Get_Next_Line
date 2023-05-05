/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:09:44 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/05/05 23:55:17 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//get_line
char	*get_line(int fd, char *buffer, char *relic)
{
	int		read_byte;
	char	*tmp;

	read_byte = 1;
	while (read_byte > 0)
	{
		read_byte = read(fd, buffer, BUFFER_SIZE);
		if (read_byte == -1)
			return (0x0);
		buffer[read_byte] = '\0';
		if (!relic)
			relic = ft_strdup("");
		tmp = relic;
		relic = ft_strjoin(relic, buffer);
		free(tmp);
		tmp = 0x0;
		if (ft_strchr(buffer, '\n') || !read_byte)
			break;
	}
	return (relic);
}

//get_relic

char	*get_relic(char *line)
{
	char	*relic;

	//search for \n, (trucate line ?) and put the tail in relic
}

char	*get_next_line(int fd)
{
	static char	*relic;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0x0);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0x0);
	line = get_line(fd, buffer, relic);
	if (!line)
		return (0x0);
	relic = get_relic(line);
}

