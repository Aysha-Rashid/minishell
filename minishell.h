/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 12:45:58 by ayal-ras          #+#    #+#             */
/*   Updated: 2024/02/11 20:33:26 by ayal-ras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#include <readline/readline.h>
#include "libft/libft.h"
// #include "pipex/pipex.h"

// #define	WRONG_MESSAGE "\033[31mWrong input"
#define PIPE 6
#define INFILE 5
#define STDIN 0
#define STDOUT 1
typedef struct s_commands
{
	char	**cmd;
}				t_commands;

typedef struct s_data
{
	char			**envp;
	char			*pwd;
	char			*old_pwd;
	t_commands		*commands;
	// int				*builtin;
	struct s_data	*next;
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

void	prompt_loop(char **str, t_data *data);
char	**allocate_env(char **env);
void	free_array(char **str);
int		find_pwd(t_data *data);
int		ft_env(t_data *data);
int		ft_pwd(t_data *data);
int		count_arg(char **str);
// void	count_arg(int i, char **str, int out);
int		ft_echo(char **argv);
int		*builtin_arr(char *str);
void	init_signal(void);
void	sigint_handler(int sig);
int		valid_command(char **str, t_data *data);
// typedef struct s_mini
// {

// }               t_mini;