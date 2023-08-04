/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:41:56 by mcarazo-          #+#    #+#             */
/*   Updated: 2023/08/03 18:31:34 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_path(char **cmd1, char **envp)
{
	int		i;
	char	*cmd;
	char	**paths,

	i = 0;
	paths = env_path(envp);
	while (paths[i])
	{
		cmd = ft_strjoin(paths[i], cmd1[1]);
		execve(cmd, cmd1, envp); //si es correcto se ejecuta en la terminal
		free(cmd);
	}
	return (EXIT_FAILURE);
}

void	ft_exec(char **argv, char **envp)
{
	int		fd[2];
	pid_t	child;

	pipe(fd);
	if (child < 0)
		return (perror("Fork: "));
	else if (child)
	{
		dup2(fd[1], STDOUT_FILENO);
		check_path(ft_split(argv[2], ' '), envp);
	}
	else
	{
		dup2(f2, fd[0]);
		//waitpid
	}
}

void	ft_check_args(int argc, char **argv)
{
	int	f1;
	int	f2;

	if (argc != 4)
		exit (1);
	f1 = open(argv[1], O_RDONLY);
	f2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (f1 < 0 || f2 < 0)
		return (-1);
}

char	**ft_sep_path(char **cmd, char **envp)
{
	int		i;
	char	*try;
	char	*path;
	char	**sep_paths;
	char	**cmd_args;

	path = ft_substr(envp[2], 5, 61);
	sep_paths = ft_split(path, ':');
	//cmd_args = ft_split(argv[2], ' ');
	i = 0;
	while (sep_paths[i])
	{
		sep_paths[i] = ft_join(sep_paths[i], "/");
		//printf("%s\n", sep_paths[i]);
		i++;
	}
	return (sep_paths);
}

{
	while (sep_paths[i])
	{
		try = ft_strjoin(sep_paths[i], cmd[1]);
		execve(try, cmd, envp); //si es correcto se ejecuta en la terminal
		free(try);
	}
	return (EXIT_FAILURE);
}

int	main(int argc, char **argv, char **envp)
{
	char	**paths;

	ft_check_args(argc, argv);
	paths = ft_sep_path(argv, envp);
}
