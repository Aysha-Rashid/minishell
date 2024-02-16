/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:52:34 by ayal-ras          #+#    #+#             */
/*   Updated: 2024/02/16 20:45:47 by ayal-ras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_echo(char *argv)
{
	char	**token;
	int		n_option;
	int		i;

	token = ft_split(argv, ' ');
	n_option = 0;
	i = 1;
	while (token[i] && ft_strncmp(token[i], "-n", 7) == 0)
	{
		n_option = 1;
		i++;
	}
	while (token[i])
	{
		ft_putstr_fd(token[i], 1);
		if (token[i + 1] && token[i][0] != '\0')
			write(1, " ", 1);
		i++;
	}
	if (n_option == 0)
		write(1, "\n", 1);
	return (0);
}

// int ft_echo(char *argv) {
//     int i = 1;
//     int n_option = 0;

//     // Check for -n option
//     if (argv[1] && !strcmp(argv[1], "-n")) {
//         n_option = 1;
//         i = 2; // Skip the -n option
//     }

//     // Print arguments
//     while (argv[i]) {
//         write(1, argv[i], ft_strlen(argv[i])); // Print argument
//         if (argv[i + 1]) {
//             write(1, " ", 1); // Print space if not the last argument
//         }
//         i++;
//     }

//     // Print newline if -n option not provided
//     if (n_option == 0) {
//         write(1, "\n", 1);
//     }

//     return 0;
// }
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