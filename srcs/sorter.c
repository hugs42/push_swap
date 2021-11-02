/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:25:41 by hugsbord          #+#    #+#             */
/*   Updated: 2021/11/02 16:58:04 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

int		ft_sort_5_arg(t_data *data, int len)
{
	int i;

	i = 0;
	ft_pb(data);
	ft_pb(data);
	ft_sort_3_arg(data, len);
	while (i <= len)
	{
		if (data->b[i] >= data->a[data->a_first])
			ft_ra(data, 1);
		else
			ft_pa(data);
		i++;
	}
	ft_putnbr_fd(len, 1);
	ft_show_stack(data, 1, len);
	ft_putstr_fd("\n", 1);
	ft_show_stack(data, 2, len);
	ft_putstr_fd("\n", 1);
	ft_putnbr_fd(data->a_first, 1);
	return (SUCCESS);
}

int		ft_sort_3_arg(t_data *data, int len)
{
	if (data->a[2] > data->a[1])
		ft_sa(data, 1);
	if (data->a[0] < data->a[1])
	{
		ft_rra(data, 1);
		if (data->a[1] < data->a[2])
			ft_sa(data, 1);
	}
	return (SUCCESS);
}

int		ft_sorting(t_data *data, int len)
{
//	ft_show_stack(data, 1);
	if (len == 3)
	{
		ft_sort_3_arg(data, len);
	}
	else if (len == 5)
	{
		ft_sort_5_arg(data, len);
	}
	return (SUCCESS);
}
