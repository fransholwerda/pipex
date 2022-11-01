/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   child_process.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 17:40:21 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/11/01 17:41:01 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHILD_PROCESS_H
# define CHILD_PROCESS_H

# include "struct_tools.h"

void	child_process(int fd, t_command cmd);

#endif
