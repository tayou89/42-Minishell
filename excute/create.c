/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyu <junyu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:58:01 by junyu             #+#    #+#             */
/*   Updated: 2023/06/22 16:30:56 by junyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"excute.h"

int	parent_excute_builtin(t_process *process, int exnum, t_data *data)
{
	int		argc;
	char	**argv;
	int		fd0;
	int		fd1;
	int		status;

	argc = process->count.command;
	argv = process->command;
	fd0 = dup(STDIN_FILENO);
	fd1 = dup(STDOUT_FILENO);
	status = dupinfile(STDIN_FILENO, process->infile_list, 1);
	if (status == 0)
		status = dupoutfile(STDOUT_FILENO, process->outfile_list, 1);
	if (status == 0)
		status = excute_builtin(argc, argv, data, exnum);
	dup2(fd0, STDIN_FILENO);
	dup2(fd1, STDOUT_FILENO);
	close(fd0);
	close(fd1);
	return (status);
}

int	**makepipe(int argc)
{
	int	i;
	int	**result;

	i = 0;
	result = malloc(sizeof(int *) * (argc));
	if (result == 0)
		return (0);
	while (i < argc)
	{
		result[i] = malloc(sizeof(int) * 2);
		if (result[i] == 0)
			return (0);
		if (pipe(result[i]) == -1)
			return (0);
		i++;
	}
	return (result);
}

int	pidwait(int *savepid, int argc)
{
	int	status;
	int	i;

	i = 0;
	while (i < argc)
	{
		if (i == argc - 1)
			waitpid(savepid[i], &status, 0);
		else
			waitpid(savepid[i], 0, 0);
		i++;
	}
	free(savepid);
	return (status);
}

int	child_gen(t_data *data)
{
	int	status;
	int	*savepid;
	int	**pipefd;

	pipefd = makepipe(data->count.pipe);
	if (pipefd == 0)
	{
		perror("minishell");
		return (1);
	}
	savepid = makeprocess(data->count.process, data, data->envp, pipefd);
	if (savepid == 0)
	{
		closefd(pipefd, data->count.process);
		perror("minishell");
		return (1);
	}
	status = pidwait(savepid, data->count.process);
	return (WEXITSTATUS(status));
}
