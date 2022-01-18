/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:06:35 by jvigneau          #+#    #+#             */
/*   Updated: 2021/12/14 14:44:17 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

char	*get_next_line(int fd);
int		the_one_that_reads(char **buffer, int fd);
int		len_n_seek(char *str, char to_search);
char	*the_one_that_joins(char *buffer, char *line_read);
void	the_one_that_copies(char **buffer, char **line, int len);
char	*the_one_that_doops(char *buffer);

#endif
