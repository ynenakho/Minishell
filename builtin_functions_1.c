/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_functions_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <ynenakho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 14:06:42 by ynenakho          #+#    #+#             */
/*   Updated: 2019/03/22 23:24:35 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *g_builtin_str[] = {"cd", "exit", "help", "env", "setenv", "unsetenv"};

int (*g_builtin_func[])(char **) = {&msh_cd, &msh_exit, &msh_help, &msh_env,
	&msh_setenv, &msh_unsetenv};

int	msh_env(char **args)
{
	print_env();
	return (1);
	free(args);
}

int	msh_unsetenv(char **key)
{
	if (ft_strcmp(search_by_key(key[1]), "EMPTY") != 0)
		delete_list_env(key[1]);
	return (1);
}

int	msh_setenv(char **args)
{
	char	**tmp;

	if (!args[1])
		return (1);
	if (ft_strcmp("=", args[1]) == 0)
	{
		ft_printf("IDI NA HUY!\n");
		return (1);
	}
	if (ft_strchr(args[1], '=') == NULL)
	{
		if (args[2])
			action_setenv(args[1], args[2]);
		else
			action_setenv(args[1], NULL);
	}
	else
	{
		tmp = ft_strsplit(args[1], '=');
		action_setenv(tmp[0], tmp[1]);
		delete_double_pointer(tmp);
	}
	return (1);
}
