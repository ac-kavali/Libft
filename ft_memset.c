/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahi <achahi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 10:13:50 by achahi            #+#    #+#             */
/*   Updated: 2025/10/16 17:58:14 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

void    *ft_memset(void *ptr, int v, size_t s)
{
    unsigned char *arr;
    size_t       i;

    arr = (unsigned char *)ptr;
    i = 0;
    while (i < s)
    {
        arr[i] = (unsigned char)v; //arr is type unsigned char then you should cast the v.
        i++;
    }
    return (ptr);
}
