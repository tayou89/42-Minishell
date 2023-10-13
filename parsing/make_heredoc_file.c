/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_heredoc_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyu <junyu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:20:39 by tayou             #+#    #+#             */
/*   Updated: 2023/06/24 21:23:28 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	make_heredoc_file_in_process(t_process *process, t_data *data);
void	find_heredoc_path(t_node *node, t_data *data);
void	open_heredoc_file(char *file_path, t_process *process, t_data *data);
void	read_line_and_write_to_heredoc(t_process *process);

void	make_heredoc_file(t_data *data)
{
	t_process	*process;
	int			i;

	i = 0;
	while (i < data->count.process && g_signal != 2)
	{
		process = &data->process[i];
		if (process->flag.heredoc_exist == TRUE)
			make_heredoc_file_in_process(process, data);
		i++;
	}
}

void	make_heredoc_file_in_process(t_process *process, t_data *data)
{
	t_node	*list;
	int		pid;

	list = process->infile_list;
	while (list != (void *) 0)
	{
		if (list->string_type == HEREDOC && g_signal != 2)
		{
			process->stop_string = ft_strdup(list->string);
			if (process->stop_string == (void *) 0)
				execute_error_process("process->stop_string", 1, data);
			free_1d_array(list->string);
			find_heredoc_path(list, data);
			g_signal = 1;
			pid = fork();
			if (pid == 0)
			{
				open_heredoc_file(list->string, process, data);
				read_line_and_write_to_heredoc(process);
			}
			waitpid(pid, 0, 0);
		}
		list = list->next;
	}
}

void	find_heredoc_path(t_node *node, t_data *data)
{
	char	*basic_path;
	char	*number;
	int		i;

	basic_path = "/tmp/heredoc_";
	i = 0;
	while (i < 300)
	{
		number = ft_itoa(i);
		if (number == (void *) 0)
			execute_error_process("ft_itoa", 1, data);
		node->string = ft_strjoin(basic_path, number);
		if (node->string == (void *) 0)
			execute_error_process("ft_strjoin", 1, data);
		free_1d_array(number);
		if (access(node->string, F_OK) == -1)
			return ;
		else
			free_1d_array(node->string);
		i++;
	}
}

void	open_heredoc_file(char *file_path, t_process *process, t_data *data)
{
	process->fd.heredoc = open(file_path, \
		O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (process->fd.heredoc == -1)
		execute_error_process(file_path, 1, data);
}

void	read_line_and_write_to_heredoc(t_process *process)
{
	char	*line;

	signal(SIGINT, exit);
	line = readline("> ");
	if (line == (void *) 0)
		control_d_in_heredoc();
	while (check_string_is_same(line, process->stop_string) \
			== FALSE)
	{
		write(process->fd.heredoc, line, ft_strlen(line));
		write(process->fd.heredoc, "\n", 1);
		free_1d_array(line);
		line = readline("> ");
		if (line == (void *) 0)
			control_d_in_heredoc();
	}
	free_1d_array(process->stop_string);
	process->stop_string = (void *) 0;
	free_1d_array(line);
	close(process->fd.heredoc);
	exit(0);
}
