/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 09:27:32 by jvigneau          #+#    #+#             */
/*   Updated: 2022/02/15 18:51:50 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <stdlib.h>
# define BUFFER_SIZE 1

char	*get_next_line(int fd);
int		the_one_that_reads(char **buffer, int fd);
int		len_n_search(char *str, char to_search);
char	*the_one_that_joins(char *buffer, char *temp_buffer);
void	the_one_that_copies(char **buffer, char **final_line, int len);
char	*the_one_that_doops(char *buffer);

#endif