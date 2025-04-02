#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct pswp_list
{
	int					value;
	int					moves;
	int					min;
	int					max;
	int					cost;
	int					reverse;
	struct pswp_list	*target;
	struct pswp_list	*next;

}						p_list;

int						init_stack(int argc, char **argv, p_list **stack_a);
int						rearange_stack(p_list **stack, int size);
long long int			ft_atoil(const char *str);
void					swap(char stack, int single, p_list **lst_stck);
void					push(p_list **stack_take, p_list **stack_put, char ch);
void					rotate(p_list **last, p_list **stack, char ch,
							int single);
void					reverse_rotate(p_list **last, p_list **stack, char ch,
							int single);
void					split_stack(p_list **stack_a, p_list **stack_b);
void					double_reverse(p_list **stack_a, p_list **stack_b,
							p_list **lasta, p_list **lastb);
void					double_rotate(p_list **stack_a, p_list **stack_b,
							p_list **lasta, p_list **lastb);
void					double_swap(p_list **stack_a, p_list **stack_b);
void					append_node(p_list **list, p_list *node);
void					clear_list(p_list **lst);
void					add_front(p_list **lst, p_list *new);
void					rotate_node(p_list *sorted, p_list **stack, char ch);
void					sort_three(p_list **stack_a);
void					find_target(p_list **fnd, p_list *stack);
void					double_rotate_node(p_list *cheap, p_list **stack_a,
							p_list **stack_b);
void					rotate_nodes(int counta, int countb, p_list **stack_a,
							p_list **stack_b);
void					reverse_rotate_nodes(int counta, int countb,
							p_list **stack_a, p_list **stack_b);
void					final_merge(p_list **stack_a, p_list **stack_b);
void					final_sort(p_list **stack_a);
p_list					*last_node(p_list *lst);
p_list					*create_node(int value);
p_list					*find_cheap(p_list *stack_a);
#endif
