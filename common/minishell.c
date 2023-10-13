/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyu <junyu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 23:01:49 by tayou             #+#    #+#             */
/*   Updated: 2023/06/26 11:37:26 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	check_argc(argc, argv);
	make_initial_setting(envp, &data);
	handle_signal(&data);
	get_input_and_process_data(&data);
	return (0);
}
