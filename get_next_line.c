/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhorbach <rhorbach@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/25 17:28:55 by rhorbach      #+#    #+#                 */
/*   Updated: 2023/01/31 17:17:16 by rhorbach      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//make functions for the found\nline leftover functions
//protect all mallocs
//error handling
//split functions into one reusable

char *append_buffer(char **line_ptr, char *buffer, int buffer_bytes)
{
	int length = ft_strlen(*line_ptr);
	char *dst = malloc((buffer_bytes + length + 1) * sizeof(char));
	if (dst == NULL)
		return (NULL);
	ft_memmove(dst, *line_ptr, length);
	ft_memmove(&dst[length], buffer, buffer_bytes);
	dst[buffer_bytes + length] = '\0';
	free(*line_ptr);
	*line_ptr = dst;
	return (*line_ptr);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE];
	char		*line;
	static char	temp[BUFFER_SIZE];
	int			i;
	int			temp_len;

	temp_len = ft_strlen(temp);
	i = 0;
	while (i < temp_len && temp[i] != '\n')
		i++;
	line = malloc((i + 1) * sizeof(char)); // can return NULL
	// printf("tmp: [%s]\n", temp);
	// printf("i: %i\n", i);
	ft_memmove(line, temp, i);
	line[i] = '\0';
	if (i < temp_len) // found newline
	{
		ft_memmove(temp, &temp[i + 1], temp_len - i - 1);
		temp[temp_len - i - 1] = '\0';

		// above 2 lines are the same as
		// ft_memmove(temp, &temp[i + 1], temp_len - i);

		return (line);
	}
	while (1)
	{
		int bytes_read = read(fd, buffer, BUFFER_SIZE); // can return -1
		if (bytes_read == 0) // EOF
		{
			free(line);
			return (NULL);
		}

		// {
		// 	i = 0;
		// 	while (i < bytes_read)
		// 	{
		// 		if (buffer[i] == '\n')
		// 		{
		// 			ft_memmove(temp, &buffer[i + 1], bytes_read - i - 1);
		// 			temp[bytes_read - i - 1] = '\0';
		// 			return (append_buffer(&line, buffer, i));
		// 		}
		// 		i++;
		// 	}
		// 	append_buffer(&line, buffer, bytes_read); // can return NULL
		// }

		i = 0;
		while (i < bytes_read && buffer[i] != '\n')
			i++;
		if (i < bytes_read)
		{
			ft_memmove(temp, &buffer[i + 1], bytes_read - i - 1);
			temp[bytes_read - i - 1] = '\0';
			return (append_buffer(&line, buffer, i));
		}
		append_buffer(&line, buffer, bytes_read); // can return NULL
	}

	return (line);
}

int	main (void)
{
	int		fd;
	char	*line;

	fd = open("The-Fire-Fades.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("<%s>\n", line);
		free(line);
	}
	printf("<%s>\n", line);
	close(fd);
}




// <hello ><world
// ><test
// t><est2
// b><ye
// a
// b><
// c>

// tmp: \0
// tmp: t\0
// tmp: b\0
// tmp: a\nb\0
// tmp: b\0
