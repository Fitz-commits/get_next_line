/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 12:10:55 by cdelaby           #+#    #+#             */
/*   Updated: 2019/11/07 12:10:57 by cdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char			*ft_strcpy(char *dest, const char *src)
{
	int i;

	i = 0;
	while (src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

int				ft_strlen(const char *str)
{
	int i;

	if (!str)
	{
		return (0);
	}
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char			*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t i;

	i = 0;
	while (src[i] != 0 && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char			*ft_strdup(const char *src)
{
	char *fin;

	fin = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (fin == 0)
		return (0);
	ft_strcpy(fin, src);
	return (&*fin);
}

char			*ft_strndup(const char *src, size_t n)
{
	char *dest;

	if (!(dest = malloc(sizeof(char) * (n + 1))))
		return (0);
	dest = ft_strncpy(dest, src, n);
	dest[n] = 0;
	return (&*dest);
}
