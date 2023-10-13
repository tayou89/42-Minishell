/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 01:13:09 by tayou             #+#    #+#             */
/*   Updated: 2023/06/21 11:53:35 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	initialize_process_data(t_data *data);

void	malloc_process(t_data *data)
{
	data->count.process = data->count.pipe + 1;
	data->process = \
		(t_process *) malloc(sizeof(t_process) * data->count.process);
	if (data->process == (void *) 0)
		execute_error_process("data->process", 1, data);
	initialize_process_data(data);
}

void	initialize_process_data(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->count.process)
	{
		data->process[i].line = (void *) 0;
		data->process[i].redirection = (void *) 0;
		data->process[i].stop_string = (void *) 0;
		data->process[i].command = (void *) 0;
		data->process[i].command_list = (void *) 0;
		data->process[i].infile_list = (void *) 0;
		data->process[i].outfile_list = (void *) 0;
		data->process[i].quote_list = (void *) 0;
		data->process[i].env_list = (void *) 0;
		data->process[i].index.start = -1;
		data->process[i].count.character = 0;
		data->process[i].count.heredoc = 0;
		data->process[i].string_type = COMMAND;
		data->process[i].flag.heredoc_exist = FALSE;
		i++;
	}
}
