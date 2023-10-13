/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyu <junyu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:12:01 by junyu             #+#    #+#             */
/*   Updated: 2023/06/19 16:55:38 by junyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static long long	returnmax(long long minus)
{
	if (minus == 1)
		return (-9223372036854775807 - 1);
	return (9223372036854775807);
}

static long long	checkmax(long long result, char str, long long minus)
{
	char	comp;

	comp = '7';
	if (minus == 1)
		comp += 1;
	if (result < -922337203685477580)
		return (1);
	if (result == -922337203685477580 && str >= comp)
		return (1);
	return (0);
}

long long	ft_atoll(const char *str)
{
	long long	where;
	long long	result;
	long long	minus;

	result = 0;
	where = 0;
	minus = -1;
	while ((str[where] >= 9 && str[where] <= 13) || str[where] == ' ')
		where++;
	if (str[where] == '+' || str[where] == '-')
	{
		if (str[where++] == '-')
			minus *= -1;
	}
	while (str[where] >= '0' && str[where] <= '9')
	{
		if (checkmax(result, str[where], minus) == 1)
		{
			return (returnmax(minus));
		}
		result *= 10;
		result -= str[where++] - '0';
	}
	return ((minus * result));
}
