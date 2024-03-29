/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   struct_tools.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/25 15:59:18 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/11/08 13:11:39 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "struct_tools.h"
#include "utils.h"

t_command	*new_cmd(char *cmd, char **args)
{
	t_command	*new_command;

	new_command = (t_command *)malloc(sizeof(t_command));
	if (!new_command)
		stop(NULL);
	new_command->path = NULL;
	new_command->cmd = cmd;
	new_command->args = args;
	new_command->file = NULL;
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

static void	free_cmd_content(t_command *cmd)
{
	if (cmd->args)
		free_split(cmd->args);
	if (cmd->cmd)
		free(cmd->cmd);
	if (cmd->path)
		free(cmd->path);
	if (cmd->file)
		free(cmd->file);
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
			free_cmd_content(tmp);
			free(tmp);
			tmp = cmd;
		}
		cmd = NULL;
		free_cmd_content(tmp);
		free(tmp);
	}
}
