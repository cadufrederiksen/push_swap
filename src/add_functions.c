/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 12:41:03 by carmarqu          #+#    #+#             */
/*   Updated: 2023/09/14 13:18:56 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_index2(t_state *pile_a, char **argv, int argc)
{
	int		x;
	t_state	*tmp;

	x = 0;
	ft_sort_params(argc, argv, x);
	tmp = pile_a;
	while (tmp)
	{
		x = 0;
		while (x < argc)
		{
			if (tmp->value == ft_atoi(argv[x]))
				tmp->index = x + 1;
			x++;
		}
		tmp = tmp->next;
	}
}

void	add_index(t_state *pile_a, char **argv, int argc, int checker)
{
	int		x;
	t_state	*tmp;

	x = 1;
	if (checker == 2)
	{
		add_index2(pile_a, argv, argc);
		return ;
	}
	ft_sort_params(argc, argv, x);
	tmp = pile_a;
	while (tmp)
	{
		x = 1;
		while (x < argc)
		{
			if (tmp->value == ft_atoi(argv[x]))
				tmp->index = x;
			x++;
		}
		tmp = tmp->next;
	}
}

void	add_pile_pos(t_state *pile)
{
	t_state	*aux;
	int		pos;

	aux = pile;
	pos = 0;
	while (aux)
	{
		aux->pile_pos = pos;
		aux = aux->next;
		pos++;
	}
}

int	add_target2(t_state *pile_a, int idx)
{
	t_state	*aux;
	int		next_big;
	int		pos;

	pos = 0;
	next_big = 1000;
	aux = pile_a;
	while (aux)
	{
		if (idx < aux->index)
		{
			if (next_big > aux->index)
			{
				next_big = aux->index;
				pos = aux->pile_pos;
			}	
		}
		aux = aux->next;
	}
	return (pos);
}

void	add_target(t_state *pile_a, t_state *pile_b)
{
	t_state	*aux_a;
	t_state	*aux_b;

	aux_b = pile_b;
	while (aux_b)
	{
		aux_a = pile_a;
		while (aux_a)
		{
			if (aux_b->index == (aux_a->index - 1))
				aux_b->target = aux_a->pile_pos;
			else if (aux_b->index == (aux_a->index + 1))
				aux_b->target = aux_a->pile_pos + 1;
			else
				aux_b->target = add_target2(pile_a, aux_b->index);
			aux_a = aux_a->next;
		}
		aux_b = aux_b->next;
	}
}
