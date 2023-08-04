/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:38:41 by mcarazo-          #+#    #+#             */
/*   Updated: 2023/08/04 09:16:46 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**env_path(char **envp)
{
	int		i;
	char	*path;
	char	**sep_paths;
	char	**cmd_args;

	path = ft_substr(envp[2], 5, 61);
	sep_paths = ft_split(path, ':');
	i = -1;
	while (sep_paths[++i])
		sep_paths[i] = ft_join(sep_paths[i], "/");
	return (sep_paths);
}

int	check_path(char **cmd, char **envp)
{
	int		i;
	char	*path_cmd;
	char	**paths;

	i = 0;
	paths = env_path(envp);
	while (paths[i])
	{
		path_cmd = ft_strjoin(paths[i], cmd[0]);
		execve(path_cmd, cmd, envp);
		free(path_cmd);
		i++;
	}
	return (EXIT_FAILURE);
}

void	child_process1(int fd[2], int end[2], char **cmd, char **envp)
{
	close(fd[1]);
	close(end[0]);
	dup2(fd[0], STDIN_FILENO);
	dup2(end[1], STDOUT_FILENO);
	check_path(cmd, envp);
	exit(EXIT_FAILURE);
}

void	child_process2(int fd[2], int end[2], char **cmd, char **envp)
{
	close(fd[0]);
	close(end[1]);
	dup2(end[0], STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	check_path(cmd, envp);
	exit(EXIT_FAILURE);
}

void	pipex(int fd[2], char **argv, char **envp)
{
	int		status;
	char	**cmds1;
	char	**cmds2;
	int		end[2];
	pid_t	pid1;
	pid_t	pid2;

	cmds1 = ft_split(argv[2], ' ');
	cmds2 = ft_split(argv[3], ' ');
	pipe(end);
	pid1 = fork();
	if (pid1 < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid1 == 0)
		child_process1(fd, end, cmds1, envp);
	pid2 = fork();
	if (pid2 < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid2 == 0)
		child_process2(fd, end, cmds2, envp);
	close (end[0]);
	close (end[1]);
	waitpid(pid1, &status, 0);
	waitpid(pid2, &status, 0);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];

	fd[0] = open(argv[1], O_RDONLY);
	fd[1] = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644); //argc - 1
	//env_path(envp);
	if (argc < 5)
	{
		printf("No hay suficientes argumentos");
		return (0);
	}
	else if (argc == 5)
		pipex(fd, argv, envp);
	else
		printf("Trabajando en ello");
	
	//free(cmds);

	return (0);
}
