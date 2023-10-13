/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyu <junyu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:09:50 by junyu             #+#    #+#             */
/*   Updated: 2023/06/19 17:24:27 by junyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"builtin.h"

int	cd(int argc, char **argv)
{
	int		result;
	char	*error;

	if (argc >= 2)
	{
		result = chdir(argv[1]);
		if (result != 0)
		{
			error = strerror(errno);
			ft_putstr_fd("minishell: cd: ", 2);
			ft_putstr_fd(argv[1], 2);
			ft_putstr_fd(": ", 2);
			ft_putstr_fd(error, 2);
			ft_putstr_fd("\n", 2);
			return (1);
		}
	}
	return (0);
}
