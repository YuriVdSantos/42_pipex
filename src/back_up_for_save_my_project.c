#include "pipex.h"

int pipex(int argc, char **argv, char **env)
{
	int	fd[2];
	char **cmd;
	if (pipe(fd) == -1)
		return 1;
	cmd = split_cmd(argv);	
	int	pid1 = fork();
	if (pid1 < 0) 
		return 2;
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