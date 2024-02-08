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
	int	i;

	i = 0;
	while (data->envp[i])
	{
		if (!ft_strncmp(data->envp[i], "PWD=", 4))
			data->pwd = ft_substr(data->envp[i],
					4, ft_strlen(data->envp[i]) - 4);
		if (!ft_strncmp(data->envp[i], "OLDPWD=", 7))
			data->old_pwd = ft_substr(data->envp[i],
					7, ft_strlen(data->envp[i]) - 7);
		i++;
	}
	return (1);
}
