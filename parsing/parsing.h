/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyu <junyu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:34:55 by tayou             #+#    #+#             */
/*   Updated: 2023/06/26 11:51:34 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdio.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <termios.h>
# include <fcntl.h>
# include <signal.h>
# include "../libft/libft.h"

# define SYNTAX_ERR		258

# define COMMAND		0
# define INFILE			1
# define HEREDOC		2
# define OUTFILE		3
# define OUTFILE_TRUNC	4
# define OUTFILE_APPEND	5
# define DOUBLE_QUOTE	6
# define SINGLE_QUOTE	7
# define ENV			8
# define NOT_ENV		9

# define TRUE			1
# define FALSE			0

typedef struct s_count
{
	int	env;
	int	pipe;
	int	process;
	int	character;
	int	command;
	int	heredoc;
}	t_count;

typedef struct s_index
{
	int	process;
	int	start;
	int	line;
	int	string;
}	t_index;

typedef struct s_flag
{
	int	syntax_error;
	int	heredoc_exist;
}	t_flag;

typedef struct s_fd
{
	int	heredoc;
}	t_fd;

typedef struct s_node
{
	char			*string;
	int				string_type;
	struct s_node	*next;
}	t_node;

typedef struct s_process
{
	char	*line;
	char	*redirection;
	char	*stop_string;
	char	**command;
	int		string_type;
	t_node	*command_list;
	t_node	*infile_list;
	t_node	*outfile_list;
	t_node	*quote_list;
	t_node	*env_list;
	t_index	index;
	t_count	count;
	t_flag	flag;
	t_fd	fd;
}	t_process;

typedef struct s_data
{
	char		**envp;
	char		*line;
	int			exit_status;
	t_count		count;
	t_index		index;
	t_flag		flag;
	t_process	*process;
}	t_data;

int		g_signal;

void	parse_line(t_data *data);
void	get_pipe_count(t_data *data);
void	malloc_process(t_data *data);
void	get_process_line(t_data *data);
void	get_process_string_list(t_data *data);
void	interpret_string_in_list(t_data *data);
void	get_command_array(t_data *data);
void	make_heredoc_file(t_data *data);

void	execute_redirection_process(t_process *process, t_data *data);
void	execute_space_process(t_process *process, t_data *data);
void	execute_quote_process(t_process *process);

void	interpret_quote(t_node *list, t_process *process, t_data *data);
void	interpret_env(t_node *quote_node, t_process *process, t_data *data);

void	make_string_list(char *string, t_process *process, t_data *data);

t_node	*get_new_node(char *string, int string_type, t_data *data);
t_node	*add_new_node(t_node *list, t_node *new_node);
t_node	*find_last_node(t_node *list);

int		find_character_index(char *string, char character);
char	*get_sub_string(char *string, int start_index, int size, t_data *data);
char	*get_duplicated_string(char *string, t_data *data);
char	*join_every_node_string(t_node *node, t_data *data);
char	*get_joined_string(char	*string_1, char *string_2, t_data *data);

int		check_string_has_env(char *string);
int		check_env_delimeter(char character);
int		check_quote_is_closed(int index, char quote, char *line);
int		check_string_is_same(char *string_1, char *string_2);
void	check_syntax_error(t_process *process, t_data *data);

void	control_d_in_parent(t_data *data);
void	control_d_in_heredoc(void);

void	free_every_mallocated_data(t_data *data);
void	free_1d_array(void *array);
void	free_2d_array(void **array);
void	free_linked_list(t_node **list);
void	free_process_data(t_data *data);
void	execute_error_process(char *error, int exit_number, t_data *data);

#endif
