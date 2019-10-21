/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 11:57:02 by cdelaby           #+#    #+#             */
/*   Updated: 2019/10/10 11:58:47 by cdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 20
#endif

int		main()
{
	static char *fil[5];
	
	fil[0] = strdup( "njuik kqn hjben	 iluukjfn kh	j. fn	ekh.fj,mn eqfnkmnfejkq	m,f ");
	printf("%s", fil[0]);
}
