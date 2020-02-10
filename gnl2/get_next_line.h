/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 13:11:27 by lvirgini          #+#    #+#             */
/*   Updated: 2020/02/10 16:20:29 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //

#ifndef		GET_NEXT_LINE_H
# define	GET_NEXT_LINE_H

# include	<unistd.h>
#include 	<stdlib.h>

int			get_next_line(int fd, char **line);
int			ft_strchr_len(const char *s, int c);
char		*ft_strjoin_max_free_s1(char *s1, char const *s2, size_t s2_len);
int			copy_buf_in_line(char **line, char *buf, int end_of_line, int len);
int			stop_read(char **line, char *buf, int end_of_line, int len);
char		*ft_strncpy(char *dst, char *src, size_t n);

#endif

#ifndef		BUFFER_SIZE
# define	BUFFER_SIZE 15
#endif
