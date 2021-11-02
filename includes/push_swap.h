/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 11:05:37 by hugsbord          #+#    #+#             */
/*   Updated: 2021/11/02 16:13:25 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

#include "./get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include "./../libft/libft.h"

# define SUCCESS		1
# define ERROR			-1

typedef struct		s_node
{
	int				num;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

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
int		ft_sorting(t_data *data, int len);
int		ft_sort_3_arg(t_data *data, int len);
int		ft_sort_5_arg(t_data *data, int len);

#endif
