/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 17:06:54 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/11/04 14:13:30 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "struct_tools.h"

typedef struct s_pipex
{
	t_command	*cmds;
}				t_pipex;

void	pipex(int argc, char *argv[], char *env[]);

#endif
