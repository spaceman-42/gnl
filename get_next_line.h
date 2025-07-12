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
# define BUFFER_SIZE 14
# endif


char *get_next_line(int fd);


#endif

// Funtion name as per subject
// Funtion prototipe as per char *get_next_line(int fd), page 1
// We can use read, malloc and free , page 1
// read  is in stdlib.h , page 1, line 15
// malloc is in unistd.h, page 1
// free is in stdlib.h, page 1
// we define BUFFER_SIZE as per subject request, page 6
