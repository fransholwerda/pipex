/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   struct_tools.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/25 15:59:38 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/11/04 12:55:19 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_TOOLS_H
# define STRUCT_TOOLS_H

typedef struct s_command
{
	char				*path;
	char				*cmd;
	char				**args;
	char				*file;
	struct s_command	*next;
}				t_command;

t_command	*new_cmd(char *path, char *cmd, char **args);
void		cmd_add_back(t_command *cmd, t_command *new_cmd);
void		free_cmds(t_command *cmd);

#endif
