/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_process_string_list.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 00:55:23 by tayou             #+#    #+#             */
/*   Updated: 2023/06/24 17:58:37 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	execute_syntax_error_process(t_data *data);
void	execute_other_process(t_process *process);
void	get_command_and_file_list(t_process *process, t_data *data);

void	get_process_string_list(t_data *data)
{
	t_process	*process;

	data->index.process = 0;
	while (data->index.process < data->count.process)
	{
		if (data->flag.syntax_error == TRUE)
			return ;
		process = &data->process[data->index.process];
		get_command_and_file_list(process, data);
		data->index.process++;
	}
}

void	get_command_and_file_list(t_process *process, t_data *data)
{
	char	character;

	if (process->line == (void *) 0)
	{
		execute_syntax_error_process(data);
		return ;
	}
	process->index.line = 0;
	while (process->line[process->index.line] != '\0')
	{
		character = process->line[process->index.line];
		if (character == '<' || character == '>')
			execute_redirection_process(process, data);
		else if (character == ' ')
			execute_space_process(process, data);
		else if (character == '\'' || character == '\"')
			execute_quote_process(process);
		else
			execute_other_process(process);
	}
	make_string_list(process->line, process, data);
}

void	execute_other_process(t_process *process)
{
	if (process->index.start < 0)
		process->index.start = process->index.line;
	process->count.character++;
	process->index.line++;
}

void	execute_syntax_error_process(t_data *data)
{
	if (data->index.process == data->count.process - 1)
		execute_error_process("newline", SYNTAX_ERR, data);
	else
		execute_error_process("|", SYNTAX_ERR, data);
}
