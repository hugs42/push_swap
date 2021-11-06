/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 11:05:37 by hugsbord          #+#    #+#             */
/*   Updated: 2021/11/06 19:37:14 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

#include <unistd.h>
#include "./../libft/libft.h"

# define SUCCESS		1
# define ERROR			-1

typedef struct	s_pivot
{
	int			p1;
	int			p2;
}				t_pivot;

typedef struct	s_counter
{
	int			ra_count;
	int			rb_count;
	int			pb_count;
	int			pa_count;
}				t_counter;

typedef struct		s_data
{
	int			*a;
	int			*b;
	int			a_first;
	int			b_first;
	int			len;
}				t_data;

int		ft_parse_input(t_data *data, int argc, char **argv);
int		ft_init_data(t_data *data, int len);
int		ft_check_double(int *input, int len, int nb);
int		ft_check_char(char *input);
int		ft_check_len(char *input, char c);
int		ft_check_max(int nb);
void	ft_show_stack(t_data *data, int stack, int len);
void	ft_reverse_stack(t_data *data);
void	ft_sa(t_data *data, int is_op);
void	ft_sb(t_data *data, int is_op);
void	ft_ss(t_data *data);
void	ft_pa(t_data *data);
void	ft_pb(t_data *data);
void	ft_ra(t_data *data, int is_op);
void	ft_rb(t_data *data, int is_op);
void	ft_rr(t_data *data);
void	ft_rra(t_data *data, int is_op);
void	ft_rrb(t_data *data, int is_op);
void	ft_rrr(t_data *data);
int		ft_sorting(t_data *data);
int		ft_sort_2_arg(t_data *data, int stack);
int		ft_sort_3_arg(t_data *data);
int		ft_sort_4_arg(t_data *data, int stack);
int		ft_sort_5_arg(t_data *data);
int		*ft_stackdup(t_data *data, int len, int stack);
void	ft_sort_stack(int *stack, int len);
int		ft_smallest_nb(t_data *data, int len, int stack);
int		ft_already_sort_a(t_data *data, int len);
int		ft_already_sort_b(t_data *data, int len);
int		ft_quicksort_a_to_b(t_data *data, int len);
int		ft_quicksort_b_to_a(t_data *data, int len);
#endif
