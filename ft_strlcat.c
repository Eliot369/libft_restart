/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliot <eliot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 18:11:12 by eliot             #+#    #+#             */
/*   Updated: 2025/10/19 20:21:30 by eliot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	strlenbuff(const char *str, size_t size)
{
	size_t	len;

	len = 0;
	while ((len <= size - 1) && *str)
	{
		len++;
		str++;
	}
	return (len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;

	i = 0;
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	dst_len = strlenbuff(dst, size);
	src_len += dst_len;
	while (src[i] && (dst_len + i < size - 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if (dst_len <= size - 1)
		dst[dst_len + i] = '\0';
	return (src_len);
}
