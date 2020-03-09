/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 13:11:27 by lvirgini          #+#    #+#             */
/*   Updated: 2020/03/09 13:22:47 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# define NB_FD 100

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_gnl	t_gnl;

struct		s_gnl
{
	int		fd;
	char	buf[BUFFER_SIZE + 1];
};

/*
** GET NEXT LINE . c
*/

int			get_next_line(int fd, char **line);

/*
** GET NEXT LINE UTILS . c
** Attention fonctions modifiees pour GNL.
*/

int			ft_strchr_len(const char *s, int c);
char		*ft_strjoin_max_free_s1(char *s1, char const *s2, size_t s2_len);
char		*ft_strncpy(char *dst, char *src, size_t n);
size_t		ft_strlen(const char *s);

#endif
