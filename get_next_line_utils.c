/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:05:57 by lvirgini          #+#    #+#             */
/*   Updated: 2020/01/28 18:57:54 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*ft_strdup(const char *s)
{
	unsigned int	i;
	unsigned int	len;
	char			*dst;

	len = 0;
	while (s[len])
		len++;
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
}

/*
** 	Recherche un caractère (c) dans une chaine de caratere (*s).
** 	Renvoie un pointeur sur la première occurence.
*/

unsigned int	ft_strchr_i(const char *s, int c)
{
	unsigned int i;

	i = 0;
	while (s[i])
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

char			*ft_strjoin_s1_free(char *s1, char const *s2)
{
	int		len;
	int		i;
	int		j;
	char	*dest;

	len = 0;
	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	while (s1[i++] || (i = 0) != 0)
		len++;
	while (s2[i++] || (i = 0) != 0)
		len++;
	if (!(dest = malloc(sizeof(*dest) * (len + 1))))
		return (NULL);
	while (s1[i] || (i = 0) != 0)
		dest[j++] = s1[i++];
	while (s2[i])
		dest[j++] = s2[i++];
	dest[j] = '\0';
	free(s1);
	return (dest);
}
