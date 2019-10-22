/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 07:53:16 by cdelaby           #+#    #+#             */
/*   Updated: 2019/10/11 07:53:18 by cdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 5
#endif

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
	return (-1);
}

char		*ft_strcpy(char *dest, const char *src)
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

int		ft_strlen(const char *str)
{
	int i;

	if (!str)
	{
		return(0);
	}
	
	i = 0;
	while (str[i])
		i++;
		
	return (i);
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

char		*ft_strdup(const char *src)
{
	char *fin;

	fin = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (fin == 0)
		return (0);
	ft_strcpy(fin, src);
	return (&*fin);
}

char		*ft_strndup(const char *src, size_t n)
{
	char *dest;

	if (!(dest = malloc(sizeof(char) * (n + 1))))
		return (0);
	dest = ft_strncpy(dest, src, n);
	dest[n] = 0;
	return (&*dest);
}


char *change_rest(char *rest, char *nrest)
{	
	int size;
	int i;

	i = 0;
	if(rest)
		free(rest);
	size = ft_strlen(nrest);
	if(!(rest = malloc(sizeof(char) * (size + 1))))
		return (0);
	while(i < size)
	{
		rest[i] = nrest[i];
		i++;
	}
	rest[i] = 0;
	return (rest);
}

char		*ft_stradd(char *rest, char *s2)
{
	char			*copy;
	char			*copy_cpp;
	char			*rest_cpp;

	if (rest == 0 && s2 == 0)
		return (0);
	copy = ft_strdup(rest);
	free(rest);
	copy_cpp = copy;
	if (!(rest = (char*)malloc(sizeof(char) * (ft_strlen(copy)
		+ ft_strlen(s2) + 1))))
		return (0);
	rest_cpp = rest;
	while (*copy)
		*rest++ = *copy++;
	while (*s2)
		*rest++ = *s2++;
	free(copy_cpp);
	*rest = 0;
	return (rest_cpp);
}

char		*ligne_find(char *rest, char **line) //should escalate error tbd
{
	char cpp_local[BUFFER_SIZE + 1];

	if(search_buf(rest) == ft_strlen(rest) - 1)
		{
			if(!(*line = ft_strndup((rest), search_buf(rest))))
				return (0);
			free(rest);
			rest = NULL;
		}
	else
		{
			ft_strcpy(cpp_local, &rest[search_buf(rest) + 1]);
			printf("rest = %s\n", rest);		
			if(!(*line = ft_strndup(rest, search_buf(rest))))
					return (0);
			free(rest);
			rest = 0;
			if(!(rest = strdup(cpp_local)))
				return (0);
		}
	return (rest);
}

int		get_next_line(int fd, char **line)
{
	static char *rest = NULL;
	char buf[BUFFER_SIZE + 1];
	int br;

	while(((br = read(fd, buf, BUFFER_SIZE)) > 0) || rest)
	{
		buf[br] = 0;

		if (rest)
			rest = ft_stradd(rest, buf);
		else
			rest = strdup(buf);
		if(search_buf(rest) > -1)
		{
			rest = ligne_find(rest, line);
			return (1);
		}
	}
	return (0);

}

/* int		get_next_line(int fd, char **line)
{
	static t_list *fil;
	t_list *temp;
	t_list *node;
	char *buf;
	int found;


	if(search_buf(fil->s))
		if(search_buf(fil->s) == ft_strlen(fil->s))
			{
				if(!(*line =ft_strdup(fil->s)))
					return (0);
				free(fil->s);
				free(fil);
				return (1);
			}
		if (!(*line =ft_strndup(fil->s, search_buf(fil->s))))
			return(0);
		fil->s = change_rest(fil->s, &fil->s[search_buf(fil->s)]);
		return (1);

	
	
}
*/
int	main(int argc, char **argv)
{
	int		i;
	int		fd;
	char	*line;
	int		ret;

	/* printf("limit fdmax %d\n", OPEN_MAX); */
	if (argc != 2)
	{
		printf("You forgot the filename");
		exit(1);
	}
	printf("BUFFER_SIZE = %d\n", BUFFER_SIZE);
	fd = open(argv[1], O_RDONLY);
	i = 1;
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		printf("%3d [%s]\n", i, line);
		free(line);
		i++;
	}
	if (ret == -1)
		printf("error\n");
	else if (ret == 0)
		printf("EOF\n");
	close(fd);
	return (0);
}

/*

left to do :

1. Séparer les fonction, optimiser la place et l'espace
2. Accepter différents fd

*/
