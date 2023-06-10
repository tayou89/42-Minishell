/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 22:46:35 by tayou             #+#    #+#             */
/*   Updated: 2023/06/11 00:07:59 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <dirent.h>
# include <termios.h>
# include "./libft/libft.h"

# define STDIN		0

# define T_ECHOCTL	64
# define T_TCSANOW	0

# define S_SIGINT	2
# define S_SIGQUIT	3
# define S_SIG_IGN	(void (*)(int))1
# define S_SIG_ERR	((void (*)(int))-1)

# define SYNTAX_ERR	258

# define TRUE		1
# define FALSE		0

typedef struct s_list
{
	char			*string;
	struct s_node	*next;
	struct s_node	*last;
}	t_list;

typedef struct s_envp
{
	char	**array;
	char	**cmd_directory;
	t_list	*list;
}	t_envp;

typedef struct s_terminal
{
	struct termios	initial_setting;
	struct termios	changed_setting;
}	t_terminal;

typedef struct s_input
{
	char	*line;
	char	**space_split;
}	t_input;

typedef struct s_count
{
	int	pipe;
	int	process;
}	t_count;

typedef struct s_path
{
	char	*cmd;
	char	*infile;
	char	*outfile;
}	t_path;

typedef struct s_fd
{
	int	infile;
	int	outfile;
	int	pipe[2];
}	t_fd;

typedef struct s_flag
{
	int	heredoc_exist;
}	t_flag;

typedef struct s_process
{
	char	*line;
	char	**cmd;
	char	*stop_string;
	t_path	path;
	t_fd	fd;
	t_flag	flag;
}	t_process;

typedef struct s_data
{
	t_envp			envp
	t_terminal		terminal;
	t_input			input;
	t_count			count;
	t_process		*process;
	pid_t			*pid;
}	t_data;

void	check_argc(int argc);

void	make_initial_setting(char **envp, t_data *data);
void	handle_signal(t_data *data);

void	get_input_and_process_data(t_data *data);
void	check_line_exception(t_data *data);

int		check_string_is_pipe(char *string);
int		check_string_is_redirection(char *string);

void	execute_error_process(char *error, int exit_number, t_data *data);

void	free_every_mallocated_data(t_data *data);
void	free_1d_array(void *array);
void	free_2d_array(void **array);

#endif
