/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 15:30:09 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/10/25 15:52:59 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <get_paths.h>
#include <unistd.h>
#include <utils.h>
#include <stdlib.h>


#include <stdio.h>
void	pipex(int argc, char *argv[], char *env[])
{
	char	**split;

	split = get_paths(env);
	int i = 0;
	char *tmp = NULL;
	while (split[i])
	{
		tmp = split[i];
		split[i] = ft_strjoin(tmp, "/cat");
		free(tmp);
		//printf("%s\n", split[i]);
		i++;
	}
	i = 0;
	char *stringie[3] = {"cat", "Makefile", NULL};
	while (split[i])
	{
		if (access(split[i], F_OK) == 0)
		{
			execve(split[i], stringie, env);
			printf("access: %d\n", access(split[i], F_OK));
		}
		i++;
	}
	free_split(split);
}
