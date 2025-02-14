/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:52:35 by carmarqu          #+#    #+#             */
/*   Updated: 2023/09/14 12:52:07 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_sort_params(int argc, char **argv, int j)
{
	int		i;
	char	*c;

	while (j < argc)
	{
		i = j + 1;
		while (i < argc)
		{
			if (ft_atoi(argv[j]) > ft_atoi(argv[i]))
			{
				c = argv[i];
				argv[i] = argv[j];
				argv[j] = c;
				i++;
			}
			else
				i++;
		}
		j++;
	}
	return (argv);
}

int	new_argc(char **argv)
{
	int	x;

	x = 0;
	while (argv[x])
		x++;
	return (x);
}

int	find_idx(t_state *pile, int idx)
{
	t_state	*aux;

	aux = pile;
	add_pile_pos(pile);
	while (pile)
	{
		if (aux->index == idx)
			return (aux->pile_pos);
		aux = aux->next;
	}
	return (0);
}

void	add_new(t_state **lst, t_state *new)
{
	t_state	*aux;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	aux = last_list(*lst);
	aux->next = new;
}
