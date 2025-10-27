/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahi <achahi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 09:40:01 by achahi            #+#    #+#             */
/*   Updated: 2025/10/27 01:42:33 by achahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	s_len;
	size_t	i;
	size_t	j;
	char	*trimed;

	i = 0;
	j = 0;
	s_len = ft_strlen(s1);
	trimed = malloc(s_len + 1);
	while (is_in_set(s1[i], set))
		i++;
	while (is_in_set(s1[s_len - 1], set))
		s_len--;
	while (i < s_len)
		trimed[j++] = s1[i++];
	trimed[i] = '\0';
	return (trimed);
}
