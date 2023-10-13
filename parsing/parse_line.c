/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyu <junyu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:19:27 by tayou             #+#    #+#             */
/*   Updated: 2023/06/26 11:30:57 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int		check_exception(t_data *data);
void	initialize_struct_data(t_data *data);

void	parse_line(t_data *data)
{
	if (check_exception(data) == TRUE)
		return ;
	initialize_struct_data(data);
	get_pipe_count(data);
	malloc_process(data);
	get_process_line(data);
	get_process_string_list(data);
	if (data->flag.syntax_error == TRUE)
		return ;
	interpret_string_in_list(data);
	get_command_array(data);
	make_heredoc_file(data);
}

int	check_exception(t_data *data)
{
	int	i;

	i = 0;
	while (data->line[i] == ' ')
		i++;
	if (data->line[i] == '\0')
		return (TRUE);
	else
		return (FALSE);
}

void	initialize_struct_data(t_data *data)
{
	data->count.pipe = 0;
	data->count.process = 0;
	data->process = (void *) 0;
	data->flag.syntax_error = FALSE;
}
