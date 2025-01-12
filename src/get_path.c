/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvieira- <yvieira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 12:43:24 by yvieira-          #+#    #+#             */
/*   Updated: 2025/01/12 15:20:31 by yvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pipex.h"

char	**ft_split(char const *s, char c);
int	ft_strncmp(const char *str1, const char *str2, size_t n);


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