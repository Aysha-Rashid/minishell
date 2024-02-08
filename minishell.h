/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 12:45:58 by ayal-ras          #+#    #+#             */
/*   Updated: 2024/02/08 17:51:46 by ayal-ras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#include <readline/readline.h>
#include "libft/libft.h"
// #include "pipex/pipex.h"

// #define	WRONG_MESSAGE "\033[31mWrong input"
#define PIPE 6
#define INFILE 5
#define STDIN 0
#define STDOUT 1
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
	int		pid_1;
	int		pid_2;
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