/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurivieiradossantos <yurivieiradossanto    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:24:09 by yvieira-          #+#    #+#             */
/*   Updated: 2025/01/11 22:15:27 by yurivieirad      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int	main( int argc, char* argv[])
{
	if(argc != 5)
		EXIT_FAILURE;
	if(!argv[2] || !argv[3])
		EXIT_FAILURE;

	return processe_forks(argc, argv, **env);
	
}
