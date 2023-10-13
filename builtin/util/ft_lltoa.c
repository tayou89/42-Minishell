/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyu <junyu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 18:13:06 by junyu             #+#    #+#             */
/*   Updated: 2023/06/19 16:55:36 by junyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtin.h"

static int	lencheck(long long n)
{
	int	result;

	result = 1;
	if (n == 0)
		return (1);
	if (n >= 0)
		n *= -1;
	else
		result++;
	while (n < -9)
	{
		n /= 10;
		result++;
	}
	return (result);
}

static void	strmake(char *result, long long n, int len)
{
	int	minus;

	minus = 0;
	result[len] = '\0';
	if (n < 0)
	{
		minus = 1;
		result[0] = '-';
	}
	while (len > minus)
	{
		if (n >= 0)
			result[len - 1] = (n % 10) + '0';
		else
			result[len - 1] = -(n % 10) + '0';
		len--;
		n /= 10;
	}
}

char	*ft_lltoa(long long n)
{
	int		len;
	char	*result;

	len = lencheck(n);
	result = (char *)malloc(len + 1);
	if (result == 0)
		return (0);
	strmake(result, n, len);
	return (result);
}
