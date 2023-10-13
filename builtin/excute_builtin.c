/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyu <junyu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:38:22 by junyu             #+#    #+#             */
/*   Updated: 2023/06/21 18:12:34 by junyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"builtin.h"

int	check_builtin(char *name)
{
	size_t	len;

	len = ft_strlen(name) + 1;
	if (ft_strncmp(name, "echo", len) == 0)
		return (1);
	if (ft_strncmp(name, "cd", len) == 0)
		return (2);
	if (ft_strncmp(name, "pwd", len) == 0)
		return (3);
	if (ft_strncmp(name, "export", len) == 0)
		return (4);
	if (ft_strncmp(name, "unset", len) == 0)
		return (5);
	if (ft_strncmp(name, "env", len) == 0)
		return (6);
	if (ft_strncmp(name, "exit", len) == 0)
		return (7);
	return (0);
}

int	excute_builtin(int argc, char **argv, t_data *data, int exnum)
{
	int	result;

	result = 0;
	if (exnum == 1)
		result = echo(argc, argv);
	else if (exnum == 2)
		result = cd(argc, argv);
	else if (exnum == 3)
		result = pwd();
	else if (exnum == 4)
		result = export(argc, argv, data);
	else if (exnum == 5)
		result = unset(argc, argv, data);
	else if (exnum == 6)
		result = env(data->envp);
	else if (exnum == 7)
		result = builtin_exit(argc, argv);
	return (result);
}

int	child_excute(int argc, char **argv, t_data *envp, int exnum)
{
	int	result;

	result = excute_builtin(argc, argv, envp, exnum);
	exit(result);
}

//int	parent_excute(t_process *process, int exnum, char **envp)
//{
//	int		argc;
//	char	**argv;
//	int		fd0;
//	int		fd1;
//
//	argc = process->count.command;
//	argv = process->command;
//	fd0 = dup(0);
//	fd1 = dup(1);
//	dup2(fd0, 0);
//	dup2(fd1, 1);
//	argc = excute_builtin(argc, argv, envp, exnum);
//	dup2(0, fd0);
//	dup2(1, fd1);
//	close(fd0);
//	close(fd1);
//	return (argc);
//}
