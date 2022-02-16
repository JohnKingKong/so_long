/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 09:27:32 by jvigneau          #+#    #+#             */
/*   Updated: 2021/12/10 09:27:32 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	the_one_that_reads(char **buffer, int fd)
{
	int		len_read;
	char	*temp_buffer;

	while (!*buffer || !len_n_search(*buffer, '\n'))
	{
		temp_buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!temp_buffer)
			return (0);
		len_read = read(fd, temp_buffer, BUFFER_SIZE);
		if (len_read <= 0)
		{
			free(temp_buffer);
			return (0);
		}
		temp_buffer[len_read] = '\0';
		*buffer = the_one_that_joins(*buffer, temp_buffer);
		free(temp_buffer);
	}
	return (len_n_search(*buffer, '\n'));
}

int	len_n_search(char *str, char to_search)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] && str[len] != to_search)
		len++;
	if (!to_search)
		return (len);
	if (str[len] != to_search)
		return (0);
	else
		return (len + 1);
}

char	*the_one_that_joins(char *buffer, char *temp_buffer)
{
	int		i;
	int		j;
	int		len;
	char	*new_buffer;

	i = 0;
	j = 0;
	len = len_n_search(buffer, 0) + len_n_search(temp_buffer, 0);
	new_buffer = malloc(sizeof(char) * len + 1);
	if (!new_buffer)
		return (0);
	while (buffer && buffer[i])
	{
		new_buffer[i] = buffer[i];
		i++;
	}
	free(buffer);
	while (temp_buffer[j])
	{
		new_buffer[i] = temp_buffer[j];
		i++;
		j++;
	}
	new_buffer[i] = '\0';
	return (new_buffer);
}

void	the_one_that_copies(char **buffer, char **final_line, int len)
{
	int		i;
	char	*new_buffer;

	i = 0;
	while (i < len)
	{
		(*final_line)[i] = (*buffer)[i];
		i++;
	}
	(*final_line)[i] = '\0';
	if (!len_n_search(*buffer, '\n'))
	{
		free(*buffer);
		*buffer = NULL;
	}
	else
	{
		new_buffer = the_one_that_doops(&(*buffer)[len]);
		free(*buffer);
		*buffer = new_buffer;
	}
}

char	*the_one_that_doops(char *buffer)
{
	char	*new_buffer;
	int		i;
	int		len;

	i = 0;
	len = len_n_search(buffer, 0);
	new_buffer = malloc(sizeof(char) * len + 1);
	if (!new_buffer)
		return (0);
	while (buffer[i])
	{
		new_buffer[i] = buffer[i];
		i++;
	}
	new_buffer[i] = '\0';
	return (new_buffer);
}
