/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:05:57 by lvirgini          #+#    #+#             */
/*   Updated: 2020/02/12 14:43:17 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** STRNCPY copie src dans dst.
** Si srclen < n , rajoute des \0 jusqu'a (n).
*/

char		*ft_strncpy(char *dst, char *src, size_t n)
{
	size_t		i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dst[i] = src[i];
		i++;
	}
	while (i < n)
		dst[i++] = '\0';
	return (dst);
}

/*
**  GNL modif.
** 	Recherche un caractère (c) dans une chaine de caratere (*s).
** 	Renvoie la len de la première occurence.
*/

int			ft_strchr_len(const char *s, int c)
{
	unsigned int i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == (char)c)
			return (i);
		++i;
	}
	return (-1);
}

/*
**	GNL Modif.
** Joint deux chaines de caractere dans une nouvelle chaine.
** variante gnl : free la chaine s1, qui est toujours malloc
** dans gnl.
*/

char		*ft_strjoin_max_free_s1(char *s1, char const *s2, size_t s2_len)
{
	int		len;
	int		i;
	int		j;
	char	*dest;

	len = s2_len;
	i = 0;
	j = 0;
	if (!s2)
		return (NULL);
	while (s1 && (s1[i++] || (i = 0) != 0))
		len++;
	if (!(dest = malloc(sizeof(*dest) * (len + 1))))
		return (NULL);
	while ((s1 && s1[i]) || (i = 0) != 0)
		dest[j++] = s1[i++];
	while (i < s2_len)
		dest[j++] = s2[i++];
	dest[j] = '\0';
	if (s1)
		free(s1);
	return (dest);
}

/*
** 	Renvoie le nombre de caratère dans la chaine (*s)
** 	SANS compter le dernier octet nul : "\0"
*/

size_t		ft_strlen(const char *s)
{
	unsigned int i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}
