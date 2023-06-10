/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_initial_setting.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:23:50 by tayou             #+#    #+#             */
/*   Updated: 2023/06/10 23:54:31 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	initialize_struct_data(char **envp, t_data *data);

void	make_initial_setting(char **envp, t_data *data)
{
	initialize_struct_data(envp, data);
	initialize_mallocible_data(data);
}

void	initialize_struct_data(char **envp, t_data *data)
{
	data->args.envp = envp;
	data->count.pipe = 0;
	data->count.process = 0;
}

void	initialize_mallocible_data(t_data *data)
{
	data->input.line = (void *) 0;
	data->input.space_split = (void *) 0;
	data->input.pipe_split = (void *) 0;
	data->process = (void *) 0;
}
