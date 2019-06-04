/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <ynenakho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 14:05:10 by ynenakho          #+#    #+#             */
/*   Updated: 2019/03/22 22:31:24 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	msh_loop(void)
{
	char	*line;
	char	**args;
	int		status;

	status = 1;
	while (status)
	{
		write(1, "minishell> ", 12);
		get_next_line(0, &line);
		args = msh_split(line);
		status = msh_execute(args);
		ft_strdel(&line);
		delete_double_pointer(args);
	}
}

int		main(void)
{
	create_env();
	msh_loop();
	return (0);
}
