/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_string_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:07:57 by tayou             #+#    #+#             */
/*   Updated: 2023/06/24 18:20:33 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	add_new_node_by_type(int type, t_node *new_node, t_process *process);
void	initialize_data_for_next_list(t_process *process);

void	make_string_list(char *string, t_process *process, t_data *data)
{
	char	*sub_string;
	t_node	*new_node;
	int		start;
	int		size;

	if (process->index.start == -1)
		return ;
	start = process->index.start;
	size = process->count.character;
	sub_string = get_sub_string(string, start, size, data);
	new_node = get_new_node(sub_string, process->string_type, data);
	add_new_node_by_type(process->string_type, new_node, process);
	initialize_data_for_next_list(process);
}

void	add_new_node_by_type(int type, t_node *new_node, t_process *process)
{
	if (type == COMMAND)
		process->command_list = add_new_node(process->command_list, new_node);
	else if (type == INFILE || type == HEREDOC)
		process->infile_list = add_new_node(process->infile_list, new_node);
	else if (type == OUTFILE_TRUNC || type == OUTFILE_APPEND)
		process->outfile_list = add_new_node(process->outfile_list, new_node);
	else if (type == DOUBLE_QUOTE || type == SINGLE_QUOTE)
		process->quote_list = add_new_node(process->quote_list, new_node);
	else if (type == NOT_ENV || type == ENV)
		process->env_list = add_new_node(process->env_list, new_node);
}

void	initialize_data_for_next_list(t_process *process)
{
	if (process->string_type == NOT_ENV || process->string_type == ENV)
		process->string_type = NOT_ENV;
	else if (process->string_type == SINGLE_QUOTE
		|| process->string_type == DOUBLE_QUOTE)
		process->string_type = DOUBLE_QUOTE;
	else
		process->string_type = COMMAND;
	process->index.start = -1;
	process->count.character = 0;
}
