#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

char **split_cmd(char **argv);
int pipex(int argc, char **argv, char **env);
char *get_path(char **env);
