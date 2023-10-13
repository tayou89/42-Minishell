/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_d_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyu <junyu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 21:15:53 by tayou             #+#    #+#             */
/*   Updated: 2023/06/26 11:10:03 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	control_d_in_parent(t_data *data)
{
	free_every_mallocated_data(data);
	printf("\033[u");
	printf("\033[10C");
	printf(" exit\n");
	exit(0);
}

void	control_d_in_heredoc(void)
{
	printf("\033[1A");
	printf("\033[2C");
	exit(0);
}
