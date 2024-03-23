#include "pipex.h"

char 	*listing(char **p,char **arg)
{
	int i;
	int j;
	char *re;
	i = 0;
	j = -1;
	while(p[i])
	{
		re = ft_strjoin(p[i],"/");
		re = ft_strjoin(re,arg[0]);
		i++;
		if(access(re,"O_X") != -1)
			return (re);
	}
	return (NULL);
}
void exic(char *c,char **envp)
{

	char	*path;
	char	**cmd;
	
	cmd = ft_split(c,' ');
	path = listing(envp,cmd);
	if(!path)
		perror("access fail");
	execve(path,cmd,envp);
}