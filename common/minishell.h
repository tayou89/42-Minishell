/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:36:39 by tayou             #+#    #+#             */
/*   Updated: 2023/06/26 11:48:51 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../parsing/parsing.h"
# include "../builtin/builtin.h"
# include "../excute/excute.h"

void	check_argc(int argc, char **argv);
void	make_initial_setting(char **envp, t_data *data);
void	handle_signal(t_data *data);
void	get_input_and_process_data(t_data *data);

#endif
