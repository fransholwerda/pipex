/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 15:30:09 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/11/08 13:15:36 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "utils.h"
#include "parse.h"
#include "struct_tools.h"
#include "child_process.h"
#include "pipex.h"

static t_command	*cmds_init(int argc, char *argv[])
{
	t_command	*cmds;

	cmds = parse(argc, argv);
	cmds->file = ft_strdup(argv[1]);
	cmds->next->file = ft_strdup(argv[argc - 1]);
	return (cmds);
}

void	pipex(int argc, char *argv[], char *env[])
{
	t_command	*cmds;
	int			tunnel[2];
	pid_t		pid1;
	pid_t		pid2;

	cmds = cmds_init(argc, argv);
	if (pipe(tunnel) < 0)
		stop(NULL);
	pid1 = fork();
	if (pid1 < 0)
		stop(NULL);
	else if (pid1 == 0)
		child_process1(env, tunnel, cmds);
	pid2 = fork();
	if (pid2 < 0)
		stop(NULL);
	else if (pid2 == 0)
		child_process2(env, tunnel, cmds->next);
	close(tunnel[0]);
	close(tunnel[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	free_cmds(cmds);
}
