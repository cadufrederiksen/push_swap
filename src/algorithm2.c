/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:03:19 by carmarqu          #+#    #+#             */
/*   Updated: 2023/09/14 13:12:28 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	over3_moves(t_state **pile_a, t_state **pile_b, int price_a,
		int price_b)
{
	while (price_a < 0 && price_b < 0)
	{
		do_rrr(pile_a, pile_b);
		price_a++;
		price_b++;
	}
	while (price_a < 0)
	{
		do_rra(pile_a);
		price_a++;
	}
	while (price_b < 0)
	{
		do_rrb(pile_b);
		price_b++;
	}
	if (price_a > 0 || price_b > 0)
		over3_moves2(pile_a, pile_b, price_a, price_b);
}

void	over3_moves2(t_state **pile_a, t_state **pile_b, int price_a,
		int price_b)
{
	while (price_a > 0 && price_b > 0)
	{
		do_rr(pile_a, pile_b);
		price_a--;
		price_b--;
	}
	while (price_a > 0)
	{
		do_ra(pile_a);
		price_a--;
	}
	while (price_b > 0)
	{
		do_rb(pile_b);
		price_b--;
	}
}
