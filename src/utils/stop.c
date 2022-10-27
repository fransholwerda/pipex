/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stop.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 16:38:23 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/10/27 13:03:26 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <ft_strlen.h>

void	stop(char *s)
{
	if (errno == 0)
		write(2, s, ft_strlen(s));
	else
		perror(s);
	exit(EXIT_FAILURE);
}
