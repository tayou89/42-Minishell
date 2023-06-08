/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 22:46:35 by tayou             #+#    #+#             */
/*   Updated: 2023/06/08 23:08:37 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <dirent.h>
# include <termios.h>
# include "./libft/libft.h"

# define STDIN		0

# define T_ECHOCTL	64
# define T_TCSANOW	0

# define S_SIGINT	2
# define S_SIGQUIT	3
# define S_SIG_IGN	(void (*)())1






#endif
