/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyu <junyu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:26:45 by junyu             #+#    #+#             */
/*   Updated: 2023/06/21 18:00:07 by junyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCUTE_H
# define EXCUTE_H
# include "../common/minishell.h"
# include<errno.h>
# include <unistd.h>

//create.c
int		parent_excute_builtin(t_process *process, int exnum, t_data *data);
int		**makepipe(int argc);
int		pidwait(int *savepid, int argc);
int		child_gen(t_data *data);

//excute.c
int		excute(t_process *process, char **env, t_data *data);
char	*makedir(char *command, char **env);
char	**findpath(char **env);
void	dcharfree(char **str, int i);
char	*findexec(char **path, char *slash);

//pipex.c
int		pipex(t_data *data);

//dup.c
int		dupinfile(int fd, t_node *list, int flag);
int		dupoutfile(int fd, t_node *list, int flag);

//fork.c
void	childclosefd(int **pipefd, int argc, int where);
int		*makeprocess(int argc, t_data *argv, char **env, int **pipefd);
void	closefd(int **pipefd, int argc);

#endif
