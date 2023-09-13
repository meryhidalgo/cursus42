/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:38:41 by mcarazo-          #+#    #+#             */
/*   Updated: 2023/09/13 16:06:29 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

char	**env_path(char **envp)
{
	int		i;
	char	*path;
	char	*ocurrence;
	char	**sep_paths;

	i = 0;
	while (envp[i])
	{
		ocurrence = ft_strnstr(envp[i], "PATH", 4);
		if (ocurrence)
			break ;
		i++;
	}
	if (ocurrence == NULL)
		error_message("Error in path", 0);
	path = ft_substr(ocurrence, 5, ft_strlen(ocurrence) - 5);
	sep_paths = ft_split(path, ':');
	free (path);
	i = -1;
	while (sep_paths[++i])
		sep_paths[i] = ft_join(sep_paths[i], "/");
	return (sep_paths);
}

void	exec_process(char *cmd, char **envp)
{
	int		i;
	char	*path_cmd;
	char	**paths;
	char	**cmd_flags;

	i = 0;
	cmd_flags = ft_split(cmd, ' ');
	if (execve(cmd, cmd_flags, envp) == -1)
	{
		if (!envp || *envp == NULL || **envp == '\0')
			error_message("Error in environment", 0);
		else
		{
			paths = env_path(envp);
			while (paths[i])
			{
				path_cmd = ft_strjoin(paths[i++], cmd_flags[0]);
				if (access(path_cmd, F_OK) == 0)
					execve(path_cmd, cmd_flags, envp);
				free(path_cmd);
			}
		}
		double_free(cmd_flags);
		error_message("Command not found", 0);
	}
}

void	pipex(char *cmd, char **envp)
{
	pid_t	pid;
	int		pipefd[2];

	if (pipe(pipefd) == -1)
		error_message("Error in pipe", 0);
	pid = fork();
	if (pid < 0)
		error_message("Error in fork", 0);
	else if (pid == 0)
	{
		close (pipefd[0]);
		if (dup2(pipefd[1], STDOUT_FILENO) == -1)
			error_message("Error in dup2", 0);
		exec_process(cmd, envp);
	}
	else
	{
		close (pipefd[1]);
		if (dup2(pipefd[0], STDIN_FILENO) == -1)
			error_message("Error in dup2", 0);
	}
}

void	out_exec(char *cmd, char **envp, int fd)
{
	int		status;
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		error_message("Error in fork", 0);
	else if (pid == 0)
	{
		if (dup2(fd, STDOUT_FILENO) == -1)
			error_message("Error in dup2", 0);
		exec_process(cmd, envp);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WEXITSTATUS(status) != 0)
			exit(EXIT_FAILURE);
	}
}

int	main(int ac, char **av, char **envp)
{
	int	fd[2];

	if (ac < 5)
		error_message("Not enough arguments to perform pipex.\n", 1);
	else if (ac == 5)
	{
		fd[0] = open(av[1], O_RDONLY);
		if (fd[0] == -1)
			error_message("Error in infile", 0);
		fd[1] = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC | O_CLOEXEC, 0644);
		if (fd[1] == -1)
			error_message("Error in opening outfile", 0);
		if (dup2(fd[0], STDIN_FILENO) == -1)
			error_message("Error in dup2", 0);
		pipex(av[2], envp);
		close(fd[0]);
		out_exec(av[ac - 2], envp, fd[1]);
		close (fd[1]);
	}
	else
		error_message("Too many arguments, try executing pipex_bonus.\n", 1);
	return (0);
}
	//system("leaks -q pipex");

//si no hay infile, el programa debe ejecutar los comandos e imprimir un 0 en el outfile
