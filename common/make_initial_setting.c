/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_initial_setting.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyu <junyu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:23:50 by tayou             #+#    #+#             */
/*   Updated: 2023/06/24 15:21:49 by tayou            ###   ########.fr       */
/*   Updated: 2023/06/22 18:59:03 by junyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	initialize_data(t_data *data);
void	copy_envp(char **envp, t_data *data);
void	get_env_count(char **envp, t_data *data);
void	get_data_envp(char **envp, t_data *data);

void	make_initial_setting(char **envp, t_data *data)
{
	initialize_data(data);
	copy_envp(envp, data);
}

void	initialize_data(t_data *data)
{
	g_signal = 0;
	data->exit_status = 0;
	data->count.pipe = 0;
	data->count.process = 0;
	data->line = (void *) 0;
	data->process = (void *) 0;
	data->flag.syntax_error = FALSE;
}

void	copy_envp(char **envp, t_data *data)
{
	get_env_count(envp, data);
	get_data_envp(envp, data);
}

void	get_env_count(char **envp, t_data *data)
{
	int	i;

	i = 0;
	while (envp[i] != (void *) 0)
		i++;
	data->count.env = i;
}

void	get_data_envp(char **envp, t_data *data)
{
	int	i;

	data->envp = (char **) malloc(sizeof(char *) * (data->count.env + 1));
	if (data->envp == (void *) 0)
		execute_error_process("data->envp", 1, data);
	i = 0;
	while (envp[i] != (void *) 0)
	{
		data->envp[i] = ft_strdup(envp[i]);
		if (data->envp[i] == (void *) 0)
			execute_error_process("data->envp", 1, data);
		i++;
	}
	data->envp[i] = (void *) 0;
}
