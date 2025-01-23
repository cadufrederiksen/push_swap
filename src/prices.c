/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prices.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:37:43 by carmarqu          #+#    #+#             */
/*   Updated: 2023/09/14 13:03:28 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	prices(t_state *pile_a, t_state *pile_b, int size_a, int size_b)
{
	t_state	*aux_b;
	int		smaller;

	smaller = 100;
	add_pile_pos(pile_a);
	add_pile_pos(pile_b);
	add_target(pile_a, pile_b);
	aux_b = pile_b;
	while (aux_b)
	{
		if (aux_b->pile_pos > (size_b / 2))
			aux_b->price_b = (aux_b->pile_pos - size_b);
		else
			aux_b->price_b = aux_b->pile_pos;
		if (aux_b->target > (size_a / 2))
			aux_b->price_a = (aux_b->target - size_a);
		else
			aux_b->price_a = aux_b->target;
		aux_b->final_price = abs(aux_b->price_a) + abs(aux_b->price_b);
		if (aux_b->final_price < smaller && aux_b->final_price >= 0)
			smaller = aux_b->final_price;
		aux_b = aux_b->next;
	}
	return (smaller);
}
