/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mng_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:12:37 by mcarazo-          #+#    #+#             */
/*   Updated: 2023/08/03 12:44:10 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	end_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_isdigit(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if ((c[i] == 43 || c[i] == 45) && (!c[i + 1]
				|| !('0' <= c[i + 1] && c[i + 1] <= '9')))
			return (0);
		else if ((c[i] == 43 || c[i] == 45) && (i != 0 && !((c[i - 1] > 8
						&& c[i - 1] < 14) || c[i - 1] == 32)))
			return (0);
		else if (!(('0' <= c[i] && c[i] <= '9') || c[i] == 43 || c[i] == 45))
			return (0);
		i++;
	}
	return (1);
}

int	redundancy(int *nums, int length)
{
	int	i;
	int	j;

	i = 0;
	while (i < length)
	{
		j = i + 1;
		while (j < (length - 1))
		{
			if (nums[i] == nums[j++])
				return (1);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	char	**str;
	int		*nums;
	t_list	*stack_a;
	t_list	*stack_b;

	i = 0;
	nums = NULL;
	if (argc < 2)
		return (1);
	else if (argc == 2)
	{
		str = ft_split(argv[1], ' ');
		nums = array_number(countwords(argv[1], ' '), str, 1);
		argc = countwords(argv[1], ' ') + 1;
	}
	else
		nums = array_number(argc, argv, 0);
	if (redundancy(nums, argc) == 1)
		end_error();
	stack_a = create_list(argc, nums);
	stack_b = NULL;
	free(nums);
	push_swap(&stack_a, &stack_b);
}

	//system("leaks -q push_swap");
/*
	printf("A ");
	print_list(stack_a);
	printf("B ");
	print_list(stack_b);

	printf("A ");
	print_list(stack_a);
	printf("B ");
	print_list(stack_b);
	//https://github.com/LeoFu9487/push_swap_tester
*/
