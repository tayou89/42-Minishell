/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:17:28 by tayou             #+#    #+#             */
/*   Updated: 2023/06/23 12:25:22 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	get_command_count(t_process *process);
void	malloc_command_array(t_process *process, t_data *data);
void	fill_command_array(t_process *process, t_data *data);

void	get_command_array(t_data *data)
{
	t_process	*process;
	int			i;

	i = 0;
	while (i < data->count.process)
	{
		process = &data->process[i];
		if (process->command_list != (void *) 0)
		{
			get_command_count(process);
			malloc_command_array(process, data);
			fill_command_array(process, data);
			free_linked_list(&process->command_list);
		}
		i++;
	}
}

void	get_command_count(t_process *process)
{
	t_node	*list;

	process->count.command = 0;
	list = process->command_list;
	while (list != (void *) 0)
	{
		if (list->string != (void *) 0)
			process->count.command++;
		list = list->next;
	}
}

void	malloc_command_array(t_process *process, t_data *data)
{
	process->command = \
		(char **) malloc(sizeof(char *) * (process->count.command + 1));
	if (process->command == (void *) 0)
		execute_error_process("process->command", 1, data);
}

void	fill_command_array(t_process *process, t_data *data)
{
	t_node	*list;
	int		i;

	list = process->command_list;
	i = 0;
	while (i < process->count.command)
	{
		if (list->string != (void *) 0)
		{
			process->command[i] = ft_strdup(list->string);
			if (process->command[i] == (void *) 0)
				execute_error_process("process->command", 1, data);
			i++;
		}
		list = list->next;
	}
	process->command[i] = (void *) 0;
}
