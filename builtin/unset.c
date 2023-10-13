/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyu <junyu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:55:43 by junyu             #+#    #+#             */
/*   Updated: 2023/06/23 18:54:42 by junyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"builtin.h"

static void	error_print(char *name)
{
	ft_putstr_fd("minishell: unset: `", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
}

static void	frees(char *one, char *two, char **three)
{
	free(one);
	free(two);
	free(three);
}

static char	**del_env(char *str, char **env)
{
	char	**result;
	int		count;
	int		i;
	int		flag;
	char	*comp;

	flag = 0;
	count = envcount(env) - (finderase(env, str) != -1) + 1;
	result = malloc(sizeof(char *) * count);
	comp = ft_strjoin(str, "=");
	if (result == 0 || comp == 0)
		exit(1);
	i = 0;
	while (env[i] != 0)
	{
		if (ft_strncmp(env[i], comp, ft_strlen(comp)) != 0)
			result[i - flag] = ft_strdup(env[i]);
		else
			flag += 1;
		free(env[i++]);
	}
	frees(comp, env[i], env);
	result[i - flag] = 0;
	return (result);
}

int	unset(int argc, char **argv, t_data *data)
{
	int		i;
	int		returnval;
	char	**envp;

	i = 0;
	returnval = 0;
	while (++i < argc)
	{
		envp = data->envp;
		if (envname_vaild_check(argv[i]) != 1)
		{
			error_print(argv[i]);
			returnval = 1;
			continue ;
		}
		data->envp = del_env(argv[i], envp);
	}
	return (returnval);
}
