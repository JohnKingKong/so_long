/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:53:16 by jvigneau          #+#    #+#             */
/*   Updated: 2022/01/15 16:36:21 by jvigneau         ###   ########          */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*get_next_line(int fd)
{
	static char	*buffer[26000];
	char		*line_read;
	int			len;

	if (fd < 0 || fd > 26000)
		return (NULL);
	len = the_one_that_reads(&buffer[fd], fd);
	if (!len)
		len = len_n_seek(buffer[fd], '\0');
	if (!len)
	{
		free(buffer[fd]);
		return (NULL);
	}
	line_read = malloc(sizeof(char) * len + 1);
	if (!line_read)
		return (NULL);
	the_one_that_copies(&buffer[fd], &line_read, len);
	return (line_read);
}
