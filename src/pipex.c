/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 15:30:09 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/10/31 17:54:44 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "utils.h"
#include "parse.h"
#include "struct_tools.h"

void	pipex(int argc, char *argv[], char *env[])
{
	t_command	*cmds;
	int			fd[2];
	pid_t		pid;

	cmds = parse(argc, argv, env);
	pipe(fd);
	pid = fork();
	if (pid < 0)
		stop("Pid failure\n");
	else if (pid == 0) //child process
	{
		dup2(fd[0], 0);
		close(fd[0]);
		close(fd[1]);
		execve(cmds->path, cmds->args, env);
	}
	else //parent process
	{
		//waitpid(child_pid)
		dup2(fd[1], 1);
		close(fd[0]);
		close(fd[1]);
		execve(cmds->next->path, cmds->next->args, env);
	}
	free_cmds(cmds);
}
