/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 14:23:32 by cdelaby           #+#    #+#             */
/*   Updated: 2019/10/15 14:23:37 by cdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 5
#endif

char		*ft_strcpy(char *dest, const char *src);
int			ft_strlen(const char *str);
char		*ft_strncpy(char *dest, const char *src, size_t n);
char		*ft_strdup(const char *src);
char		*ft_strndup(const char *src, size_t n);
int			search_buf(char *buf);
char		*ft_strnadd(char *rest, char *s2);
int			handle_rest(char **line, char *rest);

#endif
