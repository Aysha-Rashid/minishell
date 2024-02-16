/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 12:16:37 by ayal-ras          #+#    #+#             */
/*   Updated: 2024/02/16 21:05:52 by ayal-ras         ###   ########.fr       */
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
	data.commands = (t_commands *)malloc(sizeof(t_commands));
	if (data.commands == NULL)
		exit(EXIT_FAILURE);
	parse_env(&data, env);
	find_pwd(&data);
	prompt_loop(*argv, &data);
}

void	prompt_loop(char *str, t_data *data)
{
	char	*trimmed_cmd;

	while (1)
	{
        str = readline("\033[96mminishell$ \033[0m");
        if (str == NULL)
            continue;
        // if (data->cmd)
        //     free(data->cmd);
        data->cmd = ft_strdup(str);
        trimmed_cmd = ft_strtrim(str, " ");
		free(str);
		if (trimmed_cmd && ft_strncmp(trimmed_cmd, "exit", 5) == 0)
		{
			ft_putendl_fd("\033[0;32msee you around 😮‍💨!\033[0m", 1);
			ft_putendl_fd("exit", 1);
			free(trimmed_cmd);
			exit(0);
		}
		if (valid_command(trimmed_cmd, data) == 1)
			ft_putendl_fd("\033[31mERROR HANDLING", 2);
		add_history(trimmed_cmd);
		// token_reader(data);
		free(trimmed_cmd);
	}
	// free_array(str);
}

// int	token_reader(t_data *tools)
// {
// 	int		i;
// 	int		j;

// 	i = 0;
// 	while (tools->args[i])
// 	{
// 		j = 0;
// 		i += skip_spaces(tools->args, i);
// 		if (check_token(tools->args[i]))
// 			j = handle_token(tools->args, i, &tools->lexer_list);
// 		else
// 			j = read_words(i, tools->args, &tools->lexer_list);
// 		if (j < 0)
// 			return (0);
// 		i += j;
// 	}
// 	return (1);
// }

void	free_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

int	valid_command(char *str, t_data *data)
{
	if (str && (!ft_strncmp(str, "env", 3)
			|| !ft_strncmp(str, "ENV", 3)))
		return (ft_env(data));
	else if (!ft_strncmp(str, "export", 5))
		return (ft_export(str, data));
	else if (str && (!ft_strncmp(str, "pwd", 3)
			|| !ft_strncmp(str, "PWD", 3)))
		return (ft_pwd(data));
	else if (str && (!ft_strncmp(str, "echo", 4)
			|| !ft_strncmp(str, "echo -n", 7)))
		return (ft_echo(str)); // not working with double or single qoute
	// else if (str && (ft_strcmp(str, )))
	// all the builtins and commands that needs to handled (execution work)
	else if (!str)
		prompt_loop(str, data);
	return (1);
}

int	parse_env(t_data *data, char **env)
{
	int		i;
	char	*temp;

	data->commands->path = find_paths_and_split(env);
	data->envp = allocate_env(env);
	// printf("how many times? \n");
	i = 0;
	while (data->commands->path[i])
	{
		if (ft_strncmp(&data->commands->path[i]
				[ft_strlen(data->commands->path[i]) - 1], "/", 1) != 1)
		{
			temp = ft_strjoin(data->commands->path[i], "/");
			free(data->commands->path[i]);
			data->commands->path[i] = temp;
		}
		i++;
	}
	return (0);
}

char	**find_paths_and_split(char **envp)
{
	char	*envp_path;
	char	**paths;
	int		i;

	if (!envp)
		return (NULL);
	envp_path = NULL;
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			envp_path = ft_substr(envp[i], 5, ft_strlen(envp[i]) - 5);
			break ;
		}
		// printf("how many times?");
		i++;
	}
	paths = ft_split(envp_path, ':');
	free(envp_path);
	if (!paths)
	{
		free(paths);
		return (NULL);
	}
	return (paths);
}
// int *builtin_arr(char str)
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