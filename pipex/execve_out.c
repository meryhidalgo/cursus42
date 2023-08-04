/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:38:41 by mcarazo-          #+#    #+#             */
/*   Updated: 2023/08/03 19:16:18 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec(char *args[3])
{
	execve("/bin/ls", args, NULL);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	**cmds;

	fd = open(argv[1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	cmds = ft_split(argv[2], ' ');
	//exec(args);
	dup2(fd, STDOUT_FILENO);
	execve("/bin/ls", cmds, NULL);
	printf ("Esta linea no se ejecutará.");
	free(cmds);

	return (0);
}
