/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:12:51 by carmarqu          #+#    #+#             */
/*   Updated: 2023/09/19 11:52:06 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_sort(t_state **pile_a, int size)
{
	int	pos;
	int	sort;

	pos = find_idx(*pile_a, 1);
	if (pos > size / 2)
		sort = pos - size;
	else
		sort = pos;
	while (sort > 0)
	{
		do_ra(pile_a);
		sort--;
	}
	while (sort < 0)
	{
		do_rra(pile_a);
		sort++;
	}
}

int	push_under(t_state **pile_a, t_state **pile_b, int size)
{
	int	size_b;

	size_b = 0;
	while (size_b < size / 2 && (size - size_b) > 3)
	{
		if ((*pile_a)->index <= size / 2)
		{
			do_pb(pile_a, pile_b);
			size_b++;
		}
		else
			do_ra(pile_a);
	}
	return (size_b);
}

void	over3_b(t_state **pile_a, t_state **pile_b, int size_b, int size_a)
{
	t_state	*aux_b;
	int		smaller;

	while (size_b > 0)
	{
		smaller = prices(*pile_a, *pile_b, size_a, size_b);
		aux_b = *pile_b;
		if ((*pile_b)->final_price == 0)
		{
			do_pa(pile_b, pile_a);
			size_b--;
			size_a++;
		}
		else
		{
			while (aux_b->final_price != smaller && aux_b->next != NULL)
				aux_b = aux_b->next;
			over3_moves(pile_a, pile_b, aux_b->price_a, aux_b->price_b);
		}
	}
	final_sort(pile_a, size_a);
}

void	over3_a(t_state **pile_a, t_state **pile_b, int size)
{
	int	size_b;
	int	size_a;

	size_b = push_under(pile_a, pile_b, size);
	size_a = size - size_b;
	while (size_a > 3)
	{
		if ((*pile_a)->index < size / 2 || (*pile_a)->index <= size - 3)
		{
			do_pb(pile_a, pile_b);
			size_b++;
			size_a--;
		}
		else
			do_ra(pile_a);
	}
	size3(pile_a);
	over3_b(pile_a, pile_b, size_b, size_a);
}
