/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyu <junyu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:15:37 by junyu             #+#    #+#             */
/*   Updated: 2023/06/24 19:46:57 by junyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"excute.h"

char	**findpath(char **env)
{
	char	**result;
	int		i;

	i = 0;
	while (env[i] != 0)
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			break ;
		i++;
	}
	if (env[i] == 0)
		return (0);
	result = ft_split((*(env + i) + 5), ':');
	if (result == 0)
		exit(1);
	return (result);
}

char	*findexec(char **path, char *slash)
{
	char	*temp;
	int		i;

	i = 0;
	if (path == 0 || ft_strlen(slash) == 1)
		return (0);
	while (path[i] != 0)
	{
		temp = ft_strjoin(path[i], slash);
		if (temp == 0)
			return (0);
		if (access(temp, X_OK) == 0)
			return (temp);
		free(temp);
		i++;
	}
	return (0);
}

void	dcharfree(char **str, int i)
{
	if (str == 0)
		return ;
	while (str[i] != 0)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	*makedir(char *command, char **env)
{
	char	**path;
	char	*slash;
	char	*result;

	path = findpath(env);
	slash = ft_strjoin("/", command);
	if (slash == 0)
	{
		dcharfree(path, 0);
		exit (1);
	}
	result = findexec(path, slash);
	dcharfree(path, 0);
	free(slash);
	if (result == 0)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(command, 2);
		ft_putstr_fd(": command not found\n", 2);
		exit(127);
	}
	return (result);
}

int	excute(t_process *process, char **env, t_data *data)
{
	char	**argv;
	char	*finalcmd;
	char	*check;
	int		n;

	if (process->command == 0)
		exit (0);
	n = check_builtin(process->command[0]);
	if (n != 0)
		exit(excute_builtin(process->count.command, process->command, data, n));
	argv = process->command;
	check = ft_strchr(argv[0], '/');
	if (check != 0)
		finalcmd = argv[0];
	else
		finalcmd = makedir(argv[0], env);
	execve(finalcmd, argv, env);
	ft_putstr_fd("minishell: ", 2);
	perror(argv[0]);
	if (errno == 13)
		exit (126);
	exit (127);
}
