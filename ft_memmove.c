/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliot <eliot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 12:46:27 by eliot             #+#    #+#             */
/*   Updated: 2025/10/19 16:04:47 by eliot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*simple_forward_copy(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;

	s = (const unsigned char *)src;
	d = (unsigned char *)dest;
	while (n > 0)
	{
		*d = *s;
		n--;
		s++;
		d++;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;

	s = (const unsigned char *) src;
	d = (unsigned char *) dest;
	if (dest == src || n == 0)
		return (dest);
	else if (dest < src)
		return (simple_forward_copy(dest, src, n));
	else
	{
		while (n > 0)
		{
			d[n - 1] = s[n - 1];
			n--;
		}
		return (dest);
	}
}
