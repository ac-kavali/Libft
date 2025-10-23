/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahi <achahi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 20:35:23 by achahi            #+#    #+#             */
/*   Updated: 2025/10/23 22:30:58 by achahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strdup(const char *s)
{
	size_t	i;
	char	*dup;
	
	if (!s)
		return (NULL);
	i = ft_strlen(s);
	dup = (char *)malloc(i + 1* sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (str[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return(dup);
}
