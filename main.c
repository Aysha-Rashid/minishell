/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 12:16:37 by ayal-ras          #+#    #+#             */
/*   Updated: 2024/02/15 16:53:16 by ayal-ras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	if (argv[1] || argc != 1)
	{
		ft_putendl_fd("invalid arguments", 2);
		exit(0);
	}
	data.envp = allocate_env(env);
	find_pwd(&data);
	prompt_loop(argv, &data);
}

void	prompt_loop(char **str, t_data *data)
{
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
		add_history(*str);
	}
		free_array(str);
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
	// t_env *env_copy = duplicate_env(data->envp);
	// data->builtin = builtin_arr(&str[0]);
	// write(1, "1", 1);
	if (*str && (ft_strncmp(*str, "env", 4) == 0
			|| ft_strncmp(*str, "ENV", 4) == 0))
		return (ft_env(data));
	else if (*str && ft_strncmp(*str, "export", 6) == 0)
		return (ft_export(str, data));
	else if (*str && (ft_strncmp(*str, "pwd", 4) == 0
			|| ft_strncmp(*str, "PWD", 4) == 0))
		return (ft_pwd(data));
	else if (*str && (ft_strncmp(*str, "echo", 5) == 0
			|| ft_strncmp(*str, "echo -n", 8) == 0))
		return (ft_echo(str));
	// else if (*str && (ft_strcmp(str, )))
	// all the builtins and commands that needs to handled (execution work)
	else if (!*str)
		prompt_loop(str, data);
	return (1);
}


// char	**allocate_env(char **env)
// {
// 	char	**lines_of_env;
// 	size_t	lines;

// 	lines = 0;
// 	while (env[lines] != NULL)
// 		lines++;
// 	lines_of_env = malloc(sizeof(char *) *(lines + 1));
// 	if (!lines_of_env)
// 		return (NULL);
// 	lines = 0;
// 	while (env[lines] != NULL)
// 	{
// 		lines_of_env[lines] = ft_strdup(env[lines]);
// 		if (lines_of_env[lines] == NULL)
// 		{
// 			free_array(lines_of_env);
// 			return (NULL);
// 		}
// 		lines++;
// 	}
// 	lines_of_env[lines] = NULL;
// 		// write(1, "1", 1);
// 	return (lines_of_env);
// }
// int	ft_env(t_data *data)
// {
// 	t_env *temp; // temporary variable to traverse the list

// 	temp = data->envp; // temporary variable to traverse the list
// 	if (temp)
// 	{
// 		while (temp != NULL)
// 		{
// 			ft_putendl_fd(temp->value, 1);
// 			temp = temp->next;
// 		}
// 		return (EXIT_SUCCESS);
// 	}
// 	else
// 		return (EXIT_FAILURE);
// }
// void	init_signal(void)
// {
// 	// free(str);
// 	signal(SIGINT, 0);
// 	// signal(SIGQUIT, SIG_IGN);
// }

// void	sigint_handler(int sig)
// {
// 	rl_on_new_line();
// 	rl_redisplay();
// 	(void) sig;
// }

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