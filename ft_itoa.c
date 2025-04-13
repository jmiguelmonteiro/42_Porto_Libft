/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 12:15:25 by josemigu          #+#    #+#             */
/*   Updated: 2025/04/13 22:46:16 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_itoa_10(long n)
{
	int		len;

	len = 1;
	while (n > 9 || n < -9)
	{
		n /= 10;
		len++;
	}
	if (n < 0)
		len++;
	return (len);
}

char	*ft_itoa(int n)
{
	int		signal;
	int		len;
	long 	nn;
	char	*result;

	nn = n;
	len = len_itoa_10(nn);
	signal = 1;
	if (nn < 0)
	{
		signal = -1;
		nn *= signal;
	}
	result = ft_calloc(len + 1, sizeof (*result));
	if (!result)
		return (NULL);
	result[len] = '\0';
	while (nn > 9)
	{
		result[--len] = (char) (nn % 10) + 48;
		nn /= 10;
	}
	result[--len] = (char) (nn % 10) + 48;
	if (signal == -1)
		result[--len] = '-';
	return (result);
}
