/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/23 17:05:42 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/10/24 16:59:03 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SPLIT_H
# define FT_SPLIT_H

void	free_split(char **result);
char	**ft_split(char const *s, char c);

#endif
