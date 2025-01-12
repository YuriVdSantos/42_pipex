/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvieira- <yvieira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 12:43:17 by yvieira-          #+#    #+#             */
/*   Updated: 2025/01/12 17:14:12 by yvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pipex.h"

int pipex(int argc, char **argv, char **env)
{
	int	infile;
	char **path;

	infile = open(argv[1], O_RDONLY, 0644);
	if(infile == -1)
		return EXIT_FAILURE;
	if(!env)
		return -1;
	if(argc != 5)
		printf("Falta argumento");
	int	fd[2];
	char **cmd;
	if (pipe(fd) == -1)
		return 1;
	cmd = split_first_cmd(*argv);
	path = get_path(env);
	int	pid1 = fork();
	if (pid1 < 0) 
		return 2;
	if(pid1 == 0)
	{
		if (dup2(fd[1], STDOUT_FILENO) == -1 || dup2(infile, STDIN_FILENO) == -1)
			// is_error(1);
		close(fd[0]);
		close(fd[1]);
		close(fd[infile]);
		// execve(, NULL);
	}
	int pid2 = fork();
	if (pid2 < 0 )
		return 3;
	int	outfile;
	outfile = open(argv[4], O_RDONLY | O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
		// is_error(2);
	if (pid2 == 0)
	{
		if (dup2(fd[0], STDIN_FILENO) == -1 || dup2(outfile, STDOUT_FILENO) == -1)
			return EXIT_FAILURE;
		close(fd[0]);
		close(fd[1]);
		execlp("more", "more", NULL);
	}
	close(fd[0]);
	close(fd[1]);
	close(fd[outfile]);

	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
