/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 14:12:17 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/11/04 17:42:56 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"

char	*ft_strdup(const char *s)
{
	char	*sdup;
	size_t	i;

	sdup = NULL;
	if (s)
	{
		sdup = malloc((ft_strlen(s) + 1) * sizeof(char));
		if (!sdup)
			stop(NULL);
		i = 0;
		while (i < ft_strlen(s))
		{
			sdup[i] = s[i];
			i++;
		}
		sdup[i] = '\0';
	}
	return (sdup);
}
