/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 14:41:12 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/10/23 15:43:03 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	uc1;
	unsigned char	uc2;

	uc1 = '\0';
	uc2 = '\0';
	if (s1 && s2)
	{
		while (n > 0)
		{
			uc1 = (unsigned char)*s1;
			uc2 = (unsigned char)*s2;
			if (uc1 == '\0' || uc2 == '\0' || uc1 != uc2)
				return (uc1 - uc2);
			s1++;
			s2++;
			n--;
		}
	}
	return (uc1 - uc2);
}
