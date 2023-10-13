/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:51:51 by tayou             #+#    #+#             */
/*   Updated: 2023/06/26 11:47:23 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	free_every_mallocated_data(t_data *data)
{
	if (data->line != (void *) 0)
	{
		free_1d_array(data->line);
		data->line = (void *) 0;
	}
	if (data->process != (void *) 0)
		free_process_data(data);
}

void	free_1d_array(void *array)
{
	free(array);
	array = (void *) 0;
}

void	free_2d_array(void **array)
{
	int	i;

	i = 0;
	while (array[i] != (void *) 0)
	{
		free(array[i]);
		array[i] = (void *) 0;
		i++;
	}
	free(array);
	array = (void *) 0;
}

void	free_linked_list(t_node **list)
{
	t_node	*head_copy;

	if (list == (void *) 0)
		return ;
	while (*list != (void *) 0)
	{
		head_copy = (*list)->next;
		free_1d_array((*list)->string);
		free(*list);
		*list = (void *) 0;
		*list = head_copy;
	}
}

void	execute_error_process(char *error, int exit_number, t_data *data)
{
	if (exit_number == SYNTAX_ERR && data->flag.syntax_error == FALSE)
	{
		data->exit_status = exit_number;
		data->flag.syntax_error = TRUE;
		printf("minishell: syntax error near unexpected token '%s'\n", error);
		return ;
	}
	printf("minishell: ");
	perror(error);
	free_every_mallocated_data(data);
	exit(exit_number);
}
