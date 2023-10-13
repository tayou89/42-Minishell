/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyu <junyu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:58:52 by junyu             #+#    #+#             */
/*   Updated: 2023/06/23 18:56:47 by junyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static void	error_print(char *name)
{
	ft_putstr_fd("minishell: export: `", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
}

static char	**add_env(char *str, char **env)
{
	char	**result;
	int		count;
	int		i;

	count = envcount(env) + (findenv(env, str) == -1) + 1;
	result = malloc(sizeof(char *) * count);
	if (result == 0)
		exit(1);
	i = 0;
	while (i < count - 1)
	{
		if (i != findenv(env, str) && env[i] != 0)
			result[i] = ft_strdup(env[i]);
		else
			result[i] = ft_strdup(str);
		free(env[i]);
		i++;
	}
	result[i] = 0;
	free(env);
	return (result);
}

int	export(int argc, char **argv, t_data *data)
{
	int		i;
	int		returnval;
	char	**envp;

	i = 0;
	returnval = 0;
	while (++i < argc)
	{
		envp = data->envp;
		if (envname_vaild_check(argv[i]) == 2)
		{
			error_print(argv[i]);
			returnval = 1;
		}
		if (envname_vaild_check(argv[i]))
			continue ;
		data->envp = add_env(argv[i], envp);
	}
	return (returnval);
}
