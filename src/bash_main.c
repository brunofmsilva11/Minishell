/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bash_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 18:54:29 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/03/31 11:24:30 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*set_environment_vars(char **envp, t_memptr memptr)
{
	t_env						*envv;

	envv = init_envv(envp);
	if (envv == NULL)
		exit_error(ENV_ERROR, memptr, NULL);
	set_envv(envv);
	return (envv);
}

void	bash_run(char **envp, t_memptr *memptr)
{
	*(memptr->lexer_list) = read_readline(*memptr);
	if (!*(memptr->lexer_list))
		return ;
	*(memptr->command_table) = parse_list(*(memptr->lexer_list), *memptr);
	if (!(*(memptr->command_table)))
		return ;
	if (g_status_flag == 8)
	{
		g_status_flag = 130;
		return ;
	}
	expand_command_table(memptr->command_table, *memptr);
	prepare_processes(memptr->command_table, envp, memptr);
}

void	update_envp(char ***envp, t_memptr *memptr, t_env *env_vars)
{
	if (*envp)
		ft_free_tabs((void **)*envp);
	*envp = ft_tabdup(env_vars->env_var);
	if (!*envp)
		exit_error(MALLOC_ERROR, *memptr, NULL);
	memptr->envp = *envp;
	free_envv(env_vars);
}

void	bash_main(char **envp, t_memptr *memptr)
{
	t_env			*env_vars;

	g_status_flag = 0;
	update_shell_level(&envp, memptr);
	env_vars = set_environment_vars(envp, *memptr);
	memptr->path_list = ft_split(getenv("PATH"), ':');
	if (!(memptr->path_list))
		exit_error(MALLOC_ERROR, *memptr, NULL);
	memptr->envp = envp;
	while (g_status_flag != EOF_SIGNAL)
	{
		set_signal();
		bash_run(envp, memptr);
		update_envp(&envp, memptr, env_vars);
		env_vars = set_environment_vars(envp, *memptr);
		clean_memory(memptr);
		update_path(envp, memptr);
	}
}
