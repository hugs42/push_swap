/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:51:56 by hugsbord          #+#    #+#             */
/*   Updated: 2021/10/27 16:58:42 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

void	ft_sa(t_data *data, int is_op)
{
	int		tmp;

	tmp = 0;
	if (data->a_first >= 1)
	{
		tmp = data->a[data->a_first];
		data->a[data->a_first] = data->a[data->a_first - 1];
		data->a[data->a_first] = tmp;
	}
	if (is_op)
		ft_putstr_fd("sa\n", 1);
}

void	ft_sb(t_data *data, int is_op)
{
	int		tmp;

	tmp = 0;
	if (data->b_first >= 1)
	{
		tmp = data->b[data->b_first];
		data->b[data->b_first] = data->b[data->b_first - 1];
		data->b[data->b_first] = tmp;
	}
	if (is_op)
		ft_putstr_fd("op\n", 1);
}

void	ft_ss(t_data *data)
{
	ft_sa(data, 0);
	ft_sb(data, 0);
	ft_putstr_fd("ss\n", 1);
}