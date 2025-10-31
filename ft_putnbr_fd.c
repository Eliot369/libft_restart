/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliot <eliot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 16:59:40 by eliot             #+#    #+#             */
/*   Updated: 2025/10/27 20:08:11 by eliot            ###   ########.fr       */
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
	return (len);
}

static void	print_digits(long n_long, bool negative_val, int fd, int len)
{
	int		i;
	long	divisor;
	char	c;

	i = 1;
	divisor = 1;
	while (i < len)
	{
		divisor *= 10;
		i++;
	}
	if (negative_val == true)
		write (fd, "-", 1);
	while (divisor > 0)
	{
		c = (n_long / divisor) + '0';
		write (fd, &c, 1);
		n_long = n_long % divisor;
		divisor /= 10;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int		len;
	long	n_long;
	bool	negative_val;

	n_long = n;
	if (fd < 0)
		return ;
	if (n == 0)
	{
		write (fd, "0", 1);
		return ;
	}
	set_negative(&negative_val, &n_long);
	len = n_len(n_long, negative_val);
	print_digits(n_long, negative_val, fd, len);
}
