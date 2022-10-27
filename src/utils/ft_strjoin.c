/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/01 16:26:34 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/10/27 17:01:55 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <ft_strlen.h>
#include <stop.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*s12;
	unsigned int	i;
	unsigned int	j;

	if (s1 == NULL || s2 == NULL)
		stop("Empty strings provided.\n");
	s12 = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (s12 == NULL)
		stop("Memory allocation error\n");
	i = 0;
	while (s1[i])
	{
		s12[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		s12[i] = s2[j];
		i++;
		j++;
	}
	s12[i] = '\0';
	return (s12);
}
