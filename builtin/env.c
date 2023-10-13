/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyu <junyu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:32:14 by junyu             #+#    #+#             */
/*   Updated: 2023/06/21 18:57:12 by junyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"builtin.h"

int	env(char **envp)
{
	int	i;
	int	error;

	i = 0;
	while (envp[i] != 0)
	{
		error = 1;
		if (ft_strchr(envp[i], '=') != 0)
			error = printf("%s\n", envp[i]);
		if (error < 0)
		{
			perror("env");
			return (1);
		}
		i++;
	}
	return (0);
}
