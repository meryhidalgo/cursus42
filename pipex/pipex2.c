/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:18:59 by mcarazo-          #+#    #+#             */
/*   Updated: 2023/08/03 19:17:59 by mcarazo-         ###   ########.fr       */
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

//void	child_one(int f1, char **cmd1, int end[2], char **paths)
{
	dup2(f1, STDIN_FILENO);
}


void	pipex(int f1, int f2, char **argv, char **envp)
{
	int		end[2];
	int		status;
	pid_t	child1;
	pid_t	child2;

	pipe(end);
	child1 = fork();
	if (child1 < 0)
		return (perror("Fork: "));
	if (child1 == 0)
		child_one(f1, ft_split(argv[2], ' '), end, envp);
	child2 = fork();
	if (child2 < 0)
		return (perror("Fork: "));
	if (child2 == 0)
		child_two(f2, ft_split(argv[3], ' '), end, envp);
	waitpid(child1, &status, 0);
	waitpid(child2, &status, 0);
	close(end[0]);
	close(end[1]);
}

char	**env_path(char **envp)
{
	int		i;
	char	*path;
	char	**sep_paths;
	char	**cmd_args;

	path = ft_substr(envp[2], 5, 61);
	sep_paths = ft_split(path, ':'); //add "/" before joining the command
	//cmd_args = ft_split(argv[2], ' ');
	i = 0;
	while (sep_paths[i])
	{
		sep_paths[i] = ft_join(sep_paths[i], "/");
		printf("%s\n", sep_paths[i]);
		i++;
	}
	return (sep_paths);
}

int	main(int argc, char **argv, char **envp)
{
	int	f1;
	int	f2;

	f1 = open(argv[1], O_RDONLY);
	f2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	/*readable by all the user groups, but writable by the user only*/
	if (f1 < 0 || f2 < 0)
		return (-1);
	pipex(f1, f2, argv, envp);
	//falta liberar sep_paths
	return (0);
}
