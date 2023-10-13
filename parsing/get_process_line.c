/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_process_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyu <junyu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 00:41:07 by tayou             #+#    #+#             */
/*   Updated: 2023/06/24 17:58:10 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	get_process_line_by_pipe(t_data *data);
void	execute_pipe_process(t_data *data);
void	increase_data_to_next_quote(char quote, t_data *data);
void	get_process_line_by_substring(t_data *data);

void	get_process_line(t_data *data)
{
	data->index.process = 0;
	data->index.line = 0;
	data->index.start = 0;
	data->count.character = 0;
	get_process_line_by_pipe(data);
}

void	get_process_line_by_pipe(t_data *data)
{
	char	*line;
	char	character;

	line = data->line;
	while (line[data->index.line] != '\0')
	{
		character = line[data->index.line];
		if (character == '|')
			execute_pipe_process(data);
		else if ((character == '\'' || character == '\"')
			&& check_quote_is_closed(data->index.line, character, line))
			increase_data_to_next_quote(character, data);
		else
			data->count.character++;
		data->index.line++;
	}
	get_process_line_by_substring(data);
}

void	execute_pipe_process(t_data *data)
{
	get_process_line_by_substring(data);
	data->index.process++;
	data->index.start = data->index.line + 1;
	data->count.character = 0;
}

void	increase_data_to_next_quote(char quote, t_data *data)
{
	data->count.character++;
	data->index.line++;
	while (data->line[data->index.line] != quote)
	{
		data->count.character++;
		data->index.line++;
	}
	data->count.character++;
}

void	get_process_line_by_substring(t_data *data)
{
	int		i;

	data->process[data->index.process].line = \
	get_sub_string(data->line, data->index.start, data->count.character, data);
	i = 0;
	while (data->process[data->index.process].line[i] == ' ')
		i++;
	if (data->process[data->index.process].line[i] == '\0')
	{
		free(data->process[data->index.process].line);
		data->process[data->index.process].line = (void *) 0;
	}
}
