/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 09:50:45 by carmarqu          #+#    #+#             */
/*   Updated: 2025/01/23 14:12:44 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_state
{
	int				index;
	int				value;
	int				pile_pos;
	int				target;
	int				price_a;
	int				price_b;
	int				final_price;
	struct s_state	*next;

}					t_state;

t_state				*create_new(char *argv);
t_state				*last_list(t_state *lst);
void				add_new(t_state **lst, t_state *new);
int					check_args(char **argv, int x, t_state **pile_a);
int					main(int argc, char **argv);
char				**ft_sort_params(int argc, char **argv, int j);
void				add_index(t_state *pile_a, char **argv, int argc,
						int checker);
void				swap_pile(t_state **pile_a);
void				rotate_pile(t_state **pile);
t_state				*last_list(t_state *lst);
void				reverse_rotate_pile(t_state **pile);
t_state				*allocate_state(void);
void				push_pile(t_state **a, t_state **b);
void				size2(t_state **pile);
void				size3(t_state **pile);
int					check_pile(t_state *pile);
void				add_pile_pos(t_state *pile);
void				add_target(t_state *pile_a, t_state *pile_b);
int					check_all(char **argv, int checker, t_state **a);
void				do_sa(t_state **pile);
void				do_ra(t_state **pile);
void				do_rra(t_state **pile);
void				do_pb(t_state **pile_a, t_state **pile_b);
void				do_sb(t_state **pile);
void				do_rb(t_state **pile);
void				do_rrb(t_state **pile);
void				do_pa(t_state **pile_a, t_state **pile_b);
int					new_argc(char **argv);
void				over3_a(t_state **pile_a, t_state **pile_b, int size);
void				over3_b(t_state **pile_a, t_state **pile_b, int size_b,
						int size_a);
int					prices(t_state *pile_a, t_state *pile_b, int size_a,
						int size_b);
void				over3_moves(t_state **pile_a, t_state **pile_b, int price_a,
						int price_b);
void				do_rr(t_state **pile_a, t_state **pile_b);
void				do_rrr(t_state **pile_a, t_state **pile_b);
void				add_index2(t_state *pile_a, char **argv, int argc);
void				over3_moves2(t_state **pile_a, t_state **pile_b,
						int price_a, int price_b);
int					push_swap(int argc, char **argv, int checker);
void				select_alg(int size, t_state **pile_a, t_state **pile_b);
void				final_sort(t_state **pile_a, int size_a);
int					find_idx(t_state *pile, int idx);
int					add_target2(t_state *pile_a, int idx);
void				free_pile(t_state **pile);
void				init_checker(t_state **a, t_state **b);
void				free2d(char **str);

#endif
