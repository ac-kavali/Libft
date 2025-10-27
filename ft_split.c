/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahi <achahi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 15:30:59 by achahi            #+#    #+#             */
/*   Updated: 2025/10/27 01:40:49 by achahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_word(const char *s, char delim)
{
	size_t	i;
	int		word;

	i = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] && s[i] == delim)
			i++;
		while (s[i] && s[i] != delim)
		{
			if (i == 0 || s[i - 1] == delim)
				word++;
			i++;
		}
	}
	return (word);
}

char	*ft_make_str(const char *s, size_t start, size_t end)
{
	size_t	i;
	char	*word;

	i = 0;
	word = (char *)malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_allocate_str(const char *s, char delim)
{
	char	**ptr;
	size_t	word_count;

	word_count = ft_count_word(s, delim);
	ptr = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	return (ptr);
}

char	**ft_split(const char *s, char c)
{
	size_t	i;
	size_t	start;
	size_t	end;
	size_t	k;
	char	**words;

	if (!s)
		return (NULL);
	words = ft_allocate_str(s, c);
	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		end = i;
		if (start < end)
			words[k++] = ft_make_str(s, start, end);
	}
	words[k] = NULL;
	return (words);
}
