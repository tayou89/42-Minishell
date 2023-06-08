/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 23:01:49 by tayou             #+#    #+#             */
/*   Updated: 2023/06/08 23:22:22 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handler(int signal_number)
{
	if (signal_number == S_SIGINT)
	{
		printf("minishell> \n");
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
	}
}

int	main(void)
{
	char	*line;
	struct termios	term;

	tcgetattr(STDIN, &term);
	term.c_lflag &= ~(T_ECHOCTL);
	tcsetattr(STDIN, T_TCSANOW, &term);
	signal(S_SIGINT, handler);
	signal(S_SIGQUIT, S_SIG_IGN);
	while (1)
	{
		line = readline("minishell> ");
		if (line == (void *) 0)
		{
			printf("\033[1A");
            printf("\033[10C");
            printf(" exit\n");
            exit(-1);
			break ;
		}
		free(line);
		line = (void *) 0;
	}
	return (0);
}
