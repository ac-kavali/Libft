/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahi <achahi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 10:00:47 by achahi            #+#    #+#             */
/*   Updated: 2025/10/18 23:20:53 by achahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	if (src < dest)
	{
		while (size > 0)
		{
			size--;
			d[size] = (unsigned char)s[size];
		}
	}
	if (src > dest)
	{
		while (i < size)
		{
			d[i] = (unsigned char)s[i];
			i++;
		}
	}
	return (dest);
}
