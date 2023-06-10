/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:49:58 by tayou             #+#    #+#             */
/*   Updated: 2023/06/10 20:43:23 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_error_process(char *error, int exit_number, t_data *data)
{
	if (exit_number == SYNTAX_ERR)
		printf("syntax error near unexpected token '%s'\n", error);
	else
		perror(error);
	free_every_mallocated_data(data);
	exit(exit_number);
}
