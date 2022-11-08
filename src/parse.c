/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/25 15:53:21 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/11/08 13:12:05 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "struct_tools.h"
#include "utils.h"

static int	check_for_nonspaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

static t_command	*parse_cmd(char *arg)
{
	char		**args;
	char		*cmd_str;
	t_command	*cmd;

	if (arg[0] == '\0')
	{
		args = malloc(sizeof(char *) * 2);
		if (!args)
			stop(NULL);
		args[0] = ft_strdup("\0");
		args[1] = NULL;
		cmd_str = ft_strdup("\0");
	}
	else if (check_for_nonspaces(arg) == 1)
	{
		args = ft_split(arg, ' ');
		cmd_str = ft_strdup(args[0]);
	}
	else
	{
		args = ft_split(arg, '\0');
		cmd_str = ft_strdup(arg);
	}
	cmd = new_cmd(cmd_str, args);
	return (cmd);
}

t_command	*parse(int argc, char *argv[])
{
	t_command	*cmd;
	int			i;

	cmd = NULL;
	i = 2;
	while (i < argc - 1)
	{
		if (!cmd)
			cmd = parse_cmd(argv[i]);
		else
			cmd_add_back(cmd, parse_cmd(argv[i]));
		i++;
	}
	return (cmd);
}
