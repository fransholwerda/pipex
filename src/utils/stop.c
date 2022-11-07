/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stop.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 16:38:23 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/11/04 17:40:24 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "ft_strlen.h"

void	stop(char *s)
{
	if (s)
	{
		write(2, "pipex: ", 7);
		perror(s);
	}
	else
		perror("pipex: ");
	exit(EXIT_FAILURE);
}
