/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   child_process.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 17:16:50 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/11/07 15:16:30 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "utils.h"
#include "check_cmd_path.h"
#include "struct_tools.h"

void	child_process1(char *env[], int tunnel[2], t_command *cmd)
{
	int	infile;

	infile = open(cmd->file, O_RDONLY);
	if (infile < 0)
		stop(cmd->file);
	cmd->path = check_cmd_path(env, cmd->cmd);
	if (dup2(infile, STDIN_FILENO) < 0)
		stop(NULL);
	if (close(infile) < 0)
		stop(NULL);
	if (dup2(tunnel[1], STDOUT_FILENO) < 0)
		stop(NULL);
	if (close(tunnel[0]) < 0)
		stop(NULL);
	execve(cmd->path, cmd->args, env);
	exit(EXIT_FAILURE);
}

void	child_process2(char *env[], int tunnel[2], t_command *cmd)
{
	int	outfile;

	outfile = open(cmd->file, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (outfile < 0)
		stop(cmd->file);
	cmd->path = check_cmd_path(env, cmd->cmd);
	if (dup2(outfile, STDOUT_FILENO) < 0)
		stop(NULL);
	if (close(outfile) < 0)
		stop(NULL);
	if (dup2(tunnel[0], STDIN_FILENO) < 0)
		stop(NULL);
	if (close(tunnel[1]) < 0)
		stop(NULL);
	execve(cmd->path, cmd->args, env);
	exit(EXIT_FAILURE);
}
