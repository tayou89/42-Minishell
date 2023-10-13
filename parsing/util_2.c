/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 12:31:14 by tayou             #+#    #+#             */
/*   Updated: 2023/06/26 11:33:31 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_string_has_env(char *string)
{
	int	i;

	if (string == (void *) 0)
		return (FALSE);
	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == '$')
		{
			if (string[i + 1] == '?')
				return (TRUE);
			else if (check_env_delimeter(string[i + 1]) == FALSE)
				return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

int	check_env_delimeter(char character)
{
	if (ft_isalnum(character) == TRUE || character == '_')
		return (FALSE);
	else
		return (TRUE);
}

int	check_quote_is_closed(int index, char quote, char *line)
{
	index++;
	while (line[index] != '\0')
	{
		if (line[index] == quote)
			return (TRUE);
		index++;
	}
	return (FALSE);
}

int	check_string_is_same(char *string_1, char *string_2)
{
	int	strncmp_return;

	strncmp_return = ft_strncmp(string_1, string_2, ft_strlen(string_2));
	if (strncmp_return == 0 && string_1[ft_strlen(string_2)] == '\0')
		return (TRUE);
	else
		return (FALSE);
}

void	check_syntax_error(t_process *process, t_data *data)
{
	if (process->string_type == INFILE
		|| process->string_type == HEREDOC
		|| process->string_type == OUTFILE_TRUNC
		|| process->string_type == OUTFILE_APPEND)
	{
		if (data->index.process == data->count.process - 1)
			execute_error_process("newline", SYNTAX_ERR, data);
		else
			execute_error_process("|", SYNTAX_ERR, data);
	}
}
