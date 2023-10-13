/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyu <junyu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:07:31 by junyu             #+#    #+#             */
/*   Updated: 2023/06/20 15:33:35 by junyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"builtin.h"

static int	make_exit_num(char *str)
{
	char		*comp;

	comp = ft_lltoa(ft_atoll(str));
	if (comp == 0)
	{
		perror("exit");
		return (1);
	}
	if (ft_strncmp(str + (str[0] == '+'), comp, ft_strlen(str) + 1) != 0)
	{
		free(comp);
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		return (255);
	}
	free(comp);
	return (ft_atoi(str));
}

int	builtin_exit(int argc, char **argv)
{
	ft_putstr_fd("exit\n", 2);
	if (argc > 2)
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		return (1);
	}
	if (argc == 2)
	{
		exit(make_exit_num(argv[1]));
	}
	exit(0);
}
