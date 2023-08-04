/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:38:09 by mcarazo-          #+#    #+#             */
/*   Updated: 2023/08/03 18:38:18 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int main(void)
{
	if (access("example.txt", R_OK) != -1)
		printf("I have permission\n");
	else
		printf("I don't have permission\n");

	return (0);
}
