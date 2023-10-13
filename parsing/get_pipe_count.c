/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pipe_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyu <junyu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 01:11:32 by tayou             #+#    #+#             */
/*   Updated: 2023/06/23 18:39:19 by junyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	increase_index_to_next_quote(int *index, char quote, char *line);

void	get_pipe_count(t_data *data)
{
	char	*line;
	int		i;

	line = data->line;
	data->count.pipe = 0;
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '|')
			data->count.pipe++;
		else if ((line[i] == '\'' || line[i] == '\"')
			&& check_quote_is_closed(i, line[i], line) == TRUE)
			increase_index_to_next_quote(&i, line[i], line);
		i++;
	}
}

void	increase_index_to_next_quote(int *index, char quote, char *line)
{
	(*index)++;
	while (line[*index] != quote)
		(*index)++;
}
