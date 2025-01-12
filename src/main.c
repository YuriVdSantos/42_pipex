/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurivieiradossantos <yurivieiradossanto    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 10:19:49 by yurivieirad       #+#    #+#             */
/*   Updated: 2025/01/12 10:29:59 by yurivieirad      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main( int argc, char* argv[], char **env)
{
	if(argc != 5)
		EXIT_FAILURE;
	if(!argv[2] || !argv[3])
		EXIT_FAILURE;

	return pipex(argc, argv, env);
	
}