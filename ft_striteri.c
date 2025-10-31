/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliot <eliot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:38:52 by eliot             #+#    #+#             */
/*   Updated: 2025/10/27 13:52:13 by eliot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	s_len;
	size_t	i;

	if (!s)
		return ;
	if (*s == '\0')
		return ;
	s_len = ft_strlen(s);
	i = 0;
	while (i < s_len)
	{
		(*f)(i, &s[i]);
		i++;
	}
	return ;
}
