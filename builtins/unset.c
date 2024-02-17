/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 21:03:21 by ayal-ras          #+#    #+#             */
/*   Updated: 2024/02/17 21:32:37 by ayal-ras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_unset(char *str, t_data *data)
{
	char	**token;
	int		i;
	int		j;

	j = 0;
	i = 0;
	(void)data;
	token = ft_split(str, ' ');
	if (token[1] == NULL)
		return (0);
	else
	{
		
	}
	return (1);
}
