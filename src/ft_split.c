/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chgomez <chgomez@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:16:21 by chgomez           #+#    #+#             */
/*   Updated: 2025/11/11 17:17:34 by chgomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static int	word_count(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*dup_word(const char *start, const char *end)
{
	char	*word;
	int		len;
	int		i;

	len = end - start;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
		word[i++] = *start++;
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char		**res;
	int			i;
	const char	*start;

	if (!s)
		return (NULL);
	res = malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		start = s;
		while (*s && *s != c)
			s++;
		if (start < s)
			res[i++] = dup_word(start, s);
	}
	res[i] = NULL;
	return (res);
}
