/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   struct_tools.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/25 15:59:18 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/10/27 13:01:43 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <struct_tools.h>
#include <stdlib.h>
#include <stop.h>

t_command	*new_cmd(char *path, char *cmd, char **arg)
{
	t_command	*new_command;

	new_command = (t_command *)malloc(sizeof(t_command));
	if (!new_command)
		stop("Memory allocation error.\n");
	new_command->path = path;
	new_command->cmd = cmd;
	new_command->arg = arg;
	new_command->next = NULL;
	return (new_command);
}

void	cmd_add_back(t_command *cmd, t_command *new_cmd)
{
	if (cmd)
	{
		while (cmd->next)
			cmd = cmd->next;
		cmd->next = new_cmd;
	}
}

void	free_cmds(t_command *cmd)
{
	t_command	*tmp;

	if (cmd)
	{
		tmp = cmd;
		while (cmd->next)
		{
			cmd = cmd->next;
			free(tmp);
			tmp = cmd;
		}
		cmd = NULL;
		free(tmp);
	}
}
