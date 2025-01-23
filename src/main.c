/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 12:35:16 by carmarqu          #+#    #+#             */
/*   Updated: 2025/01/23 14:16:20 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free2d(char **str)
{
	int	x;

	if (!str)
		return ;
	x = 0;
	while (str[x])
		x++;
	x = x -1;
	while (x >= 0)
		free(str[x--]);
	free(str);
}

int	main(int argc, char **argv)
{
	int	checker;
	int	exit;
	
	checker = argc;
	if (argc <= 1)
		return (0);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		argc = new_argc(argv);
	}
	exit = push_swap(argc, argv, checker);
	if (checker == 2)
		free2d(argv);
	if (exit == 1)
		return (1);
	return (0);
}
