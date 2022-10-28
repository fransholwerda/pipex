/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 14:12:17 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/10/28 18:03:18 by fholwerd      ########   odam.nl         */
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
		printf("test6\n");
		sdup = malloc((ft_strlen(s) + 1) * sizeof(char));
		printf("test7\n");
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
