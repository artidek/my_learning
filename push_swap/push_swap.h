/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:25:47 by aobshatk          #+#    #+#             */
/*   Updated: 2025/02/26 20:07:11 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/libft/libft.h"
# include "ft_printf/libftprintf.h"

typedef struct pswp_list
{
	int					value;
	int					moves;
	int					cost;
	int					reverse;
	struct pswp_list	*target;
	struct pswp_list	*next;

}						t_plist;

typedef struct s_min_max
{
	int					min;
	int					max;
}						t_min_max;

int						init_stack(int argc, char **argv, t_plist **stack_a);
void					rearange_stack(t_plist **stack, int size);
int						calculate_cost(t_plist *node);
int						sorted(t_plist *stack);
int						find_duplicates(t_plist *stack);
long long int			ft_atoil(const char *str);
void					swap(char stack, int single, t_plist **lst_stck);
void					push(t_plist **stack_take, t_plist **stack_put,
							char ch);
void					rotate(t_plist **last, t_plist **stack, char ch,
							int single);
void					reverse_rotate(t_plist **last, t_plist **stack, char ch,
							int single);
void					split_stack(t_plist **stack_a, t_plist **stack_b);
void					double_reverse(t_plist **stack_a, t_plist **stack_b,
							t_plist **lasta, t_plist **lastb);
void					double_rotate(t_plist **stack_a, t_plist **stack_b,
							t_plist **lasta, t_plist **lastb);
void					double_swap(t_plist **stack_a, t_plist **stack_b);
void					append_node(t_plist **list, t_plist *node);
void					clear_list(t_plist **lst);
void					add_front(t_plist **lst, t_plist *new_node);
void					rotate_node(t_plist *sorted, t_plist **stack, char ch);
void					sort_three(t_plist **stack_a);
void					find_target(t_plist **fnd, t_plist *stack,
							t_min_max min_max);
void					double_rotate_node(t_plist *cheap, char cur,
							t_plist **stack_a, t_plist **stack_b);
void					rotate_nodes(int counta, int countb, t_plist **stack_a,
							t_plist **stack_b);
void					reverse_rotate_nodes(int counta, int countb,
							t_plist **stack_a, t_plist **stack_b);
void					final_merge(t_plist **stack_a, t_plist **stack_b);
void					final_sort(t_plist **stack_a);
void					find_target_final(t_plist **fnd, t_plist *stack,
							t_min_max min_max);
t_plist					*last_node(t_plist *lst);
t_plist					*create_node(int value);
t_plist					*find_min_max(t_plist *stack, int fnd);
t_plist					*find_cheap(t_plist *stack);
t_min_max				min_max(t_plist *stack, t_min_max min_max);
#endif
