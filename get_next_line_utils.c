/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhorbach <rhorbach@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/25 17:28:50 by rhorbach      #+#    #+#                 */
/*   Updated: 2023/02/07 15:09:45 by rhorbach      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdlib.h>

void	*ft_memmove(void *pdst, const void *psrc, size_t n)
{
	size_t		index;
	char *const	dst = pdst;
	const char	*src = psrc;

	if (dst == NULL && src == NULL)
		return (NULL);
	if (src < dst)
	{
		while (n > 0)
		{
			n--;
			dst[n] = src[n];
		}
		return (dst);
	}
	index = 0;
	while (index < n)
	{
		dst[index] = src[index];
		index++;
	}
	return (dst);
}

ssize_t	ft_strlen(const char *ptr)
{
	ssize_t	counter;

	counter = 0;
	while (ptr[counter] != '\0')
		counter++;
	return (counter);
}

char	*clear(char *line)
{
	free(line);
	return (NULL);
}

char	*empty_string(void)
{
	char	*str;

	str = malloc(1 * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[0] = '\0';
	return (str);
}
