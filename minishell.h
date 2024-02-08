/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 12:45:58 by ayal-ras          #+#    #+#             */
/*   Updated: 2024/02/08 13:57:16 by ayal-ras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <readline/readline.h>
#include "libft/libft.h"
#define	WRONG_MESSAGE "\033[31mWrong input"
typedef struct s_data
{
	char	**envp;
	char	*pwd;
	char	*old_pwd;
}				t_data;

typedef struct s_pipex
{
	char	**cmd1;
	char	**cmd2;
	char	*cmd_path1;
	char	*cmd_path2;
	int		infile;
	int		outfile;

}				t_pipex;

// typedef struct s_sig
// {
	
// }				t_sig;
void	prompt_loop(char *str);
char	**allocate_env(char **env);
void	free_array(char **str);
int		find_pwd(t_data *data);
// typedef struct s_mini
// {

// }               t_mini;