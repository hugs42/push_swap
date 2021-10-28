/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 17:05:23 by hugsbord          #+#    #+#             */
/*   Updated: 2021/10/27 17:34:20 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

void	ft_rra(t_data *data, int is_op)
{
	int		i;
	int		tmp;

	i = 0;
	tmp = data->a[0];
	while (i < data->a_first)
	{
		data->a[i] = data->a[i + 1];
		i++;
	}
	data->a[data->a_first] = tmp;
	if (is_op)
		ft_putstr_fd("rra\n", 1);
}

void	ft_rrb(t_data *data, int is_op)
{
	int		i;
	int		tmp;

	i = 0;
	tmp = data->b[0];
	while (i < data->b_first)
	{
		data->b[i] = data->b[i + 1];
		i++;
	}
	data->b[data->b_first] = tmp;
	if (is_op)
		ft_putstr_fd("rrb\n", 1);
}

void	ft_rrr(t_data *data)
{
	ft_rra(data, 0);
	ft_rrb(data, 0);
	ft_putstr_fd("rrr\n", 1);
}
