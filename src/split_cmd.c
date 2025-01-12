/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurivieiradossantos <yurivieiradossanto    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 10:01:13 by yurivieirad       #+#    #+#             */
/*   Updated: 2025/01/12 10:25:45 by yurivieirad      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char **split_cmd(char **argv)
{
	char **cmd;
	char **temp;
	int i = 0;
	while (argv[i] && ft_strncmp(argv[i], "", 3) != 0)
		i++;
	if (!argv[i])
		return (NULL);
	temp = ft_split(argv[i], ' ');
	cmd = (char **)malloc(sizeof(char *) * 3);
	cmd[0] = ft_strdup(temp[2]);
	cmd[1] = ft_strdup(temp[4]);
	if(!cmd)
		return (NULL);
	printf("%s", cmd[0]);
	printf("%s", cmd[1]);
	return (cmd);
}