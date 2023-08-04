/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_db.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:38:41 by mcarazo-          #+#    #+#             */
/*   Updated: 2023/08/03 19:45:22 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	int		fd1;
	int		fd2;
	int		status;
	char	**cmds1;
	char	**cmds2;
	int		end[2];
	pid_t	pid;

	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	cmds1 = ft_split(argv[2], ' ');
	cmds2 = ft_split(argv[3], ' ');
	pipe(end);
	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		close(fd2);
		close(end[0]);
		dup2(fd1, STDIN_FILENO);
		dup2(end[1], STDOUT_FILENO);
		execve("/usr/bin/grep", cmds1, NULL);
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, 0);
		close(fd1);
		close(end[1]);
		dup2(end[0], STDIN_FILENO);
		dup2(fd2, STDOUT_FILENO);
		execve("/usr/bin/wc", cmds2, NULL);
	}
	//free(cmds);

	return (0);
}
