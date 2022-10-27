/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 14:12:17 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/10/27 13:23:27 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stop.h>
#include <ft_strlen.h>

char	*ft_strdup(const char *s)
{
	char	*sdup;
	size_t	i;

	sdup = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (sdup == NULL)
		stop("Memory allocation error.\n");
	i = 0;
	while (i < ft_strlen(s))
	{
		sdup[i] = s[i];
		i++;
	}
	sdup[i] = '\0';
	return (sdup);
}
