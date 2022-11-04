/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/13 14:51:58 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/11/04 11:44:20 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include "stop.h"
#include "pipex.h"
#include "parse.h"


#include <stdio.h> //REMOVE
void	check_for_leaks(void)
{
	system("leaks -q pipex");
	system("lsof -c pipex");
}

int	main(int argc, char *argv[], char *env[])
{
	//atexit(check_for_leaks);
	errno = 0;
	if (argc != 5)
		stop("You need to give 4 or more arguments: file1 cmd1 cmd2 file2\n");
	pipex(argc, argv, env);
	return (EXIT_SUCCESS);
}
