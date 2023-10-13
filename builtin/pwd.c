/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyu <junyu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 18:52:40 by junyu             #+#    #+#             */
/*   Updated: 2023/06/17 19:38:08 by junyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"builtin.h"

int	pwd(void)
{
	char	*pwdstr;
	int		error;

	pwdstr = getcwd(0, 0);
	if (pwdstr == 0)
	{
		perror("pwd");
		return (1);
	}
	error = printf("%s\n", pwdstr);
	free(pwdstr);
	if (error < 0)
	{
		perror("pwd");
		return (1);
	}
	return (0);
}
