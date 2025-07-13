/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadiaz-b <jadiaz-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:52:33 by jadiaz-b          #+#    #+#             */
/*   Updated: 2025/02/25 18:12:27 by jadiaz-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif
// Does your function work if it is BUFFER_SIZE is 9999 or 1000000? do you know why?:
// here it is why we give the buffer a space beetwen 1 and 12k 
//The limit of the buffer is set.
# if BUFFER_SIZE < 1 || BUFFER_SIZE > 12000
#  undef BUFFER_SIZE
#  define  BUFFER_SIZE 5
# endif
//here goes the prototype
char *get_next_line(int fd);
// now I have to add the fuctions from my libft

// to manage memory
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_bzero(void *s, size_t n);
// to mesaure
size_t	ft_strlen(const char *s);
//to copy or get 
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strget(char *line);
//to cut 
//char	*ft_strtrim(char const *s1, char const *set)
// to join: concatenate two strings into a new string (with malloc).
char	*ft_strjoin(char *s1, char *s2, int *locate);
// to control the lines
char	*read_line(char *line, int *length);
char	*ft_newline(char *line, char *stash, int *locate, int fd);
//the main!
int		main();

#endif

// Funtion name as per subject
// Funtion prototipe as per char *get_next_line(int fd), page 1
// We can use read, malloc and free , page 1
// read  is in stdlib.h , page 1, line 15
// malloc is in unistd.h, page 1
// free is in stdlib.h, page 1
// we define BUFFER_SIZE as per subject request, page 6
