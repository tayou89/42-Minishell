/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyu <junyu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 12:29:51 by tayou             #+#    #+#             */
/*   Updated: 2023/06/26 11:33:49 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	find_character_index(char *string, char character)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == character)
			return (i);
		i++;
	}
	return (0);
}

char	*get_duplicated_string(char *string, t_data *data)
{
	char	*duplicated_string;

	if (string == (void *) 0)
		return ((void *) 0);
	duplicated_string = ft_strdup(string);
	if (duplicated_string == (void *) 0)
		execute_error_process("ft_strdup", 1, data);
	return (duplicated_string);
}

char	*get_sub_string(char *string, int start_index, int size, t_data *data)
{
	char	*sub_string;

	sub_string = ft_substr(string, start_index, size);
	if (sub_string == (void *) 0)
		execute_error_process("ft_substr", 1, data);
	return (sub_string);
}

char	*join_every_node_string(t_node *node, t_data *data)
{
	char	*joined_string;
	char	*temp;

	while (node != (void *) 0 && node->string == (void *) 0)
		node = node->next;
	joined_string = (void *) 0;
	temp = (void *) 0;
	while (node != (void *) 0)
	{
		temp = joined_string;
		joined_string = get_joined_string(temp, node->string, data);
		free(temp);
		node = node->next;
	}
	return (joined_string);
}

char	*get_joined_string(char	*string_1, char *string_2, t_data *data)
{
	char	*joined_string;

	if (string_1 == (void *) 0 && string_2 == (void *) 0)
		return ((void *) 0);
	else if (string_1 == (void *) 0)
		joined_string = get_duplicated_string(string_2, data);
	else if (string_2 == (void *) 0)
		joined_string = get_duplicated_string(string_1, data);
	else
	{
		joined_string = ft_strjoin(string_1, string_2);
		if (joined_string == (void *) 0)
			execute_error_process("ft_strjoin", 1, data);
	}
	return (joined_string);
}
