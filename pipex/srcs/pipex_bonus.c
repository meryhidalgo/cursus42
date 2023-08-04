/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:38:41 by mcarazo-          #+#    #+#             */
/*   Updated: 2023/08/04 15:25:45 by mcarazo-         ###   ########.fr       */
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
		error_message("PATH not found\n");
	path = ft_substr(ocurrence, 5, ft_strlen(ocurrence) - 5);
	sep_paths = ft_split(path, ':');
	free (path);
	i = -1;
	while (sep_paths[++i])
		sep_paths[i] = ft_join(sep_paths[i], "/");
	return (sep_paths);
}

int	exec_process(char *cmd, char **envp)
{
	int		i;
	char	*path_cmd;
	char	**paths;
	char	**cmd_flags;

	i = 0;
	paths = env_path(envp);
	cmd_flags = ft_split(cmd, ' ');
	while (paths[i])
	{
		path_cmd = ft_strjoin(paths[i], cmd_flags[0]);
		execve(path_cmd, cmd_flags, envp);
		free(path_cmd);
		i++;
	}
	double_free(paths);
	write(2, cmd_flags[0], ft_strlen(cmd_flags[0]));
	error_message(": command not found\n");
	double_free(cmd_flags);
	exit (EXIT_FAILURE);
}

void	pipex(char *cmd, char **envp)
{
	pid_t	pid;
	int		pipefd[2];

	if (pipe(pipefd) == -1)
		error_message("Broken pipe error\n");
	pid = fork();
	if (pid < 0)
		error_message("Fork failed: Resource temporarily unavailable\n");
	else if (pid == 0)
	{
		close (pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		exec_process(cmd, envp);
	}
	else
	{
		close (pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	fd[2];

	if (argc < 5)
		error_message("Not enough enough arguments to perform pipex.\n");
	/*if (argv[2] = "here_doc")
		here_doc();*/
	fd[0] = open(argv[1], O_RDONLY);
	i = 2;
	dup2(fd[0], STDIN_FILENO);
	while (i < (argc - 2))
		pipex(argv[i++], envp);
	fd[1] = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	dup2(fd[1], STDOUT_FILENO);
	exec_process(argv[argc - 2], envp);
	close (fd[1]);
	//si sale en alguno de los error_message los ficheros se quedan abiertos
	//system("leaks -q a.out");
	return (0);
}
