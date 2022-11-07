/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_cmd_path.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/23 17:32:19 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/11/07 15:15:49 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"

static char	**get_paths(char *env[])
{
	int		i;
	char	**paths;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			break ;
		i++;
	}
	paths = ft_split(&env[i][5], ':');
	if (!paths)
		stop(NULL);
	return (paths);
}

char	*check_cmd_path(char *env[], char *cmd)
{
	int		i;
	char	*tmp;
	char	*cmd_path;
	char	**paths;

	i = 0;
	tmp = NULL;
	cmd_path = NULL;
	paths = get_paths(env);
	while (paths[i] && cmd[0] != '\0')
	{
		tmp = ft_strjoin("/", cmd);
		cmd_path = ft_strjoin(paths[i], tmp);
		free(tmp);
		if (access(cmd_path, F_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	write(2, "pipex: ", 7);
	write(2, cmd, ft_strlen(cmd));
	write(2, ": command not found\n", 20);
	return (cmd);
}
