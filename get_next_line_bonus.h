/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 12:10:41 by cdelaby           #+#    #+#             */
/*   Updated: 2019/11/07 12:10:43 by cdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

char		*ft_strcpy(char *dest, const char *src);
int			ft_strlen(const char *str);
char		*ft_strncpy(char *dest, const char *src, size_t n);
char		*ft_strdup(const char *src);
char		*ft_strndup(const char *src, size_t n);
int			search_buf(char *buf);
char		*ft_strnadd(char *rest, char *s2);
int			handle_rest(char **line, char *rest);
int			get_next_line(int fd, char **line);
int			post_checks_gnl(int fd, char **line);

#endif
