/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyu <junyu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:15:36 by junyu             #+#    #+#             */
/*   Updated: 2023/06/19 16:25:18 by junyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"builtin.h"

static int	flag_check(char *str)
{
	int	i;

	i = 1;
	while (str[i] != '\0')
	{
		if (str[i++] != 'n')
			break ;
	}
	if (str[i] == '\0')
		return (1);
	return (0);
}

static int	printerror(void)
{
	perror("echo");
	return (1);
}

int	echo(int argc, char **argv)
{
	int	i;
	int	mod;
	int	error;

	mod = 0;
	if (argc >= 2 && argv[1][0] == '-')
		mod = flag_check(argv[1]);
	i = 1 + mod;
	while (argv[i] != 0)
	{
		error = printf("%s", argv[i++]);
		if (error < 0)
			return (printerror());
		if (argv[i] != 0)
		{
			error = printf(" ");
			if (error < 0)
				return (printerror());
		}
	}
	if (mod == 0 || (argc >= 2 && argv[1][1] == '\0'))
		error = printf("\n");
	if (error < 0)
		return (printerror());
	return (0);
}
