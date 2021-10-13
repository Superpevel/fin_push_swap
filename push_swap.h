#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# include <fcntl.h>

# define ERROR "Error"
# define INT_MIN -2147483648
# define INT_MAX 2147483647
# define SA swap(*a, 1)
# define SB swap(*b, 2)
# define SS sswap(*a, *b)
# define PA push(a, b, 1)
# define PB push(b, a, 2)
# define RA rotate(a, 1)
# define RB rotate(b, 2)
# define RR rrotate(a, b)
# define RRA revrotate(a, 1)
# define RRB revrotate(b, 2)
# define RRR rrevrotate(a, b)

typedef struct		s_stack
{
	int				n;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_oper
{
	char			*data;
	struct s_oper	*next;
}					t_oper;

char				*swap(t_stack *head, int id);
void				sswap(t_stack *a, t_stack *b);
char				*push(t_stack **a, t_stack **b, int id);
char				*rotate(t_stack **head, int id);
void				rrotate(t_stack **a, t_stack **b);
char				*revrotate(t_stack **head, int id);
void				rrevrotate(t_stack **a, t_stack **b);
int					sort_stack_a(t_stack **a, t_stack **b,
								int len, t_oper **oper);
int					sort_stack_b(t_stack **a, t_stack **b,
								int len, t_oper **oper);
int					ft_sort_asc(t_stack **a, int len, t_oper **oper);
int					ft_sort_desc(t_stack **b, int len, t_oper **oper);
int					ft_sort_a(t_stack **a, int len, t_oper **oper);
int					ft_sort_b(t_stack **b, int len, t_oper **oper);
int					check_input(char **av);
int					is_sorted(t_stack *a);
int					is_revsorted(t_stack *a);
void				fill_stack(t_stack **a, char **av);
void				clear_memory(t_stack **a, t_stack **b);
void				add_oper(t_oper **head, char *data);
void				optim_sasa(t_oper **oper, int *flag, int *all);
void				optim_sbsb(t_oper **oper, int *flag, int *all);
void				optim_pbpa(t_oper **oper, int *flag, int *all);
void				optim_rrara(t_oper **oper, int *flag, int *all);
void				optim_rrbrb(t_oper **oper, int *flag, int *all);
void				optim_rarb(t_oper **oper, int *flag, int *all);
void				optim_sasb(t_oper **oper, int *flag, int *all);
void				optim_rrarrb(t_oper **oper, int *flag, int *all);
void				optim_operations(t_oper **oper);
void				remove_oper(t_oper **head);
void				print_stacks(t_stack *a, t_stack *b);
int					ft_pivot(t_stack *a, int len);
int					stack_len(t_stack *a);
int		            ft_str_equal(char const *s1, char const *s2);
void	            ft_strdel(char **as);
#endif
