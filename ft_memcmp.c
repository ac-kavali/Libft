/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahi <achahi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 09:39:44 by achahi            #+#    #+#             */
/*   Updated: 2025/10/22 10:27:43 by achahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *m1, const void *m2, size_t size)
{
	size_t			i;
	unsigned char	*mem1;
	unsigned char	*mem2;

	if (!m1 || !m2)
		return (0);
	mem1 = (unsigned char *)m1;
	mem2 = (unsigned char *)m2;
	i = 0;
	while (i < size)
	{
		if (mem1[i] != mem2[i])
			return (mem1[i] - mem2[i]);
		i++;
	}
	return (0);
}
