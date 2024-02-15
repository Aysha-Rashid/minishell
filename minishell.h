/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 12:45:58 by ayal-ras          #+#    #+#             */
/*   Updated: 2024/02/15 17:20:37 by ayal-ras         ###   ########.fr       */
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
	char	*cmd;
}				t_commands;

typedef struct s_env
{
	char			*value;
	char			*key;
	struct s_env	*next;
}				t_env;

typedef struct s_data
{
	char			*pwd;
	char			*old_pwd;
	t_env			*envp;
	t_commands		*commands;
	struct s_data	*next;
}				t_data;

// typedef struct s_pipex
// {
// 	char	**cmd1;
// 	char	**cmd2;
// 	char	*cmd_path1;
// 	char	*cmd_path2;
// 	int		infile;
// 	int		outfile;
// }				t_pipex;

void	prompt_loop(char **str, t_data *data);
t_env	*allocate_env(char **env);
void	free_array(char **str);
int		find_pwd(t_data *data);
int		ft_env(t_data *data);
int		ft_pwd(t_data *data);
int		ft_export(char **str, t_data *data);
void	declare_sorted(t_env *head);
int		ft_echo(char **argv);

t_env	*duplicate_node(char *str);
t_env	*duplicate_env(t_env *env);
void	free_env_list(t_env *head);
size_t	size_env(t_env *lst);
char	*env_str(t_env *env);
int		valid_command(char **str, t_data *data);

// int		count_arg(char **str);
// int		*builtin_arr(char *str);
// void	init_signal(void);
// void	sigint_handler(int sig);