/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahi <achahi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 22:24:24 by achahi            #+#    #+#             */
/*   Updated: 2025/11/01 22:26:31 by achahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

//test additional functions here
int main(void)
{
	// Example usage of ft_strjoin
	char *s1 = "Hello, ";
	char *s2 = "World!";
	char *result = ft_strjoin(s1, s2);
	if (result)
	{
		printf("ft_strjoin result: %s\n", result);
		free(result);
	}
	return (0);
}
