/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_process_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyu <junyu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:43:02 by tayou             #+#    #+#             */
/*   Updated: 2023/06/26 11:47:50 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	free_1d_array_in_process(t_process *process);
void	free_2d_array_in_process(t_process *process);
void	free_linked_list_in_process(t_process *process);
void	remove_heredoc_file(t_process *process);

void	free_process_data(t_data *data)
{
	t_process	*process;
	int			i;

	i = 0;
	while (i < data->count.process)
	{
		process = &data->process[i];
		if (process->flag.heredoc_exist == TRUE)
			remove_heredoc_file(process);
		free_1d_array_in_process(process);
		free_2d_array_in_process(process);
		free_linked_list_in_process(process);
		i++;
	}
	free(data->process);
	data->process = (void *) 0;
}

void	free_1d_array_in_process(t_process *process)
{
	if (process->line != (void *) 0)
		free_1d_array(process->line);
	if (process->redirection != (void *) 0)
		free_1d_array(process->redirection);
	if (process->stop_string != (void *) 0)
		free_1d_array(process->stop_string);
	process->line = (void *) 0;
	process->redirection = (void *) 0;
	process->stop_string = (void *) 0;
}

void	free_2d_array_in_process(t_process *process)
{
	if (process->command != (void *) 0)
		free_2d_array((void **) process->command);
	process->command = (void *) 0;
}

void	free_linked_list_in_process(t_process *process)
{
	if (process->command_list != (void *) 0)
		free_linked_list(&process->command_list);
	if (process->infile_list != (void *) 0)
		free_linked_list(&process->infile_list);
	if (process->outfile_list != (void *) 0)
		free_linked_list(&process->outfile_list);
	if (process->quote_list != (void *) 0)
		free_linked_list(&process->quote_list);
	if (process->env_list != (void *) 0)
		free_linked_list(&process->env_list);
}

void	remove_heredoc_file(t_process *process)
{
	t_node	*list;

	list = process->infile_list;
	while (list != (void *) 0)
	{
		if (list->string_type == HEREDOC)
			unlink(list->string);
		list = list->next;
	}
}
