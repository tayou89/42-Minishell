/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_quote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 00:15:06 by tayou             #+#    #+#             */
/*   Updated: 2023/06/24 20:11:05 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	initialize_process_data_for_quote(t_process *process);
int		check_quote_string(t_node *node, t_process *process);
void	split_string_by_quote(t_node *node, t_process *process, t_data *data);
void	get_data_for_quote_string(char quote, char *string, t_process *process);

void	interpret_quote(t_node *node, t_process *process, t_data *data)
{
	initialize_process_data_for_quote(process);
	process->index.string = 0;
	while (node->string[process->index.string] != '\0')
	{
		if (check_quote_string(node, process) == TRUE)
			split_string_by_quote(node, process, data);
		else
		{
			if (process->index.start < 0)
				process->index.start = process->index.string;
			process->count.character++;
			process->index.string++;
		}
	}
	make_string_list(node->string, process, data);
}

void	initialize_process_data_for_quote(t_process *process)
{
	process->string_type = DOUBLE_QUOTE;
	process->index.start = -1;
	process->count.character = 0;
}

int	check_quote_string(t_node *node, t_process *process)
{
	char	*string;
	char	character;
	char	next_character;
	int		i;

	string = node->string;
	i = process->index.string;
	character = string[i];
	next_character = string[i + 1];
	if ((character == '\"' || character == '\'')
		&& check_quote_is_closed(i, string[i], string) == TRUE)
		return (TRUE);
	else if (character == '$'
		&& (next_character == '\'' || next_character == '\"'))
	{
		if (check_quote_is_closed(i + 1, string[i + 1], string) == TRUE)
		{
			process->index.string++;
			return (TRUE);
		}
	}
	return (FALSE);
}

void	split_string_by_quote(t_node *node, t_process *process, t_data *data)
{
	char	quote;

	if (process->count.character > 0)
		make_string_list(node->string, process, data);
	quote = node->string[process->index.string];
	get_data_for_quote_string(quote, node->string, process);
	make_string_list(node->string, process, data);
}

void	get_data_for_quote_string(char quote, char *string, t_process *process)
{
	if (quote == '\'')
		process->string_type = SINGLE_QUOTE;
	process->index.string++;
	process->index.start = process->index.string;
	while (string[process->index.string] != quote)
	{
		process->count.character++;
		process->index.string++;
	}
	process->index.string++;
}
