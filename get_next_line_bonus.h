/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 13:11:27 by lvirgini          #+#    #+#             */
/*   Updated: 2020/03/04 17:53:50 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

/*
** GET NEXT LINE . c
*/

int			get_next_line(int fd, char **line);
int			copy_buf_in_line(char **line, char *buf, int end_of_line, int len);
int			stop_read(char **line, char *buf, int end_of_line, int len);

/*
** GET NEXT LINE UTILS . c
** Attention fonctions modifiees pour GNL.
*/

int			ft_strchr_len(const char *s, int c);
char		*ft_strjoin_max_free_s1(char *s1, char const *s2, size_t s2_len);
char		*ft_strncpy(char *dst, char *src, size_t n);
size_t		ft_strlen(const char *s);

#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif
