/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_space_process.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:55:25 by tayou             #+#    #+#             */
/*   Updated: 2023/06/24 18:00:39 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	pass_space(t_process *process);

void	execute_space_process(t_process *process, t_data *data)
{
	if (process->count.character > 0)
		make_string_list(process->line, process, data);
	pass_space(process);
	if (process->line[process->index.line] == '\0')
		check_syntax_error(process, data);
}

void	pass_space(t_process *process)
{
	while (process->line[process->index.line] == ' ')
		process->index.line++;
}
