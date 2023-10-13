/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_string_in_list.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyu <junyu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:14:45 by tayou             #+#    #+#             */
/*   Updated: 2023/06/24 18:01:56 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	interpret_process_string(int type, t_process *process, t_data *data);
t_node	*define_list_by_type(int type, t_process *process);

void	interpret_string_in_list(t_data *data)
{
	t_process	*process;
	int			i;

	i = 0;
	while (i < data->count.process)
	{
		process = &data->process[i];
		interpret_process_string(COMMAND, process, data);
		interpret_process_string(INFILE, process, data);
		interpret_process_string(OUTFILE, process, data);
		i++;
	}
}

void	interpret_process_string(int type, t_process *process, t_data *data)
{
	t_node	*list;
	char	*joined_string;

	list = define_list_by_type(type, process);
	if (list == (void *) 0)
		return ;
	while (list != (void *) 0)
	{
		interpret_quote(list, process, data);
		if (list->string_type != HEREDOC)
			interpret_env(process->quote_list, process, data);
		joined_string = join_every_node_string(process->quote_list, data);
		free_1d_array(list->string);
		list->string = joined_string;
		free_linked_list(&process->quote_list);
		list = list->next;
	}
}

t_node	*define_list_by_type(int type, t_process *process)
{
	if (type == COMMAND)
		return (process->command_list);
	else if (type == INFILE)
		return (process->infile_list);
	else
		return (process->outfile_list);
}
