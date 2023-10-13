/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_quote_process.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:34:50 by tayou             #+#    #+#             */
/*   Updated: 2023/06/24 18:01:27 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	check_quote_is_start_of_string(t_process *process);
void	count_line_data_to_next_quote(char quote, t_process *process);

void	execute_quote_process(t_process *process)
{
	char	quote;
	int		index;

	check_quote_is_start_of_string(process);
	index = process->index.line;
	quote = process->line[process->index.line];
	if (check_quote_is_closed(index, quote, process->line) == TRUE)
		count_line_data_to_next_quote(quote, process);
	process->count.character++;
	process->index.line++;
}

void	check_quote_is_start_of_string(t_process *process)
{
	if (process->index.start < 0)
		process->index.start = process->index.line;
}

void	count_line_data_to_next_quote(char quote, t_process *process)
{
	process->count.character++;
	process->index.line++;
	while (process->line[process->index.line] != quote)
	{
		process->count.character++;
		process->index.line++;
	}
}
