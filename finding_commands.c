#include "minishell.h"

// int		is_builtin(char *command)
// {
// 	if (ft_strncmp(command, "echo", 4) == 0)
// 		return (1);
// 	else if (ft_strncmp(command, "cd", 2) == 0)
// 		return (1);
// 	else if (ft_strncmp(command, "cat", 3) == 0)
// 		return (1);
// 	else 
// }

int	find_pwd(t_data *data)
{
	int		i;
	t_env *temp;

	i = 0;
	temp = data->envp;
	while (temp)
	{
		if (!ft_strncmp(temp->value, "PWD=", 4))
			data->pwd = ft_substr(temp->value,
					4, ft_strlen(temp->value) - 4);
		if (!ft_strncmp(temp->value, "OLDPWD=", 7))
			data->old_pwd = ft_substr(temp->value,
					7, ft_strlen(temp->value) - 7);
		temp = temp->next;
	}
	return (1);
}
