/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliot <eliot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 18:34:17 by eliot             #+#    #+#             */
/*   Updated: 2025/10/25 20:24:26 by eliot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str_trim;
	int		start;
	int		end;

	if (!s1)
		return (NULL);
	if (!set || *set == '\0')
		return (ft_strdup(s1));
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end != start && ft_strchr(set, s1[end - 1]))
		end--;
	if (start == end)
		return (ft_strdup("\0"));
	str_trim = malloc((end - start) + 1);
	if (!str_trim)
		return (NULL);
	ft_strlcpy(str_trim, s1 + start, (end - start) + 1);
	return (str_trim);
}
