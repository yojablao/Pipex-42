#ifndef PIPEX_H
# define PIPEX_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

typedef struct s_pipexdata
{
	char		*in_fd;
	char		*out_fd;
	char	**env_path;
	char	**cmd1;
	char	*cmd2;
}				t_pipedata;

char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s);
int	ft_memcmp(const void	*s1, const void	*s2, size_t	n);

#endif