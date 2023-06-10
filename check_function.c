/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:51:56 by tayou             #+#    #+#             */
/*   Updated: 2023/06/10 18:52:55 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_string_is_pipe(char *string)
{
	if (string == (void *) 0)
		return (FALSE);
	if (ft_strncmp(string, "|", ft_strlen("|")) == 0)
		return (TRUE);
	else
		return (FALSE);
}

int	check_string_is_redirection(char *string)
{
	if (string == (void *) 0)
		return (FALSE);
	if (ft_strncmp(string, "<", ft_strlen("<")) == 0
		|| ft_strncmp(string, "<<", ft_strlen("<<")) == 0
		|| ft_strncmp(string, ">", ft_strlen(">")) == 0
		|| ft_strncmp(string, ">>", ft_strlen(">>")) == 0)
		return (TRUE);
	else
		return (FALSE);
}
