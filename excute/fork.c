/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyu <junyu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:05:55 by junyu             #+#    #+#             */
/*   Updated: 2023/06/22 18:50:57 by junyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"excute.h"

void	closefd(int **pipefd, int argc)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		close(pipefd[i][0]);
		close(pipefd[i][1]);
		free(pipefd[i]);
		i++;
	}
	free(pipefd);
}

static void	sigint(int signal_number)
{
	if (signal_number == SIGINT)
		exit(130);
}

void	childclosefd(int **pipefd, int argc, int where)
{
	int	i;

	i = 0;
	while (i < where - 1)
	{
		close(pipefd[i][0]);
		close(pipefd[i][1]);
		i++;
	}
	i += 2;
	while (i < argc - 1)
	{
		close(pipefd[i][0]);
		close(pipefd[i][1]);
		i++;
	}
}

static void	pipecontrol(int open, int before, int closefd)
{
	dup2(open, before);
	close(closefd);
}

int	*makeprocess(int argc, t_data *argv, char **env, int **pipefd)
{
	int	i;
	int	*savepid;

	savepid = malloc(sizeof(int) * (argc));
	if (savepid == 0)
		return (0);
	i = -1;
	while (++i < argc)
	{
		savepid[i] = fork();
		if (savepid[i] == 0)
		{
			signal(SIGINT, sigint);
			if (i != 0)
				pipecontrol(pipefd[i - 1][0], 0, pipefd[i - 1][1]);
			if (i != argc - 1)
				pipecontrol(pipefd[i][1], 1, pipefd[i][0]);
			dupinfile(0, (&argv->process[i])->infile_list, 0);
			dupoutfile(1, (&argv->process[i])->outfile_list, 0);
			childclosefd(pipefd, argc, i);
			excute(&argv->process[i], env, argv);
		}
	}
	closefd(pipefd, argc);
	return (savepid);
}
