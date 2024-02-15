/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:52:34 by ayal-ras          #+#    #+#             */
/*   Updated: 2024/02/12 16:56:14 by ayal-ras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
// not working
// its not considering "echo words" as seperate words but as a single string

int	ft_echo(char **argv)
{
	int	i;
	int	n_option;

	n_option = 0;
	i = 0;
	while (argv[i] && ft_strncmp(argv[i], "-n", 7) == 0)
	{
		n_option = 1;
		i++;
	}
	while (argv[i])
	{
		ft_putstr_fd(argv[i], 1);
		if (argv[i + 1] && argv[i][0] != '\0')
			write(1, " ", 1);
		i++;
	}
	if (n_option == 0)
		write(1, "\n", 1);
	return (0);
}

// int	ft_echo(char *argv)
// {
//     int	i;
//     int	n_option;

//     n_option = 0;
//     i = 0;
//     while (argv[i] && ft_strncmp(&argv[i], "-n", 2) == 0)
//     {
//         n_option = 1;
//         i += 2; // Skip "-n"
//     }
//     while (argv[i])
//     {
//         ft_putstr_fd(&argv[i], 1);
//         if (argv[i + 1] && argv[i] != '\0')
//             write(1, " ", 1);
//         i++;
//     }
//     if (n_option == 0)
//         write(1, "\n", 1);
//     return (0);
// }