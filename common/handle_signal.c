/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyu <junyu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:22:50 by tayou             #+#    #+#             */
/*   Updated: 2023/06/25 16:49:26 by junyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	make_terminal_setting(t_data *data);
void	signal_handler(int signal_number);

void	handle_signal(t_data *data)
{
	make_terminal_setting(data);
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, SIG_IGN);
}

void	make_terminal_setting(t_data *data)
{
	struct termios	term;

	if (tcgetattr(STDIN_FILENO, &term) == -1)
		execute_error_process("tcgetattr", 1, data);
	term.c_lflag &= ~(ECHOCTL);
	if (tcsetattr(STDIN_FILENO, TCSANOW, &term) == -1)
		execute_error_process("tcsetattr", 1, data);
}

void	signal_handler(int signal_number)
{
	if (signal_number == SIGINT)
	{
		if (g_signal == 0 || g_signal == -1)
		{
			write(2, "\n", 1);
			printf("\033[s");
			rl_on_new_line();
			rl_replace_line("", 1);
			rl_redisplay();
			g_signal = -1;
		}
		if (g_signal == 1)
		{
			g_signal = 2;
			write(2, "\n", 1);
		}
	}
}
