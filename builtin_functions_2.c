/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_functions_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <ynenakho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 14:06:33 by ynenakho          #+#    #+#             */
/*   Updated: 2019/03/22 23:05:06 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		msh_exit(char **args)
{
	return (0);
	free(args);
}

int		msh_cd(char **args)
{
	char current_pwd[64];
	char new_pwd[64];

	if (args[1] == NULL)
	{
		getwd(current_pwd);
		replace_value("OLDPWD", ft_strdup(current_pwd));
		if (chdir(search_by_key("HOME")) != 0)
			perror("msh");
	}
	else
	{
		getwd(current_pwd);
		if (!ft_strcmp("-", args[1]) && chdir(search_by_key("OLDPWD")) != 0)
			perror("msh");
		else if (!ft_strcmp("-", args[1]))
			ft_printf("%s\n", getwd(new_pwd));
		else if (chdir(args[1]) != 0)
			perror("msh");
		replace_value("OLDPWD", ft_strdup(current_pwd));
		getwd(new_pwd);
		replace_value("PWD", ft_strdup(new_pwd));
	}
	return (1);
}

int		msh_help(char **args)
{
	int i;

	i = 0;
	ft_printf(L_BLUE "You can use following commands:\n" RESET);
	while (i < 6)
	{
		ft_printf(L_MAGENTA "- %s\n" RESET, g_builtin_str[i]);
		i++;
	}
	return (1);
	free(args);
}
