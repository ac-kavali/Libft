/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahi <achahi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 10:13:50 by achahi            #+#    #+#             */
/*   Updated: 2025/10/17 09:27:54 by achahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t s)
{
	unsigned char	*arr;
	size_t			i;

	arr = (unsigned char *)str;
	i = 0;
	while (i < s)
	{
		arr[i] = 0;
		i++;
	}
}
