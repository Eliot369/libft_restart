/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliot <eliot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 18:57:12 by eliot             #+#    #+#             */
/*   Updated: 2025/10/23 20:39:10 by eliot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*little == '\0')
		return ((char *) big);
	if (len == 0)
		return (NULL);
	while (i < len)
	{
		if (big[i] == little[j])
		{
			while (i + j < len && big[i + j] == little[j])
			{
				if (little[j + 1] == '\0')
					return (big + i);
				j++;
			}
		}
		j = 0;
		i++;
	}
	return (NULL);
}
