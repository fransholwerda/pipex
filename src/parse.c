/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/25 15:53:21 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/10/27 18:04:13 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <struct_tools.h>
#include <stdlib.h>
#include <unistd.h>
#include <get_paths.h>
#include <utils.h>

static char	*check_cmd_path(char **paths, char *cmd)
{
	int		i;
	char	*cmd_path;

	i = 0;
	while (paths[i])
	{
		cmd_path = ft_strjoin(paths[i], cmd);
		if (access(cmd_path, F_OK))
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
	i = 1;
	while (i < argc - 1)
	{
		if (!cmd)
			cmd = parse_cmd(paths, argv[i]);
		else
			cmd_add_back(cmd, parse_cmd);
	}
	//REMOVE THIS
	while (cmd)
	{
		
	}
}
