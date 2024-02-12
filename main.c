/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 12:16:37 by ayal-ras          #+#    #+#             */
/*   Updated: 2024/02/11 20:53:19 by ayal-ras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	// (void)env;
	// char *str = NULL;
	t_data	data;

	if (argv[1] || argc != 1)
	{
		ft_putendl_fd("invalid arguments", 2);
		exit(0);
	}
	// write(1, "---------------here----------------", 36);
	data.envp = allocate_env(env);
	// data.commands->cmd = argv;
	find_pwd(&data);
	prompt_loop(argv, &data);
}

void	prompt_loop(char **str, t_data *data)
{
	// (void)data;
	while (1)
	{
		*str = readline("\033[96mminishell$ \033[0m");
		if (*str && ft_strncmp(*str, "exit", 5) == 0)
		{
			ft_putendl_fd("\033[0;32msee you around 😮‍💨!\033[0m", 1);
			ft_putendl_fd("exit", 1);
			free(*str);
			exit(0);
		}
		if (valid_command(str, data) == 1)
			ft_putendl_fd("\033[31mERROR HANDLING", 2);
		// error handling here (when the command isnt valid or something goes wrong 
		// when any of the control signal is pressed)
		add_history(*str);
		// free_array(str);
		init_signal();
	}
}

void	free_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

int	valid_command(char **str, t_data *data)
{
	// data->builtin = builtin_arr(&str[0]);
	if (*str && (ft_strncmp(*str, "env", 3) == 0 || ft_strncmp(*str, "ENV", 3) == 0))
		return (ft_env(data));
	else if (*str && (ft_strncmp(*str, "pwd", 3) == 0|| ft_strncmp(*str, "PWD", 3) == 0))
		return (ft_pwd(data));
	// else if (*str && (ft_strncmp(*str, "export", 5) == 0|| ft_strncmp(*str, "EXPORT", 5) == 0))
	// 	return (ft_pwd(data));
	else if (*str && (ft_strncmp(*str, "echo", 4) == 0|| ft_strncmp(*str, "echo -n", 8) == 0))
		return (ft_echo(str));
	// else if (*str && (ft_strcmp(str, )))
	// all the builtins and commands that needs to handled (execution work)
	else if (!*str)
		prompt_loop(str, data);
	return (1);
}

void	init_signal(void)
{
	// free(str);
	signal(SIGINT, 0);
	// signal(SIGQUIT, SIG_IGN);
}

void	sigint_handler(int sig)
{
	// if (!g_global.in_heredoc)
	// 	ft_putstr_fd("\n", STDERR_FILENO);
	// if (g_global.in_cmd)
	// {
	// 	g_global.stop_heredoc = 1;
	// 	// rl_replace_line("", 0);
	// 	rl_redisplay();
	// 	// rl_done = 1;
	// 	return ;
	// }
	rl_on_new_line();
	// rl_replace_line("", 0);
	rl_redisplay();
	(void) sig;
}

// int *builtin_arr(char *str)
// {
// 	static void	*builtins[7][2] = {
// 	// {"echo", mini_echo},
// 	// {"cd", mini_cd},
// 	{"pwd", ft_pwd},
// 	// {"export", mini_export},
// 	// {"unset", mini_unset},
// 	{"env", ft_env},
// 	// {"exit", mini_exit}
// 	};
// 	int			i;

// 	i = 0;
// 	while (i < 7)
// 	{
// 		if (str)
// 		{
// 			if (!ft_strncmp(builtins[i][0], str, ft_strlen((builtins[i][0]))))
// 				return (builtins[i][1]);
// 		}
// 		i++;
// 	}
// 	return (NULL);
// }
// int ft_exit(void)
// {
//     return (0);
// }