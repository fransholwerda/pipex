/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_paths.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/23 17:32:19 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/11/04 11:48:17 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	**get_paths(char *env[])
{
	int		i;
	char	**paths;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			break ;
		i++;
	}
	paths = ft_split(&env[i][5], ':');
	if (!paths)
		stop("Split");
	return (paths);
}
