/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyu <junyu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:21:59 by junyu             #+#    #+#             */
/*   Updated: 2023/06/23 16:43:05 by junyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../builtin.h"

int	envcount(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != 0)
		i++;
	return (i);
}

int	finderase(char **envp, char *envname)
{
	int		i;
	int		len;
	char	*str;

	str = ft_strjoin(envname, "=");
	if (str == 0)
		exit(1);
	len = ft_strlen(str);
	i = 0;
	while (envp[i] != 0 && ft_strncmp(envname, envp[i], len) != 0)
		i++;
	if (envp[i] == 0)
		i = -1;
	free(str);
	return (i);
}

int	findenv(char **envp, char *envname)
{
	int			i;
	int			len;

	i = 0;
	len = ft_strchr(envname, '=') - envname + 1;
	while (envp[i] != 0 && ft_strncmp(envname, envp[i], len) != 0)
		i++;
	if (envp[i] == 0)
		return (-1);
	return (i);
}
