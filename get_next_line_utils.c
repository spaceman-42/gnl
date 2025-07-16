/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadiaz-b <jadiaz-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:52:33 by jadiaz-b          #+#    #+#             */
/*   Updated: 2025/02/25 18:12:27 by jadiaz-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//ft_memcpy- copy memory area.
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

// ft_bzero write zeroes to a byte string.
void	ft_bzero(void *s, size_t n)
{
	size_t	relleno;

	relleno = 0;
	while (relleno < n)
	{
		((char *)s)[relleno] = 0;
		relleno++;
	}
}

// to mesaure
size_t	ft_strlen(const char *s)
{
	size_t	d;

	d = 0;
	while (s[d] != '\0')
		d++;
	return (d);
}

//to copy or get ---- ft_strlcpy- size-bounded string copying.
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	i;

	if (dstsize == 0)
		return (ft_strlen(src));
	len = 0;
	while (src[len] != '\0')
		++len;
	i = 0;
	while (src[i] != '\0' && i < (dstsize - 1))
	{
		dst[i] = src[i];
		++i;
	}
	dst[i] = '\0';
	return (len);
}

//to cut seems I can do it without this one
// char	*ft_strtrim(char const *s1, char const *set)
// to join: concatenate two strings into a new string (with malloc).
/*
char	*ft_strjoin(char *s1, char *s2, int *locate)
{
	int		i;
	int		len1;
	int		len2;
	char	*s1s2;
	(void)locate;

	if (s1 && s2)
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		s1s2 = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
		if (s1s2 == NULL)
			return (NULL);
		i = -1;
		while (s1[++i])
			s1s2[i] = s1[i];
		i = -1;
		while (s2[++i])
		{
			s1s2[len1] = s2[i];
			len1++;
		}
		s1s2[len1] = '\0';
		return (s1s2);
	}
	return (NULL);
}*/
// my libft do not work bcquse the locate void addtion so this shuld work
char	*ft_strjoin(char *s1, char *s2, int *locate)
{
	char	*ptr;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ptr = (char *)malloc(s1_len + s2_len + 1);
	if (!ptr)
	{
		free (s1);
		return (NULL);
	}
	ft_memcpy(ptr, s1, s1_len);
	free(s1);
	ft_memcpy(ptr + s1_len, s2, s2_len + 1);
	if (s1_len + s2_len > 0 && *(ptr + s1_len + s2_len - 1) == '\n')
		*locate = 0;
	return (ptr);
}
