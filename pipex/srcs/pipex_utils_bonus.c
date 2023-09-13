/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:14:44 by mcarazo-          #+#    #+#             */
/*   Updated: 2023/09/13 15:38:24 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	error_message(char	*message, int p)
{
	if (p == 0)
		perror(message);
	else
		write(2, message, ft_strlen(message));
	exit(EXIT_FAILURE);
}

void	double_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free (s);
}

char	*ft_join(char *s1, char *s2)
{
	char	*join;
	int		i;
	int		j;

	if (s1 == 0 || s2 == 0)
		return (NULL);
	join = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (join == 0)
		return (NULL);
	i = ft_strlen(s1);
	j = 0;
	ft_strlcpy(join, s1, ft_strlen(s1) + 1);
	while (s2[j] != 0)
	{
		join[i] = s2[j];
		i++;
		j++;
	}
	join[i] = 0;
	free(s1);
	return (join);
}

void	get_in_heredoc(char **argv, int pipefd[2])
{
	char	*s;

	s = "A";
	while (s)
	{
		write(1, ">heredoc ", 9);
		s = get_next_line(0);
		if (!s)
			error_message("Error in get_next_line", 1);
		if (!ft_strncmp(argv[2], s, ft_strlen(argv[2])))
		{
			free (s);
			break ;
		}
		write(pipefd[1], s, ft_strlen(s));
		free(s);
	}
}

void	heredoc(char **argv, char **envp)
{
	pid_t	pid;
	int		status;
	int		pipefd[2];

	if (pipe(pipefd) == -1)
		error_message("Error in pipe", 0);
	pid = fork();
	if (pid < 0)
		error_message("Error in fork", 0);
	else if (pid == 0)
	{
		close (pipefd[0]);
		get_in_heredoc(argv, pipefd);
		exit(0);
	}
	else
	{
		close (pipefd[1]);
		waitpid(pid, &status, 0);
		if (WEXITSTATUS(status) != 0)
			exit(EXIT_FAILURE);
		dup2(pipefd[0], STDIN_FILENO);
		pipex(argv[3], envp);
	}
}
