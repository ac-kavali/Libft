/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spilt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahi <achahi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 15:30:59 by achahi            #+#    #+#             */
/*   Updated: 2025/10/26 16:38:11 by achahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_count_word (const char *s, char delim)
{
	size_t	i;
	int	word;

	i = 0;
	word = 0;
	while(str[i])
	{
		if (s[i] && s[i] == delim)
			i++;
		while (s[i] && s[i] != delim)
		{
			if (s[i-1] == delim)
				word++;
			i++;
		}
	}
	return (word);
}


}
char **ft_split(char const *s, char c)
{

}
