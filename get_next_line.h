/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhorbach <rhorbach@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/25 17:28:57 by rhorbach      #+#    #+#                 */
/*   Updated: 2023/02/20 17:35:15 by rhorbach      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef enum e_nl_found {
	ERROR,
	NL_NOT_FOUND,
	NL_FOUND
}	t_nl_found;

char	*get_next_line(int fd);
void	*ft_memmove(void *pdst, const void *psrc, size_t n);
ssize_t	ft_strlen(const char *ptr);
char	*clear(char *line);
char	*empty_string(void);

#endif
