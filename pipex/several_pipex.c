/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   several_pipex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:38:41 by mcarazo-          #+#    #+#             */
/*   Updated: 2023/08/04 11:54:52 by mcarazo-         ###   ########.fr       */
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
		//printf("%s\n", path_cmd);
		execve(path_cmd, cmd, envp);
		write(2, "pipex: ", 7);
		write(2, cmd[0], ft_strlen(cmd[0]));
		write(2, ": command not found\n", 20);
		free(path_cmd);
		i++;
	}
	free(paths);
	return (EXIT_FAILURE);
}

int	exec_process(int in[2], int out[2], char **cmd, char **envp)
{
	close(in[1]);
	close(out[0]);
	dup2(in[0], STDIN_FILENO);
	dup2(out[1], STDOUT_FILENO);
	check_path(cmd, envp);
	free(cmd);
	//printf("hola tu que tal");
	exit(EXIT_FAILURE);
}

int	child_process2(int fd[2], int end[2], char **cmd, char **envp)
{
	close(fd[0]);
	close(end[1]);
	dup2(end[0], STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	check_path(cmd, envp);
	exit(EXIT_FAILURE);
}

void	ft_fork(int in[2], int out[2], char **argv, char **envp, int i)
{
	pid_t	pid;
	int		status;
	char	**cmd;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		cmd = ft_split(argv[i], ' ');
		exec_process(in, out, cmd, envp);
	}
	//waitpid(pid, &status, 0);
}


void	pipex(int argc, int fd[2], char **argv, char **envp)
{
	int	i;
	char	**cmd;
	pid_t	pid2;
	pid_t	pid3;
	int		status;
	int		in[2];
	int		out[2];

	pipe(in);
	pipe(out);
	ft_fork(fd, in, argv, envp, 2);
	ft_fork(in, out, argv, envp, 3);
	close (in[0]);
	close (in[1]);
	pid3 = fork();
	if (pid3 < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid3 == 0)
	{
		cmd = ft_split(argv[4], ' ');
		//printf("%s\n", cmd[0]);
		child_process2(fd, out, cmd, envp);
	}
	close (out[0]);
	close (out[1]);
	waitpid(pid2, &status, 0);
	waitpid(pid3, &status, 0);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];

	fd[0] = open(argv[1], O_RDONLY);
	fd[1] = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644); //argc - 1
	//env_path(envp);
	/*if (argc < 5)
	{
		printf("No hay suficientes argumentos");
		return (0);
	}
	else*/
	pipex(argc, fd, argv, envp);
	
	//free(cmds);

	return (0);
}
