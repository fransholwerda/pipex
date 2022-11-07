/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/13 14:51:58 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/11/07 15:30:58 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include "stop.h"
#include "pipex.h"
#include "parse.h"

int	main(int argc, char *argv[], char *env[])
{
	errno = 0;
	if (argc != 5)
	{
		write(2, "You need to give 4 or more arguments: \
file1 cmd1 cmd2 file2\n", 60);
		exit(EXIT_FAILURE);
	}
	pipex(argc, argv, env);
	return (EXIT_SUCCESS);
}
