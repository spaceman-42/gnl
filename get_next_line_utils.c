/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadiaz-b <jadiaz-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:52:33 by jadiaz-b          #+#    #+#             */
/*   Updated: 2025/02/25 18:12:27 by jadiaz-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*csrc;
	unsigned char	*cdst;
	size_t			i;

	csrc = (unsigned char *)src;
	cdst = (unsigned char *)dst;
	i = 0;
	if (csrc == 0 && cdst == 0)
		return (NULL);
	while (i < n)
	{
		cdst[i] = csrc[i];
		i++;
	}
	return (dst);
}

void	ft_bzero(void *s, size_t n);
// to mesaure
size_t	ft_strlen(const char *s);
//to copy or get 
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strget(char *line);
//to cut 
char	*ft_strtrim(char const *s1, char const *set)
// to join: concatenate two strings into a new string (with malloc).
char	*ft_strjoin(char *s1, char *s2, int *locate);

