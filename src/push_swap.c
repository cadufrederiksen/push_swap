/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:25:11 by carmarqu          #+#    #+#             */
/*   Updated: 2025/01/23 14:15:00 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	size2(t_state **pile)
{
	if ((*pile)->index > (*pile)->next->index)
		do_sa(pile);
}

void	size3(t_state **pile)
{
	while (!check_pile(*pile))
	{
		if ((*pile)->index > (*pile)->next->index
			&& (*pile)->index > (*pile)->next->next->index)
			do_ra(pile);
		else if ((*pile)->index < (*pile)->next->index
			&& (*pile)->next->index > (*pile)->next->next->index)
			do_rra(pile);
		else
			do_sa(pile);
	}
}

void	select_alg(int size, t_state **pile_a, t_state **pile_b)
{
	if (size == 2)
		size2(pile_a);
	else if (size == 3)
		size3(pile_a);
	else if (size > 3)
		over3_a(pile_a, pile_b, size);
}

void	free_pile(t_state **pile)
{
	t_state	*pile_aux;

	if (!pile | !*pile)
		return ;
	while (*pile)
	{
		pile_aux = (*pile)->next;
		free(*pile);
		*pile = pile_aux;
	}
	*pile = NULL;
}

int	push_swap(int argc, char **argv, int checker)
{
	t_state	*pile_b;
	t_state	*pile_a;
	int		x;

	pile_a = NULL;
	pile_b = NULL;
	x = 1;
	if (checker == 2)
		x = 0;
	if (!check_all(argv, checker, &pile_a))
	{
		return (ft_putendl_fd("Error: invalid input", 2),
			free2d(argv), free_pile(&pile_a), 1);
	}
	add_index(pile_a, argv, argc, checker);
	if (check_pile(pile_a) == 1)
	{
		if (checker == 2)
			free2d(argv);
		return (free_pile(&pile_a), 0);
	}
	select_alg(argc - x, &pile_a, &pile_b);
	free_pile(&pile_a);
	free_pile(&pile_b);
	return (0);
}
