/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:01:34 by ayal-ras          #+#    #+#             */
/*   Updated: 2024/02/16 21:06:56 by ayal-ras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// int	ft_export(t_env *str, t_data *data)
// {
// 	int	i;

// 	i = 0;
// 	if (!str)
// 	{
// 		declare_sorted(data->envp, data);
// 		return (0);
// 	}
// 	return (0);
// }

// void	declare_sorted(t_env *str, t_data *data)
// {
// 	// int     i;
// 	char    **temp;

// 	// i = 0;
// 	str = allocate_env(data->envp);
// 	temp = ft_split(str->value, '\n');
// 	str = temp;
// 	// free_array(str->envp);
// 	// free(str);
// 	while (str != NULL)
// 	{
// 		// ft_putendl_fd(temp[i], 1);
// 		ft_putstr_fd("declare -x ", 1);
// 		ft_putendl_fd(str->value, 1);
// 		str = str->next;
// 		// free(temp[i]);
// 		// i++;
// 	}
// 	// free_array(temp);
// }

int	ft_export(char *str, t_data *data)
{
	t_env	*env_duplicate;
	char	**token;

	env_duplicate = duplicate_env(data->envp);
	// ft_putstr_fd(&str[6], 1);
	token = ft_split(str, ' ');
	if (token[1] == NULL)
	{
		declare_sorted(env_duplicate);
		return (0);
	}
	else
	{
		ft_putendl_fd("\033[31mnot working or more arguments", 2);
		return (0);
	}
	// Handle exporting specific environment variables (not implemented yet)
	return (1);
}

void	declare_sorted(t_env *head)
{
	char	**temp;
	char	*str;
	int		i;

	str = env_str(head);
	temp = ft_split(str, '\n');
	free(str);
	i = 0;
	while (temp[i])
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putendl_fd(temp[i], 1);
		i++;
	}
	free_array(temp);
}

size_t	size_env(t_env *lst)
{
	size_t	lst_len;

	lst_len = 0;
	while (lst && lst->next != NULL)
	{
		if (lst->value != NULL)
		{
			lst_len += ft_strlen(lst->value);
			lst_len++;
		}
		lst = lst->next;
	}
	return (lst_len);
}

char	*env_str(t_env *env)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = malloc(sizeof(char) * size_env(env) + 1);
	if (!str)
		return (NULL);
	while (env && env->next != NULL)
	{
		if (env->value != NULL)
		{
			j = 0;
			while (env->value[j])
				str[i++] = env->value[j++];
		}
		if (env->next->next != NULL)
			str[i++] = '\n';
		env = env->next;
	}
	str[i] = '\0';
	return (str);
}
