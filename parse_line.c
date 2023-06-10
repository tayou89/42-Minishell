/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:19:27 by tayou             #+#    #+#             */
/*   Updated: 2023/06/11 00:28:00 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_line(t_data *data)
{
	split_line_by_space(data);
	check_line_exception(data);
	get_process_data(data);
}

void	split_line_by_space(t_data *data)
{
	data->input.space_split = ft_split(data->input.line, ' ');
	if (data->input.space_split == (void *) 0)
		execute_error_process((void *) 0, 1, data);
}
