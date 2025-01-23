/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:47:48 by carmarqu          #+#    #+#             */
/*   Updated: 2023/09/14 13:06:06 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_pile(t_state **pile)
{
	t_state	*aux;

	if (!(*pile) || !(*pile)->next)
		return ;
	aux = *pile;
	*pile = (*pile)->next;
	aux->next = (*pile)->next;
	(*pile)->next = aux;
}

void	rotate_pile(t_state **pile)
{
	t_state	*aux;
	t_state	*last;

	if (!(*pile) || !(*pile)->next)
		return ;
	aux = *pile;
	*pile = (*pile)->next;
	last = last_list(*pile);
	aux->next = NULL;
	last ->next = aux;
}

void	reverse_rotate_pile(t_state **pile)
{
	t_state	*aux;
	t_state	*last;

	if (!(*pile) || !(*pile)->next)
		return ;
	aux = *pile;
	last = (*pile)->next;
	while (last->next != NULL)
	{
		aux = aux->next;
		last = last->next;
	}
	aux->next = NULL;
	last->next = *pile;
	*pile = last;
}

void	push_pile(t_state **src, t_state **dest)
{
	t_state	*aux;

	aux = *src;
	*src = (*src)->next;
	aux ->next = *dest;
	*dest = aux;
}
