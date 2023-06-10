/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_process_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 20:41:16 by tayou             #+#    #+#             */
/*   Updated: 2023/06/10 23:50:48 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_process_data(t_data *data)
{
	get_process_count(data);
	malloc_process(data);
	initialize_process_data(data);
	fill_process_data(data);
}

void	get_process_count(t_data *data)
{
	char	**string;
	int		i;

	string = data->input.split_line[i];
	i = 0;
	while (string[i] != (void *) 0)
	{
		if (check_string_is_pipe(string[i]) == TRUE)
			data->count.pipe++;
		i++;
	}
	data->count.process = data->count.pipe + 1;
}

void	malloc_process(t_data *data)
{
	data->process = (t_process *) malloc(sizeof(t_process) * data->count.process);
	if (data->process == (void *) 0)
		execute_error_process((void *) 0, 1, data);
}

void	initialize_process_data(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->count.process)
	{
		data->process[i].line = (void *) 0;
		data->process[i].cmd = (void *) 0;
		data->process[i].path.cmd = (void *) 0;
		data->process[i].path.infile = (void *) 0;
		data->process[i].path.outfile = (void *) 0;
		i++;
	}
}
