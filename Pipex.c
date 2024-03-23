#include "header/pipex.h"



int child(t_pipedata lol,  int *end)
{
    int fd;
    fd = open(lol.in_fd,O_RDONLY,0777);
    dup2(end[1],stdout);
    dup2(fd,stdin);
    close(end[0]);
    exic(lol.cmd1,lol.env_path);
}
int parent(t_pipedata pip,int *end)
{
    int fd;
    int *status;
    fd = open(pip.out_fd,O_WRONLY,0777);
    if(fd == -1)
        perror("outfile");
    close(stdin);
    close(end[1]);
    dup2(end[0],stdin);
    dup2(fd,stdout);
    exic(pip.cmd2,pip.env_path);
    wait(&status);
    printf("%i",status);
}
int main(int c, char **v ,char **envp)
{
    t_pipedata pip;
    int i;
    int fd[2];
    pid_t id;
    
    pip.in_fd = *v[1];
    pip.out_fd = *v[4];
    pip.env_path = envp;
    pip.cmd1 = *v[2];
    pip.cmd2 = *v[3];
    if(c == 5)
    {
        if(pipe(fd) == 0)
            perror("pipefail");
        if((id  = fork) == -1)
            perror("forkfail");
        if(id == 0)
            child(pip,fd);
        else
            parent(pip,fd);

    }
    else
        perror("RDFS");
}