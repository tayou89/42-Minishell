/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyu <junyu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:28:28 by junyu             #+#    #+#             */
/*   Updated: 2023/06/22 18:59:03 by junyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"excute.h"

int	pipex(t_data *data)
{
	int	num;

	g_signal = 1;
	if (data->process == (void *)0)
		return (-1);
	num = 0;
	if ((&data->process[0])->command != 0)
		num = check_builtin((&data->process[0])->command[0]);
	if (data->count.process == 1 && num != 0)
		num = parent_excute_builtin(&data->process[0], num, data);
	else
		num = child_gen(data);
	if (g_signal == 2)
		num = 130;
	return (num);
}
