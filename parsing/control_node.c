/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 17:46:34 by tayou             #+#    #+#             */
/*   Updated: 2023/06/21 12:00:54 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_node	*get_new_node(char *string, int string_type, t_data *data)
{
	t_node	*new_node;

	new_node = (t_node *) malloc(sizeof(t_node));
	if (new_node == (void *) 0)
		execute_error_process("new_node", 1, data);
	new_node->string = string;
	new_node->string_type = string_type;
	new_node->next = (void *) 0;
	return (new_node);
}

t_node	*add_new_node(t_node *list, t_node *new_node)
{
	t_node	*list_copy;

	if (list == (void *) 0)
		list = new_node;
	else
	{
		list_copy = list;
		while (list_copy->next != (void *) 0)
			list_copy = list_copy->next;
		list_copy->next = new_node;
	}
	return (list);
}

t_node	*find_last_node(t_node *list)
{
	while (list->next != (void *) 0)
		list = list->next;
	return (list);
}
