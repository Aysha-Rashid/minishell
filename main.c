/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 12:16:37 by ayal-ras          #+#    #+#             */
/*   Updated: 2024/02/08 14:05:33 by ayal-ras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	// (void)env;
	char *str = NULL;
	t_data	data;

	if (argv[1] || argc != 1)
	{
		ft_putendl_fd("invalid arguments", 2);
		exit (0);
	}
	data.envp = allocate_env(env);
	find_pwd(&data);
	prompt_loop(str);
}

void	prompt_loop(char *str)
{
	// t_data *data = NULL;
	while (1)
	{
		str = readline("\033[96mminishell: \033[0m");
		if (*str && ft_strncmp(str, "exit", 5) == 0)
		{
			ft_putendl_fd("\033[0;32msee you around 😮‍💨!\033[0m", 1);
			free(str);
			break ;
		}
		free(str);
		ft_putendl_fd("\033[31mcommand output should display here", 1);
	}
}

char	**allocate_env(char **env)
{
	char	**lines_of_env;
	size_t	lines;

	lines = 0;
	while (env[lines] != NULL)
		lines++;
	lines_of_env = malloc(lines + 1);
	lines = 0;
	while (env[lines])
	{
		if (env[lines] == NULL)
		{
			free_array(lines_of_env);
			return (lines_of_env);
		}
		lines_of_env[lines] = env[lines];
		lines++;
	}
	return (lines_of_env);
}

void	free_array(char **str)
{
	int i = 0;
	while(str[i])
		free(str[i++]);
	free(str);
}
// int ft_exit(void)
// {
//     return (0);
// }