/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_paths.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/23 17:32:19 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/10/27 13:08:33 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>
#include <stop.h>

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
	paths = ft_split(env[i], ':');
	return (paths);
}
