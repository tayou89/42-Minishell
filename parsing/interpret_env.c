/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyu <junyu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 00:46:59 by tayou             #+#    #+#             */
/*   Updated: 2023/06/26 11:11:01 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	split_string_by_env(t_node *node, t_process *process, t_data *data);
void	make_env_list(t_node *node, t_process *process, t_data *data);
t_node	*change_env_node_string(t_node *env_node, t_data *data);
char	*get_env_value(char *string, char **envp, t_data *data);

void	interpret_env(t_node *quote_node, t_process *process, t_data *data)
{
	char	*joined_string;

	process->string_type = NOT_ENV;
	while (quote_node != (void *) 0)
	{
		if (quote_node->string_type == DOUBLE_QUOTE
			&& check_string_has_env(quote_node->string) == TRUE)
		{
			split_string_by_env(quote_node, process, data);
			process->env_list = change_env_node_string(process->env_list, data);
			joined_string = join_every_node_string(process->env_list, data);
			free_1d_array(quote_node->string);
			quote_node->string = joined_string;
			free_linked_list(&process->env_list);
		}
		quote_node = quote_node->next;
	}
}

void	split_string_by_env(t_node *node, t_process *process, t_data *data)
{
	char	character;
	char	next;
	int		i;

	process->index.string = 0;
	while (node->string[process->index.string] != '\0')
	{
		i = process->index.string;
		character = node->string[i];
		next = node->string[i + 1];
		if ((character == '$' && next == '?')
			|| (character == '$' && check_env_delimeter(next) == FALSE))
			make_env_list(node, process, data);
		else
		{
			if (process->index.start < 0)
				process->index.start = process->index.string;
			process->count.character++;
			process->index.string++;
		}
	}
	make_string_list(node->string, process, data);
}

void	make_env_list(t_node *node, t_process *process, t_data *data)
{
	if (process->count.character > 0)
		make_string_list(node->string, process, data);
	process->string_type = ENV;
	process->index.string++;
	process->index.start = process->index.string;
	if (node->string[process->index.string] == '?'
		|| ft_isdigit(node->string[process->index.string]) == TRUE)
	{
		process->count.character++;
		process->index.string++;
		make_string_list(node->string, process, data);
		return ;
	}
	while (check_env_delimeter(node->string[process->index.string]) == FALSE)
	{
		process->count.character++;
		process->index.string++;
	}
	make_string_list(node->string, process, data);
}

t_node	*change_env_node_string(t_node *env_node, t_data *data)
{
	t_node	*head;
	char	*env_value;

	head = env_node;
	while (env_node != (void *) 0)
	{
		if (env_node->string_type == ENV)
		{
			env_value = get_env_value(env_node->string, data->envp, data);
			free_1d_array(env_node->string);
			env_node->string = get_duplicated_string(env_value, data);
		}
		env_node = env_node->next;
	}
	return (head);
}

char	*get_env_value(char *string, char **envp, t_data *data)
{
	int	equal_index;
	int	length;
	int	i;

	if (string[0] == '?')
		return (ft_itoa(data->exit_status));
	if (ft_isdigit(string[0]) == TRUE)
		return ((void *) 0);
	i = 0;
	while (envp[i] != (void *) 0)
	{
		equal_index = find_character_index(envp[i], '=');
		if (equal_index >= (int) ft_strlen(string))
			length = equal_index;
		else
			length = ft_strlen(string);
		if (ft_strncmp(string, envp[i], length) == 0)
			return (&envp[i][equal_index + 1]);
		i++;
	}
	return ((void *) 0);
}
