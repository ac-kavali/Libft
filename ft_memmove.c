/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahi <achahi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 10:00:47 by achahi            #+#    #+#             */
/*   Updated: 2025/11/03 19:58:12 by achahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	if (src < dest)
	{
		while (n > 0)
		{
			n--;
			d[n] = (unsigned char)s[n];
		}
	}
	if (src > dest)
	{
		while (i < n)
		{
			d[i] = (unsigned char)s[i];
			i++;
		}
	}
	return (dest);
}
