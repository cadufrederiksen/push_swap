/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 16:00:10 by carmarqu          #+#    #+#             */
/*   Updated: 2023/09/14 13:08:09 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_sa(t_state **pile)
{
	swap_pile(pile);
	write(1, "sa\n", 3);
}

void	do_ra(t_state **pile)
{
	rotate_pile(pile);
	write(1, "ra\n", 3);
}

void	do_rra(t_state **pile)
{
	reverse_rotate_pile(pile);
	write(1, "rra\n", 4);
}

void	do_pb(t_state **pile_a, t_state **pile_b)
{
	push_pile(pile_a, pile_b);
	write(1, "pb\n", 3);
}

void	do_rr(t_state **pile_a, t_state **pile_b)
{
	rotate_pile(pile_a);
	rotate_pile(pile_b);
	write(1, "rr\n", 3);
}
