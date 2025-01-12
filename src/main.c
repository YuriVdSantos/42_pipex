/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvieira- <yvieira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 12:43:02 by yvieira-          #+#    #+#             */
/*   Updated: 2025/01/12 15:25:11 by yvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pipex.h"

int	main( int argc, char **argv, char **env)
{
	if(argc != 5)
		EXIT_FAILURE;
	if(!argv[2] || !argv[3])
		EXIT_FAILURE;

	return pipex(argc, argv, env);
	
}