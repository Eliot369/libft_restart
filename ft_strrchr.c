/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliot <eliot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:24:30 by eliot             #+#    #+#             */
/*   Updated: 2025/10/22 13:41:33 by eliot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	if ((unsigned char) s[i] == (unsigned char) c)
		return ((char *) s + i);
	i -= 1;
	while (i >= 0)
	{
		if ((unsigned char) s[i] == (unsigned char) c)
			return ((char *) s + i);
		i--;
	}
	return (NULL);
}
