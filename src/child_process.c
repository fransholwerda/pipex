/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   child_process.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 17:16:50 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/11/03 16:15:54 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "struct_tools.h"

void	child_process1(char *env[], int tunnel[2], int infile, t_command *cmd)
{
	dup2(infile, STDIN_FILENO);
	close(infile);
	dup2(tunnel[1], STDOUT_FILENO);
	close(tunnel[0]);
	execve(cmd->path, cmd->args, env);
	exit(EXIT_FAILURE);
}

void	child_process2(char *env[], int tunnel[2], int outfile, t_command *cmd)
{
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
	dup2(tunnel[0], STDIN_FILENO);
	close(tunnel[1]);
	execve(cmd->path, cmd->args, env);
	exit(EXIT_FAILURE);
}
