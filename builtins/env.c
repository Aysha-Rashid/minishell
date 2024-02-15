/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:27:38 by ayal-ras          #+#    #+#             */
/*   Updated: 2024/02/15 17:17:53 by ayal-ras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// char	*allocate_env(char **env)
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
t_env	*duplicate_node(char *str)
{
	t_env	*new_node;

	new_node = malloc(sizeof(t_env));
	if (!new_node)
		return (NULL);
	new_node->value = ft_strdup(str);
	new_node->next = NULL;
	return (new_node);
}

t_env	*allocate_env(char **env)
{
	t_env	*head;
	t_env	*temp;
	t_env	*node;
	int		i;

	i = 0;
	temp = NULL;
	head = NULL;
	while (env[i])
	{
		node = duplicate_node(env[i]);
		if (!node)
		{
			free_env_list(head);
			return (NULL);
		}
		if (!head)
			head = node;
		else
			temp->next = node;
		temp = node;
		i++;
	}
	return (head);
}

int	ft_env(t_data *data)
{
	t_env	*temp;

	temp = data->envp;
	if (temp)
	{
		while (temp != NULL)
		{
			ft_putendl_fd(temp->value, 1);
			temp = temp->next;
		}
		return (EXIT_SUCCESS);
	}
	else
		return (EXIT_FAILURE);
}

t_env	*duplicate_env(t_env *env) // might need it later for export
{
	t_env	*head = NULL;
	t_env	*temp = NULL;

	while (env != NULL)
	{
		if (head == NULL)
		{
			head = malloc(sizeof(t_env));
			temp = head;
		}
		else
		{
			temp->next = malloc(sizeof(t_env));
			temp = temp->next;
		}
		if (temp == NULL)
			return (NULL);
		temp->value = ft_strdup(env->value);
		temp->next = NULL;
		env = env->next;
	}
	return (head);
}

void	free_env_list(t_env *head)
{
	t_env *temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp->value);
		free(temp);
	}
}

// int	ft_env(t_data *data)
// {
// 	int	i;
// 	t_env *temp;

// 	temp = data->envp;
// 	i = 0;
// 	if (temp)
// 	{
// 		while (temp && temp->next != NULL)
// 		{
// 			ft_putendl_fd(temp->value, 1);
// 			temp = temp->next;
// 			// ft_putendl_fd(data->envp->value, 2);
// 			// write(1, "1", 1);
// 			i++;
// 		}
// 		return (EXIT_SUCCESS);
// 	}
// 	return (EXIT_FAILURE);
// }