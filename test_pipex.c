/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvieira- <yvieira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:35:20 by yvieira-          #+#    #+#             */
/*   Updated: 2025/01/12 17:10:16 by yvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char **get_path(char **env)
{
	int i = 0;
	if(!env)
		return (NULL);
	
	while (env[i] && ft_strncmp(env[i], "PATH", 4) != 0)
		i++;
	if (!env)
		return (NULL);
	return (ft_split(*env, ':'));
}

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

int main(int argc, char **argv, char **env)
{
	char **all_paths = get_path(env);
	while(**all_paths)
	{
		printf("%s/n", *all_paths);
		all_paths++;
	}
	char **first_cmd = split_first_cmd(*argv);
	while(**first_cmd)
	{
		printf("%s/n", *first_cmd);
		first_cmd++;
	}
	return 0;
}