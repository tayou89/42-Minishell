/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipe_and_redirection.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:34:37 by tayou             #+#    #+#             */
/*   Updated: 2023/06/10 21:12:24 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_pipe_and_redirection_count(t_data *data);
void	get_pipe_and_redirection_index(t_data *data);
void	malloc_pipe_and_redirection_index(t_data *data);

void	check_pipe_and_redirection(t_data *data)
{
	get_pipe_and_redirection_count(data);
	get_pipe_and_redirection_index(data);
}

void	get_pipe_and_redirection_count(t_data *data)
{
	int		i;

	i = 0;
	while (data->input.split_line[i] != (void *) 0)
	{
		if (check_string_is_pipe(data->input.split_line) == TRUE)
			data->pipe.count++;
		else if (check_string_is_redirection == TRUE)
			data->redirection.count++;
		i++;
	}
}

void	get_pipe_and_redirection_index(t_data *data)
{
	int		pipe_index;
	int		redirection_index;
	int		i;


	malloc_pipe_and_redirection_index(data);
	pipe_index = 0;
	redirection_index = 0;
	i = 0;
	while (data->input.split_line[i] != (void *) 0)
	{
		if (check_pipe(data->input.plit_line[i]) == TRUE)
		{
			data->pipe.index[pipe_index] = i;
			pipe_index++;
		}
		else if (check_redirection(data->input.split_line[i]) == TRUE)
		{
			data->redirection.index[redirection_index] = i;
			redirection_index++;
		}
		i++;
	}
}

void	malloc_pipe_and_redirection_index(t_data *data)
{
	data->pipe.index = (int *) malloc(sizeof(int) * data->pipe.count);
	if (data->pipe.index == (void *) 0)
		execute_error_process((void *) 0, 1, data);
	data->redirection.index = \
		(int *) malloc(sizeof(int) * data->redirection.count);
	if (data->redirection.index == (void *) 0)
		execute_error_process((void *) 0, 1, data);
}
