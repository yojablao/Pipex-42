/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yojablao <yojablao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 06:45:13 by yojablao          #+#    #+#             */
/*   Updated: 2024/03/29 06:27:28 by yojablao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef struct s_t
{
	char	*in;
	char	**cmd1;
	char	**cmd2;
	char	*path2;
	char	*path1;
	char	*out;
}	t_pipe;

char	*pars(char *c, char **envp);
void	free_split(char **str);
char	*find_path(char *cmd, char **envp);
void	free_struct(t_pipe *struc);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
void	free_split(char **str);

#endif
