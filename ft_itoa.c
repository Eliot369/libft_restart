/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliot <eliot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 19:14:29 by eliot             #+#    #+#             */
/*   Updated: 2025/10/27 11:45:35 by eliot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	set_negative(bool *negative_val, long *n_long)
{
	if (*n_long < 0)
	{
		*negative_val = true;
		*n_long *= -1;
	}
	else
		*negative_val = false;
}

static int	n_len(long n, bool negative_val)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	if (negative_val == true)
		len += 1;
	return (len);
}

char	*ft_itoa(int n)
{
	long	n_long;
	bool	negative_val;
	int		len;
	char	*result;

	n_long = n;
	if (n == 0)
		return (ft_strdup("0"));
	set_negative(&negative_val, &n_long);
	len = n_len(n_long, negative_val);
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[len] = '\0';
	len--;
	while (len >= 0 && n_long != 0)
	{
		result[len] = (n_long % 10) + '0';
		n_long /= 10;
		len--;
	}
	if (negative_val == true)
		result[0] = '-';
	return (result);
}
