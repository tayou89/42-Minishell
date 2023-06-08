#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include "./libft/libft.h"
#include <sys/wait.h>
#include <dirent.h>
#include <errno.h>
#include <termios.h>

void	handler(int sig_number)
{
	if (sig_number == SIGINT)
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

	printf("ECHOCTL: %d\n", ECHOCTL);
	printf("TCSANOW: %d\n", TCSANOW);
	printf("SIGINT: %d\n", SIGINT);
	printf("SIGQUIT: %d\n", SIGQUIT);
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	signal(SIGINT, handler);
	signal(SIGQUIT, SIG_IGN);
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
