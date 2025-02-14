/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:02:39 by carmarqu          #+#    #+#             */
/*   Updated: 2023/10/17 11:24:24 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "push_swap.h"

void	check_moves2(t_state **a, t_state **b, char *line)
{
	if (line[0] == 'p' && line[1] == 'a' && line[2] == '\n' && *b)
		push_pile(b, a);
	else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\n' && *a)
		push_pile(a, b);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'a'
		&& line[3] == '\n')
		reverse_rotate_pile(a);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'b'
		&& line[3] == '\n')
		reverse_rotate_pile(b);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'r'
		&& line[3] == '\n')
	{
		reverse_rotate_pile(b);
		reverse_rotate_pile(a);
	}
	else
	{
		ft_putendl_fd("Invalid instruction", 2);
		exit(2);
	}
}

char	*check_moves(t_state **a, t_state **b, char *line)
{
	if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		swap_pile(a);
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\n')
		swap_pile(b);
	else if (line[0] == 's' && line[1] == 's' && line[2] == '\n')
	{
		swap_pile(a);
		swap_pile(b);
	}
	else if (line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
		rotate_pile(a);
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		rotate_pile(b);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == '\n')
	{
		rotate_pile(b);
		rotate_pile(a);
	}
	else
		check_moves2(a, b, line);
	return (get_next_line(0));
}

void	init_checker(t_state **a, t_state **b)
{
	char	*tmp;
	char	*line;

	line = get_next_line(0);
	while (line && *line != '\n')
	{
		tmp = line;
		line = check_moves(a, b, line);
		free(tmp);
	}
	if (!check_pile(*a) || *b)
		ft_putendl_fd("KO", 1);
	else
		ft_putendl_fd("OK", 1);
	free(line);
}

int	main(int argc, char **argv)
{
	int		checker;
	t_state	*pile_b;
	t_state	*pile_a;

	pile_a = NULL;
	pile_b = NULL;
	checker = argc;
	if (argc <= 1)
		return (0);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		argc = new_argc(argv);
	}
	if (!check_all(argv, checker, &pile_a))
	{
		ft_putendl_fd("Error", 2);
		exit(2);
	}
	init_checker(&pile_a, &pile_b);
	free_pile(&pile_a);
	free_pile(&pile_b);
}
