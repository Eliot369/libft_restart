/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliot <eliot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:09:35 by eliot             #+#    #+#             */
/*   Updated: 2025/10/28 21:02:04 by eliot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*build_str(char const *s, char c, int *i, int word_len)
{
	char	*new_str;

	new_str = (char *)malloc((word_len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s, word_len + 1);
	return (new_str);
}

static char	*extract_str(char const *s, char c, char **new_list, int *i)
{
	int	word_count;
	int	w_len;

	word_count = 0;
	while (*s == c)
		s++;
	while (*s)
	{
		if (*s != c)
		{
			w_len = 0;
			word_count++;
			while (s[w_len] && s[w_len] != c)
				w_len++;
			if (word_count - 1 == *i)
			{
				new_list[*i] = build_str(s, c, i, w_len);
				return (new_list[*i]);
			}
			else
				s += w_len;
		}
		else
			s++;
	}
}

static int	s_word_count(char const *s, char c)
{
	int	word_count;

	word_count = 0;
	while (*s == c)
		s++;
	while (*s)
	{
		if (*s != c)
		{
			word_count++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (word_count);
}

char	**ft_split(char const *s, char c)
{
	char	**new_list;
	int		word_count;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	word_count = s_word_count(s, c);
	new_list = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!new_list)
		return (NULL);
	new_list[word_count] = NULL;
	while (i < word_count)
	{
		if (!extract_str(s, c, new_list, &i))
		{
			i -= 1;
			while (i >= 0)
				free (new_list[i--]);
			free (new_list);
			return (NULL);
		}
		i++;
	}
}
