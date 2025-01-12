/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurivieiradossantos <yurivieiradossanto    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 22:01:50 by yurivieirad       #+#    #+#             */
/*   Updated: 2025/01/11 22:42:18 by yurivieirad      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int processe_forks(int argc, char **argv)
{
	int	fd[2];
	if (pipe(fd) == -1)
		return 1;
	
	int	pid1 = fork();
	if (pid1 < 0) 
		return 2;
	//Need to add error handling
	if(pid1 == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execlp("ls", "ls", "-la", NULL);
	}
	int pid2 = fork();
	if (pid2 < 0 )
		return 3;
	if (pid2 == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		execlp("more", "more", NULL);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}