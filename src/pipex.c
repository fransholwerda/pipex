/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 15:30:09 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/11/03 16:15:47 by fholwerd      ########   odam.nl         */
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

static void	pipex_init(int argc, char *argv[], char *env[], t_pipex *pip)
{
	pip->inf_fd = open(argv[1], O_RDONLY);
	if (pip->inf_fd < 0)
		perror("Infile: ");
	pip->out_fd = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pip->out_fd < 0)
		perror("Outfile: ");
	pip->cmds = parse(argc, argv, env);
}

void	pipex(int argc, char *argv[], char *env[])
{
	t_pipex		pip;
	int			tunnel[2];
	pid_t		pid1;
	pid_t		pid2;

	pipex_init(argc, argv, env, &pip);
	pipe(tunnel);
	pid1 = fork();
	if (pid1 < 0)
		perror("Fork: ");
	else if (pid1 == 0)
		child_process1(env, tunnel, pip.inf_fd, pip.cmds);
	pid2 = fork();
	if (pid2 < 0)
		perror("Fork: ");
	else if (pid2 == 0)
		child_process2(env, tunnel, pip.out_fd, pip.cmds->next);
	close(tunnel[0]);
	close(tunnel[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	close(pip.inf_fd);
	close(pip.out_fd);
	free_cmds(pip.cmds);
}
