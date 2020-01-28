/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:19:48 by lvirgini          #+#    #+#             */
/*   Updated: 2020/01/28 13:44:33 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

#include <stdio.h>

char			*ft_strdup(const char *s);
int				get_next_line(int fd, char **line);
char			*ft_strjoin(char const *s1, char const *s2);
unsigned int	ft_strchr_i(const char *s, int c);

#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE -1
#endif
