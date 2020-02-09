/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:05:57 by lvirgini          #+#    #+#             */
/*   Updated: 2020/02/09 18:57:50 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
char			*ft_strdup_buffer_size(const char *s, size_t len)
{
	unsigned int	i;
	unsigned int	len;
	char			*dst;

	if (!s)
		return (NULL);
	if (!(dst = malloc(sizeof(*dst) * (len + 1))))
		return (NULL);
	i = 0;
	while (s[i] && i < len)
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}*/

/*
** Copie src dans dst au plus size octets. protège dst en la finissant par \0.
*/

size_t		ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int i;
	unsigned int src_len;

	if (!src)
		return (0);
	src_len = 0;
	i = 0;
	while (src[src_len])
		++src_len;
	if (size-- > 0)
	{
		while (size-- && i < (src_len) && src[i])
		{
			dst[i] = src[i];
			++i;
		}
		dst[i] = '\0';
	}
	return (src_len);
}

/*
** 	Recherche un caractère (c) dans une chaine de caratere (*s).
** 	Renvoie un pointeur sur la première occurence.
*/

unsigned int	ft_strchr_len(const char *s, int c)
{
	unsigned int i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == (char)c)
			return (i);
		++i;
	}
	return (0);
}

/*
** Joint deux chaines de caractere dans une nouvelle chaine.
** variante gnl : free la chaine s1, qui est toujours malloc
** dans gnl.
*/

char			*ft_strjoin_max_free_s1(char *s1, char const *s2, size_t s2_len)
{
	int		len;
	int		i;
	int		j;
	char	*dest;

	len += s2_len;
	i = 0;
	j = 0;
	if (!s2)
		return (NULL);
	while (s1 && (s1[i++] || (i = 0) != 0))
		len++;
	if (!(dest = malloc(sizeof(*dest) * (len + 1))))
		return (NULL);
	while (s1[i] || (i = 0) != 0)
		dest[j++] = s1[i++];
	while (i < s2_len)
		dest[j++] = s2[i++];
	dest[j] = '\0';
	free(s1);
	return (dest);
}
