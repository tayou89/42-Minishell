/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyu <junyu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 18:55:20 by junyu             #+#    #+#             */
/*   Updated: 2023/06/21 19:56:32 by junyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H
# include<unistd.h>
# include<stdio.h>
# include<errno.h>
# include<stdlib.h>
# include<string.h>
# include"../common/minishell.h"

//pwd.c
int			pwd(void);

//echo.c
int			echo(int argc, char **argv);

//env.c
int			env(char **envp);

//exit.c
int			builtin_exit(int argc, char **argv);

//cd.c 
int			cd(int argc, char **argv);

//export.c
int			export(int argc, char **argv, t_data *data);

// unset.c
int			unset(int argc, char **argv, t_data *data);

//excute_builtin.c
int			excute_builtin(int argc, char **argv, t_data *data, int exnum);
int			child_excute(int argc, char **argv, t_data *data, int exnum);
int			check_builtin(char *name);

// util/ft_ltoa.c
char		*ft_lltoa(long long number);

//util/ft_atol.c
long long	ft_atoll(const char *str);

//util/envname_vaild_check.c
int			envname_vaild_check(char *name);

//util/env_util.c
int			envcount(char **envp);
int			findenv(char **envp, char *envname);
int			finderase(char **envp, char *envname);
#endif