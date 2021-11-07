/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_few.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 19:47:25 by hugsbord          #+#    #+#             */
/*   Updated: 2021/11/07 03:27:26 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

void	ft_quicksort_len_4(t_data *data)
{
	if (data->a[data->a_first] > data->a[data->a_first - 1])
		ft_sa(data, 1);
	ft_pb(data);
	if (data->a[data->a_first] > data->a[data->a_first - 1])
		ft_sa(data, 1);
	ft_pb(data);
	if (data->a[data->a_first] > data->a[data->a_first - 1]
		&& data->b[data->b_first] < data->b[data->b_first - 1])
		ft_ss(data);
	else if (data->a[data->a_first] > data->a[data->a_first - 1])
		ft_sa(data, 1);
	else if (data->b[data->b_first] < data->b[data->b_first - 1])
		ft_sb(data, 1);
	ft_pa(data);
	if (data->a[data->a_first] > data->a[data->a_first - 1])
		ft_sa(data, 1);
	ft_pa(data);
	if (data->a[data->a_first] > data->a[data->a_first - 1])
		ft_sa(data, 1);
}

void	ft_quicksort_few_a(t_data *data, int len)
{
	if (len == 2 || len == 3)
	{
		if (data->a[data->a_first] > data->a[data->a_first - 1])
			ft_sa(data, 1);
		if (len == 3)
		{
			if (data->a[data->a_first - 1] > data->a[data->a_first - 2])
			{
				ft_ra(data, 1);
				ft_sa(data, 1);
				ft_rra(data, 1);
				if (data->a[data->a_first] > data->a[data->a_first - 1])
					ft_sa(data, 1);
			}
		}
	}
	if (len == 4)
		ft_quicksort_len_4(data);
}

void	ft_quicksort_few_b(t_data *data, int len)
{
	if (len >= 1 && len <= 3)
		ft_pa(data);
	if (len == 2 || len == 3)
	{
		ft_pa(data);
		if (data->a[data->a_first] > data->a[data->a_first - 1])
			ft_sa(data, 1);
		if (len == 3)
		{
			ft_pa(data);
			if (data->a[data->a_first] > data->a[data->a_first - 1])
				ft_sa(data, 1);
			if (data->a[data->a_first - 1] > data->a[data->a_first - 2])
			{
				ft_ra(data, 1);
				ft_sa(data, 1);
				ft_rra(data, 1);
				if (data->a[data->a_first] > data->a[data->a_first - 1])
					ft_sa(data, 1);
			}
		}
	}
}
