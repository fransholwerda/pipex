/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 15:30:09 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/10/28 16:52:15 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "utils.h"
#include "parse.h"
#include "struct_tools.h"

void	pipex(int argc, char *argv[], char *env[])
{
	t_command	*cmds;

	cmds = parse(argc, argv, env);
	free_cmds(cmds);
}
