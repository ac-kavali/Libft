/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahi <achahi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 15:30:59 by achahi            #+#    #+#             */
/*   Updated: 2025/11/03 19:35:21 by achahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_str(char **words, int w_number)
{
	int	i;

	i = 0;
	while (i < w_number)
	{
		free(words[i]);
		i++;
	}
	free(words);
}

static int	ft_count_word(const char *s, char delim)
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

static char	**fill(char *s, char **words_root, char delim, size_t start)
{
	size_t	wn;
	size_t	i;

	i = 0;
	wn = 0;
	while (s[i])
	{
		if (s[i] && s[i] == delim)
			i++;
		start = i;
		while (s[i] && s[i] != delim)
			i++;
		if (start < i)
		{
			words_root[wn++] = ft_substr(s, start, i - start);
			if (!(words_root[wn - 1]))
			{
				free_str(words_root, wn - 1);
				return (NULL);
			}
		}
	}
	words_root[wn] = NULL;
	return (words_root);
}

static char	**allocate_root(char *s, char delim, size_t start)
{
	char	**words_root;

	words_root = malloc((ft_count_word(s, delim) + 1) * (sizeof(char *)));
	if (!words_root)
		return (NULL);
	fill(s, words_root, delim, start);
	return (words_root);
}

char	**ft_split(char const *s, char c)
{
	char	**words_root;
	size_t	start;
	char	*str;

	str = (char *)s;
	if (!s)
		return (NULL);
	start = 0;
	words_root = allocate_root(str, c, start);
	if (!words_root)
		return (NULL);
	return (words_root);
}
