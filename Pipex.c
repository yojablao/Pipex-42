/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yojablao <yojablao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 06:45:09 by yojablao          #+#    #+#             */
/*   Updated: 2024/03/29 06:27:14 by yojablao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/pipex.h"

void	child(t_pipe lol, char **envp, int *end)
{
	int	fd;

	fd = open(lol.in, O_RDONLY, 0777);
	if (fd == -1)
		return (perror("readfile"), exit(1));
	dup2 (end[1], 1);
	dup2 (fd, 0);
	close (end[0]);
	execve (lol.path1, lol.cmd1, envp);
}

void	child2(t_pipe lol, char **envp, int *end)
{
	int	fd;

	fd = open(lol.out, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		perror ("outfile");
	dup2(end[0], 0);
	dup2(fd, 1);
	close(end[1]);
	execve(lol.path2, lol.cmd2, envp);
}

void	pip(t_pipe pex, char **envp)
{
	int		fd[2];
	pid_t	id2;
	pid_t	id;

	if (pipe(fd) == -1)
		return (perror("pipefail"), exit(1));
	id = fork();
	if (id == -1)
		return (perror("forkfail"), exit(1));
	if (id == 0)
		child(pex, envp, fd);
	else
	{
		id2 = fork();
		if (id2 == -1)
			return (perror("forkfail"), exit(1));
		if (id2 == 0)
		{
			waitpid(id, NULL, 0);
			child2(pex, envp, fd);
		}
		waitpid(id, NULL, 0);
		close(fd[0]);
		close(fd[1]);
	}
}

int	main(int c, char **v, char **envp)
{
	t_pipe	pex;

	if (!envp)
		exit(0);
	if (c == 5)
	{
		pex.in = v[1];
		pex.out = v[4];
		pex.cmd1 = ft_split(v[2], ' ');
		pex.cmd2 = ft_split(v[3], ' ');
		if (!pex.cmd1 || !pex.cmd2)
			return (1);
		pex.path1 = pars(v[2], envp);
		pex.path2 = pars(v[3], envp);
		pip(pex, envp);
		free_struct(&pex);
	}
	else
	{
		perror("argsfail");
		exit(1);
	}
}
