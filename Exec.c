/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yojablao <yojablao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 06:45:05 by yojablao          #+#    #+#             */
/*   Updated: 2024/03/28 01:36:20 by yojablao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/pipex.h"

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	free_struct(t_pipe *struc)
{
	free(struc->path2);
	free(struc->path1);
	free_split(struc->cmd1);
	free_split(struc->cmd2);
}

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;
	char	*part_path;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 5) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
		{
			free_split(paths);
			return (path);
		}
		free(path);
		i++;
	}
	free_split(paths);
	return (0);
}

char	*pars(char	*c, char	**envp)
{
	char	*path;
	char	**cmd;

	cmd = ft_split(c, ' ');
	if (!cmd)
		perror("split fail");
	path = find_path(cmd[0], envp);
	if (!path)
		perror("access fail");
	free_split(cmd);
	return (path);
}
