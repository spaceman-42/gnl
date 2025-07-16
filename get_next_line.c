/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadiaz-b <jadiaz-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:52:33 by jadiaz-b          #+#    #+#             */
/*   Updated: 2025/02/25 18:12:27 by jadiaz-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*write_buffer(char *line, int *length)
{
	char	*stash;
	size_t	len;

	len = 0;
	while (line[len] && line[len] != '\n')
		len++;
	len++;
	stash = (char *)malloc((len + 1) * sizeof(char));
	if (!stash)
		return (NULL);
	ft_memcpy(stash, line, len);
	stash[len] = '\0';
	if (len > 0 && stash[len - 1] == '\n')
		*length = len - 1;
	return (stash);
}

size_t	ft_strget(char *line)
{
	size_t	i;

	i = -1;
	if (!line)
		return (-1);
	while (++i < BUFFER_SIZE)
	{
		if (line[i] == '\n' || line[i] == '\0')
			return (i + 1);
	}
	return (i);
}

char	*ft_newline(char *line, char *stash, int *locate, int fd)
{
	ssize_t	read_bytes;
	size_t	line_len;
	char	buffer[BUFFER_SIZE + 1];

	while (*locate == -1)
	{
		ft_bzero(buffer, (BUFFER_SIZE + 1));
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(line);
			ft_bzero(stash, (BUFFER_SIZE + 1));
			return (NULL);
		}
		line_len = ft_strget(buffer);
		ft_strlcpy(stash, &buffer[line_len], (BUFFER_SIZE + 1));
		buffer[line_len] = '\0';
		line = ft_strjoin(line, buffer, locate);
		if (read_bytes == 0)
		{
			ft_bzero(stash, BUFFER_SIZE + 1);
			break ;
		}
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			bytes_line;	

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_line = -1;
	line = write_buffer(buffer, &bytes_line);
	if (!line)
		return (NULL);
	ft_strlcpy(buffer, &buffer[bytes_line + 1], BUFFER_SIZE + 1);
	line = ft_newline(line, buffer, &bytes_line, fd);
	if (!line || line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}
/*
int	main(void)
{
	char	*line;
	int		fd;

	fd = open("prueba.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("%s", line);
		free (line);
		//important to free the line
	}
	close (fd);// this will close the file because 
	the fd it is the closing
	return (0);
}*/
/* 15 WARNING! while (line[len] && line[len] != '\n') no 
 (line[len] || line[len] != '\n')
when it has not reached the end of the line
WARNING if (len > 0 && stash[len - 1] == '\n') no 
if (len > 0 || stash[len - 1] == '\n')
when it has not reached the end of the line
ft_memcpy(stash, line, len);
maybe an error on the stash management what if i add 
a proctection on the next line
line 34
//it takes a string an returs its length when reach '\n' or '\0'
// Andrei indicates I need to fix the or (I need to ask why)
// menaing a new line or the end of file
// Remeber that I have set up the upper limit of BUFFER_SIZE to 120k
// "if (!line)" and "return (-1);" is the control of page 6 
// this is the logical way to handle this behavoir. 
 line 37 //cambiamos de 0 a -1 para adapatr el cambio de i++ a ++i
 line 40 //hemos queidado el i++;
 line 44 //i++;
 line 48 // this takes a line, a buffer, 
 a pointer to a integre (entero) to the line location
// the fd file descriptor 
//Get Next Line 42 | Part 1 https://www.youtube.com/watch?v=kR4FyNzVDBE
// the expalins the FD on minute 2:50 as it is a record studio and
// 0 records, 1 play the sound and 2 give a warning
 */