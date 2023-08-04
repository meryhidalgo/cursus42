/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:38:53 by mcarazo-          #+#    #+#             */
/*   Updated: 2023/08/04 13:57:55 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**env_path(char **envp)
{
	int		i;
	char	*path;
	char	*ocurrence;
	char	**sep_paths;
	char	**cmd_args;

	i = 0;
	while (envp[i])
	{
		ocurrence = ft_strnstr(envp[i], "PATH", 4);
		if (ocurrence)
			break ;
		i++;
	}
	path = ft_substr(ocurrence, 5, ft_strlen(ocurrence) - 5);
	sep_paths = ft_split(path, ':');
	free (path);
	i = -1;
	while (sep_paths[++i])
		sep_paths[i] = ft_join(sep_paths[i], "/");
	return (sep_paths);
}

int	main(int argc, char **argv, char **envp)
{
	int		i;
	int		occ;
	char	**sep_paths;

	sep_paths = env_path(envp);
	i = 0;
	while (sep_paths[i])
	{
		printf("%s\n", sep_paths[i]);
		i++;
	}
	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH", 4))
			break ;
		i++;
	}
	printf("%s \n", ft_strnstr(envp[i], "PATH", 4));
}
