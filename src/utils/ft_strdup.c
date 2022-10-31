/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 14:12:17 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/10/31 17:34:55 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"


#include <stdio.h>
char	*ft_strdup(const char *s)
{
	char	*sdup;
	size_t	i;

	sdup = NULL;
	if (s)
	{
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
	}
	return (sdup);
}
