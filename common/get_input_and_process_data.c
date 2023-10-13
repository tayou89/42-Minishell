/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input_and_process_data.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyu <junyu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:31:35 by tayou             #+#    #+#             */
/*   Updated: 2023/06/26 11:45:48 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	signal_check(int num)
{
	if (g_signal == -1)
		num = 1;
	g_signal = 0;
	return (num);
}

void	get_input_and_process_data(t_data *data)
{
	int	result;

	printf("\033[s");
	data->line = readline("minishell> ");
	while (data->line != (void *) 0)
	{
		data->exit_status = signal_check(data->exit_status);
		add_history(data->line);
		parse_line(data);
		if (data->flag.syntax_error == FALSE && g_signal != 2)
		{
			result = pipex(data);
			if (result != -1)
				data->exit_status = result;
		}
		else if (g_signal == 2)
			data->exit_status = 1;
		else if (data->flag.syntax_error == TRUE)
			data->exit_status = 258;
		printf("\033[s");
		g_signal = 0;
		free_every_mallocated_data(data);
		data->line = readline("minishell> ");
	}
	control_d_in_parent(data);
}
