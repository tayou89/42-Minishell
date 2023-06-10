/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line_exception.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 19:27:27 by tayou             #+#    #+#             */
/*   Updated: 2023/06/11 00:21:59 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_first_string(t_data *data);
void	check_continual_pipe(t_data *data);
void	check_redirection_next_string(t_data *data);

void	check_line_excption(t_data *data)
{
	check_first_string(data);
	check_continual_pipe(data);
	check_redirection_next_string(data);
}

void	check_first_string(t_data *data)
{
	char	*first_string;

	first_strin = data->input.space_split[0];
	if (strncmp(first_string, "|", ft_strlen("|")) == 0)
		execute_error_process(first_string, SYNTAX_ERR, data);
}

void	check_continual_pipe(t_data *data)
{
	char	**string;;
	int		i;

	string = data->input.space_split;
	i = 0;
	while (string[i + 1] != (void *) 0)
	{
		if (check_string_is_pipe(string[i]) == TRUE)
		{
			if (check_string_is_pipe(string[i + 1])) == TRUE)
				execute_error_process(string[i + 1], SYNTAX_ERR, data);
		}
		i++;
	}
}

void	check_redirection_next_string(t_data *data)
{
	char	**string;
	int		i;

	string = data->input.space_split;
	i = 0;
	while (string[i] != (void *) 0)
	{
		if (check_string_is_redirection(string[i]) == TRUE)
		{
			if (check_string_is_pipe(string[i + 1]) == TRUE
				|| check_string_is_redirection(string[i + 1]) == TRUE
				|| string[i + 1] == (void *) 0)
				execute_error_process(string[i + 1], SYNTAX_ERR, data);
		}
		i++;
	}
}
