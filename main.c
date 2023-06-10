#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <readline/readline.h>
#include "./libft/libft.h"

typedef struct s_line
{
	char	*string;
}	t_line;

typedef struct s_process
{
	t_line	line;
}	t_process;

typedef struct s_data
{
	t_process	*process;
}	t_data;

void	free_data(t_data *data)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		free(data->process[i].line.string);
		i++;
	}
	free(data->process);
}

void	print_data(t_data *data)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		printf("data->process[%d].line.string: %s\n", i, data->process[i].line.string);
		i++;
	}
}

void	fill_process_data(t_data *data)
{
	int	i;
	
	i = 0;
	while (i < 3)
	{
		data->process[i].line.string = ft_strdup("process line");
		if (data->process[i].line.string == (void *) 0)
			perror("");
		i++;
	}
}

void	malloc_process(t_data *data)
{
	data->process = (t_process *) malloc(sizeof(t_process) * 3);
	if (data->process == (void *) 0)
		perror("");
}

int	main(void)
{
	char	*line;

	line = readline("minishell> ");
	if (line == (void *) 0)
		perror("");
	printf("line: %s\n", line);
	/*
	t_data	data;

	malloc_process(&data);
	fill_process_data(&data);
	print_data(&data);
	free_data(&data);
	system("leaks a.out");
	*/
	return (0);
}
