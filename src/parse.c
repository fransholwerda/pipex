/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/25 15:53:21 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/10/27 17:16:53 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <struct_tools.h>
#include <stdlib.h>
#include <get_paths.h>
#include <utils.h>

char	*check_cmd_path(char **paths, char *cmd)
{
	
}

t_command	*parse_cmd(char **paths, char *arg)
{
	char		*args;
	char		*cmd;
	t_command	*new_cmd;

	args = ft_split(arg, ' ');
	cmd = ft_strdup(args[0]);
	
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
		
	}
}
