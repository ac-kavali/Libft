/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahi <achahi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 09:54:49 by achahi            #+#    #+#             */
/*   Updated: 2025/10/17 10:44:06 by achahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_arr;
	const unsigned char	*src_arr;
	size_t				i;

	dest_arr = (unsigned char *)dest;
	src_arr = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dest_arr[i] = src_arr[i];
		i++;
	}
	return (dest);
}
