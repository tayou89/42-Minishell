/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_redirection_process.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:02:16 by tayou             #+#    #+#             */
/*   Updated: 2023/06/24 18:01:02 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	define_next_string_type(t_process *process, t_data *data);
void	get_redirection(t_process *process, t_data *data);
int		get_redirection_size(t_process *process);

void	execute_redirection_process(t_process *process, t_data *data)
{
	if (process->count.character > 0)
		make_string_list(process->line, process, data);
	get_redirection(process, data);
	define_next_string_type(process, data);
	free(process->redirection);
	process->redirection = (void *) 0;
	if (process->line[process->index.line] == '\0')
		check_syntax_error(process, data);
}

void	get_redirection(t_process *process, t_data *data)
{
	int		redirection_start;
	int		size;

	redirection_start = process->index.line;
	size = get_redirection_size(process);
	process->redirection = \
		get_sub_string(process->line, redirection_start, size, data);
}

int	get_redirection_size(t_process *process)
{
	int	size;

	size = 0;
	while (process->line[process->index.line] == '<'
		|| process->line[process->index.line] == '>')
	{
		size++;
		process->index.line++;
	}
	return (size);
}

void	define_next_string_type(t_process *process, t_data *data)
{
	char	*redirection;

	redirection = process->redirection;
	if (ft_strncmp(redirection, "<", ft_strlen(redirection)) == 0)
		process->string_type = INFILE;
	else if (ft_strncmp(redirection, "<<", ft_strlen(redirection)) == 0)
	{
		process->string_type = HEREDOC;
		process->flag.heredoc_exist = TRUE;
		process->count.heredoc++;
	}
	else if (ft_strncmp(redirection, ">", ft_strlen(redirection)) == 0)
		process->string_type = OUTFILE_TRUNC;
	else if (ft_strncmp(redirection, ">>", ft_strlen(redirection)) == 0)
		process->string_type = OUTFILE_APPEND;
	else
		execute_error_process(redirection, SYNTAX_ERR, data);
}
