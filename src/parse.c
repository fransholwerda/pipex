/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/25 15:53:21 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/10/31 17:30:47 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_paths.h"
#include "struct_tools.h"
#include "utils.h"



#include <stdio.h>
static char	*check_cmd_path(char **paths, char *cmd)
{
	int		i;
	char	*tmp;
	char	*cmd_path;

	i = 0;
	tmp = NULL;
	cmd_path = NULL;
	while (paths[i])
	{
		tmp = ft_strjoin("/", cmd);
		cmd_path = ft_strjoin(paths[i], tmp);
		free(tmp);
		if (access(cmd_path, F_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	return (NULL);
}

static t_command	*parse_cmd(char **paths, char *arg)
{
	char		**args;
	char		*cmd_str;
	char		*cmd_path;
	t_command	*cmd;

	args = ft_split(arg, ' ');
	cmd_str = ft_strdup(args[0]);
	cmd_path = check_cmd_path(paths, cmd_str);
	cmd = new_cmd(cmd_path, cmd_str, args);
	return (cmd);
}

t_command	*parse(int argc, char *argv[], char *env[])
{
	t_command	*cmd;
	char		**paths;
	int			i;

	cmd = NULL;
	paths = get_paths(env);
	i = 2;
	while (i < argc - 1)
	{
		if (!cmd)
			cmd = parse_cmd(paths, argv[i]);
		else
			cmd_add_back(cmd, parse_cmd(paths, argv[i]));
		i++;
	}
	free_split(paths);
	return (cmd);
}
