/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyu <junyu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:33:07 by junyu             #+#    #+#             */
/*   Updated: 2023/06/21 17:40:37 by junyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"excute.h"

static int	openerrorprint(char *file, int flag)
{
	ft_putstr_fd("minishell: ", 2);
	perror(file);
	if (flag == 0)
		exit(1);
	return (1);
}

int	dupinfile(int fd, t_node *list, int flag)
{
	int	file;

	file = fd;
	while (list != 0)
	{
		file = open(list->string, O_RDONLY);
		if (file == -1)
			return (openerrorprint(list->string, flag));
		if (list->next != 0)
			close(file);
		list = list->next;
	}
	if (file != fd)
		dup2(file, fd);
	return (0);
}

int	dupoutfile(int fd, t_node *list, int flag)
{
	int	file;

	file = fd;
	while (list != 0)
	{
		if (list->string_type == OUTFILE_TRUNC)
			file = open(list->string, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		else
			file = open(list->string, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (file == -1)
			return (openerrorprint(list->string, flag));
		if (list->next != 0)
			close(file);
		list = list->next;
	}
	if (file != fd)
		dup2(file, fd);
	return (0);
}
