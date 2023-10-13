/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:33:42 by tayou             #+#    #+#             */
/*   Updated: 2023/06/21 11:43:54 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_argc(int argc, char **argv)
{
	if (argc != 1 || argv[0] == (void *) 0)
	{
		printf("Error.\n");
		printf("Wrong argument.\n");
		exit(0);
	}
}
