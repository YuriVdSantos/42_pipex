/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvieira- <yvieira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 12:43:07 by yvieira-          #+#    #+#             */
/*   Updated: 2025/01/12 15:16:14 by yvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_split(char const *s, char c);

char **split_first_cmd(char *argv)
{
	char **cmd;
	if (!argv[2] || !argv[3])
		return (NULL);
	
	cmd = ft_split(&argv[2], ' ');
	if(!cmd || !cmd[0])
	{
		free(cmd);
		return (NULL);
	}
	printf("%s/n", cmd[0]);
	printf("%s/n", cmd[1]);
	return (cmd);
}

char **split_second_cmd(char *argv)
{
	char **cmd;
	if (!argv[2] || !argv[3])
		return (NULL);
	
	cmd = ft_split(&argv[3], ' ');
	if(!cmd || !cmd[0])
	{
		free(cmd);
		return (NULL);
	}
	printf("%s/n", cmd[0]);
	printf("%s/n", cmd[1]);
	return (cmd);
}