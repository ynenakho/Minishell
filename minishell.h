/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <ynenakho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 14:05:57 by ynenakho          #+#    #+#             */
/*   Updated: 2019/03/22 23:07:20 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <sys/wait.h>
# include <stdio.h>
# include <errno.h>
# include "libft/libft.h"

typedef struct	s_node
{
	char			*type;
	char			*data;
	struct s_node	*next;
}				t_node;

typedef struct	s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}				t_env;

void			delete_double_pointer(char **obj);
t_env			*g_ptm;
extern char		*g_builtin_str[];
extern int		(*g_builtin_func[]) (char **);
int				msh_cd(char **args);
int				msh_help(char **args);
int				msh_exit(char **a);
int				msh_setenv(char **args);
int				msh_unsetenv(char **name);
int				msh_env(char **args);
int				msh_num_builtins();
void			add_to_env(char *key, char *value);
void			print_env();
void			create_env();
char			*search_by_key(char *key);
void			replace_value(char *key, char *new_value);
void			action_setenv(char *key, char *value);
void			free_node(t_env *list);
void			delete_list_env(char *key);
char			*ft_update(char *str, char *update);
int				ft_list_size_env (t_env *root);
char			**list_to_arr_env(t_env *list);
int				ft_list_size(t_node *root);
char			**list_to_arr(t_node *list);
char			*valid_tilda(char *type, char *data);
char			*manage_dollar(char *type, char *data);
t_node			*add_to_list(t_node *list, char *type, char *data);
int				ft_quote_checker (char *str);
char			**msh_split(char *str);
char			*msh_read_line(void);
void			print_command(char *path, char **argv);
int				check_if_path_exists(char **p, char *path, char **args);
int				find_command(char **args);
void			find_command_in_dirs(char **d_comm);
int				msh_execute(char **args);
void			msh_loop(void);
void			lstdel(t_node **list);

#endif
