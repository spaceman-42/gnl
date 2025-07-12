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

//it takes a string an returs its length when reach '\n' or '\0'
// Andrei indicates I need to fix the or (I need to ask why)
// menaing a new line or the end of file
// Remeber that I have set up the upper limit of BUFFER_SIZE to 120k
size_t	ft_strget(char *line)
{
  size_t i=0;
  
  if (!line)
		return (-1);
	while (i < BUFFER_SIZE)
	{
		if (line[i] == '\n' || line[i] == '\0')
			return (i + 1);
		i++;
	}
	return (i);
}
// "if (!line)" and "return (-1);" is the control of page 6 

char	*read_line(char *line, int *length)
{
}

char	*ft_newline(char *line, char *stash, int *locate, int fd)
{
}

char	*get_next_line(int fd)
{
}
