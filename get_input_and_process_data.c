/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input_and_process_data.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:31:35 by tayou             #+#    #+#             */
/*   Updated: 2023/06/10 18:33:40 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_input_and_process_data(t_data *data)
{
	data->input.line = readline("minishell> ");
	while (data->input.line != (void *) 0)
	{
		parse_line(data);
	}
	execute_exit_process(data);
}

void	execute_exit_process(t_data *data)
{
	free_every_mallocated_data(data);
	printf("\033[1A");
	printf("\033[10C");
	printf(" exit\n");
	exit(0);
}
