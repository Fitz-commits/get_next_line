/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lirefc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:25:44 by cdelaby           #+#    #+#             */
/*   Updated: 2019/10/09 18:25:47 by cdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 20
#endif

void	*ft_memccpy(void *str1, const void *str2, int c, size_t n)
{
	unsigned char		*dstr;
	unsigned char		*sstr;
	size_t				i;

	if (str1 == 0 && str2 == 0)
		return (0);
	dstr = (unsigned char*)str1;
	sstr = (unsigned char*)str2;
	i = 0;
	while (i < n)
	{
		dstr[i] = sstr[i];
		if (sstr[i] == (unsigned char)c)
		{
			return (&str1[i] + 1);
		}
		i++;
	}
	return (0);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*sc;

	i = 0;
	sc = s;
	while (i < n)
	{
		sc[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	char *s1;

	if (!(s1 = malloc(size * count)))
		return (0);
	ft_bzero(s1, size * count);
	return (s1);
}

int		search_buf(char *buf)
{
	int i;

	i = 0;
	while (buf[i])
	{
		if( buf[i] == 10)
			return (i);
		i++;
	}
	return (0);
}

char	*ft_strncpy(char *dest, const char *src, size_t n)
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

int		ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}



int main()
{
    char *buf;
    char *fil;
    ssize_t bytes_read;
    int fd;

    int i;
    int j;

    i = 0;
    j = 0;

	

    buf= ft_calloc(BUFFER_SIZE + 1, 1);
	fil= ft_calloc(BUFFER_SIZE + 1, 1);
    fd = open("/Users/cdelaby/Documents/get_next_line/fichier", O_RDONLY);

    bytes_read = read(fd, buf, BUFFER_SIZE);
	if (search_buf(buf) == ft_strlen(buf) - 1)
		ft_strncpy(fil,buf,search_buf(buf));
	printf("Buffer = %s\nBytes read = %zd \nFil = %s\n", buf, bytes_read, fil);
	bytes_read = read(fd, buf, BUFFER_SIZE);
    printf("Buffer = %s\nBytes read = %zd \nFil = %s\n", buf, bytes_read, fil);
}