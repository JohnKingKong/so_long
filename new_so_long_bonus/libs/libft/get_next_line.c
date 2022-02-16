/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 09:27:32 by jvigneau          #+#    #+#             */
/*   Updated: 2021/12/10 09:27:32 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*final_line;
	int			len;

	if (fd < 0 || fd > OPEN_MAX)
		return (NULL);
	len = the_one_that_reads(&buffer[fd], fd);
	if (!len)
		len = len_n_search(buffer[fd], '\0');
	if (!len)
	{
		free(buffer[fd]);
		return (NULL);
	}
	final_line = malloc(sizeof(char) * len + 1);
	if (!final_line)
		return (NULL);
	the_one_that_copies(&buffer[fd], &final_line, len);
	return (final_line);
}
