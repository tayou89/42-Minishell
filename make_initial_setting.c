/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_initial_setting.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:23:50 by tayou             #+#    #+#             */
/*   Updated: 2023/06/09 15:09:26 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	make_initial_setting(char **envp, t_data *data)
{
	initialize_struct_data(envp, data);
	make_terminal_setting(data);
	handle_signal(
}

void	initialize_struct_data(char **envp, t_data *data)
{
	data->args.envp = envp;
	data->user.input = (void *) 0;
	data->user.split_input = (void *) 0;
}

void	make_terminal_setting(t_data *data)
{
	struct termios	term;

	if (tcgetattr(STDIN, &term) == -1)
		execute_error_process((void *) 0, 1, data);
	data->terminal.initial_setting = term;
	term.c_lflag &= ~(T_ECHOCTL);
	data->terminal.changed_setting = term;
	if (tcsetattr(STDIN, T_TCSANOW, &(data->terminal.changed_setting)) == -1)
		execute_error_process((void *) 0, 1, data);
}
