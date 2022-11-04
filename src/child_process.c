/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   child_process.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 17:16:50 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/11/04 11:46:36 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "stop.h"
#include "struct_tools.h"

void	child_process1(char *env[], int tunnel[2], int infile, t_command *cmd)
{
	if (dup2(infile, STDIN_FILENO) < 0)
		stop("Child");
	if (close(infile) < 0)
		stop("Child");
	if (dup2(tunnel[1], STDOUT_FILENO) < 0)
		stop("Child");
	if (close(tunnel[0]) < 0)
		stop("Child");
	execve(cmd->path, cmd->args, env);
	exit(EXIT_FAILURE);
}

void	child_process2(char *env[], int tunnel[2], int outfile, t_command *cmd)
{
	if (dup2(outfile, STDOUT_FILENO) < 0)
		stop("Child");
	if (close(outfile) < 0)
		stop("Child");
	if (dup2(tunnel[0], STDIN_FILENO) < 0)
		stop("Child");
	if (close(tunnel[1]) < 0)
		stop("Child");
	execve(cmd->path, cmd->args, env);
	exit(EXIT_FAILURE);
}
