/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envname_vaild_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyu <junyu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:04:34 by junyu             #+#    #+#             */
/*   Updated: 2023/06/23 20:10:46 by junyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../builtin.h"

static int	env_rule(char ch)
{
	if (ft_isdigit(ch))
		return (1);
	if (ft_isalpha(ch))
		return (2);
	if (ch == '_')
		return (3);
	return (0);
}

int	envname_vaild_check(char *name)
{
	int	i;

	i = 1;
	if (env_rule(name[0]) < 2)
		return (2);
	while (name[i] != '\0')
	{
		if (name[i] == '=')
			return (0);
		if (env_rule(name[i]) == 0)
			return (2);
		i++;
	}
	return (1);
}
