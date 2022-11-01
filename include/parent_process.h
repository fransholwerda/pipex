/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parent_process.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 17:41:10 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/11/01 17:41:39 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARENT_PROCESS_H
# define PARENT_PROCESS_H

# include "struct_tools.h"

void	parent_process(int fd, t_command cmd);

#endif
