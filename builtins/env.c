/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:27:38 by ayal-ras          #+#    #+#             */
/*   Updated: 2024/02/10 20:07:59 by ayal-ras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**allocate_env(char **env)
{
	char	**lines_of_env;
	size_t	lines;

	lines = 0;
	while (env[lines] != NULL)
		lines++;
	lines_of_env = malloc(sizeof(char *) *(lines + 1));
	if (!lines_of_env)
		return (NULL);
	lines = 0;
	while (env[lines])
	{
		lines_of_env[lines] = ft_strdup(env[lines]);
		if (lines_of_env[lines] == NULL)
		{
			free_array(lines_of_env);
			return (lines_of_env);
		}
		lines++;
	}
	return (lines_of_env);
}

int	ft_env(t_data *data)
{
	int	i;

	i = 0;
	while (data->envp[i])
	{
		ft_putendl_fd(data->envp[i], 1);
		i++;
	}
	return (EXIT_SUCCESS);
}