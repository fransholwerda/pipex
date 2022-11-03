/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   child_process.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 17:40:21 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/11/03 15:32:56 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHILD_PROCESS_H
# define CHILD_PROCESS_H

# include "struct_tools.h"

void	child_process1(char *env[], int tunnel[2], int infile, t_command *cmd);
void	child_process2(char *env[], int tunnel[2], int outfile, t_command *cmd);

#endif
