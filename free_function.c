/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:51:51 by tayou             #+#    #+#             */
/*   Updated: 2023/06/11 00:07:36 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_every_mallocated_data(t_data *data)
{
	if (data->input.line != (void *) 0)
		free_1d_array((void *) data->input.line);
	if (data->input.space_split != (void *) 0)
		free_2d_array((void **) data->input.space_split);
	if (data->process != (void *) 0)
		free_process_data(data);
}

void	free_1d_array(void *array)
{
	free(array);
	array = (void *) 0;
}

void	free_2d_array(void **array)
{
	int	i;

	i = 0;
	while (array[i] != (void *) 0)
	{
		free(array[i]);
		array[i] == (void *) 0;
		i++;
	}
	free(array);
	array = (void *) 0;
}

void	free_process_data(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->count.process)
	{
		if (data->process[i].line != (void *) 0)
			free_1d_array((void *) data->process[i].line);
		if (data->process[i].cmd != (void *) 0)
			free_2d_array((void **) data->process[i].cmd);
		if (data->process[i].path.cmd != (void *) 0)
			free_1d_array((void *) data->process[i].path.cmd);
		i++;
	}
}
