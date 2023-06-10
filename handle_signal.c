/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:22:50 by tayou             #+#    #+#             */
/*   Updated: 2023/06/10 15:26:05 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	make_terminal_setting(t_data *data);
void	signal_handler(int signal_number);

void	handle_signal(t_data *data)
{
	make_terminal_setting(data);
	signal(S_SIGINT, signal_handler);
	signal(S_SIGQUIT, S_SIG_IGN);
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

void	signal_handler(int signal_number)
{
	if (signal_number == S_SIGINT)
	{
		printf("minishell> \n");
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
	}
}
