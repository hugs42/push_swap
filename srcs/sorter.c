/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:25:41 by hugsbord          #+#    #+#             */
/*   Updated: 2021/11/07 03:27:52 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

int	ft_sort_5_arg(t_data *data)
{
	int	i;
	int	a_first_tmp;
	int	*tmp_stack;

	i = 0;
	tmp_stack = ft_stackdup(data, data->len, 1);
	ft_sort_stack(tmp_stack, data->len);
	while (i <= data->len)
	{
		if (tmp_stack[1] >= data->a[data->a_first])
			ft_pb(data);
		else
			ft_ra(data, 1);
		i++;
	}
	ft_sort_3_arg(data);
	if (data->b[0] > data->b[1])
		ft_sb(data, 1);
	ft_pa(data);
	ft_pa(data);
	return (SUCCESS);
}

int	ft_sort_4_arg(t_data *data, int stack)
{
	int	a;
	int	smallest;

	a = 1;
	if (stack == 2)
		a = 2;
	smallest = ft_smallest_nb(data, data->len, a);
	while (data->a[data->a_first] != smallest)
		ft_ra(data, 1);
	ft_pb(data);
	ft_sort_3_arg(data);
	ft_pa(data);
	return (SUCCESS);
}

int	ft_sort_3_arg(t_data *data)
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

int	ft_sort_2_arg(t_data *data, int stack)
{
	if (stack == 1)
	{
		if (data->a[0] < data->a[1])
			ft_sa(data, 1);
	}
	else if (stack == 2)
	{
		if (data->b[0] < data->b[1])
			ft_sb(data, 1);
	}
	return (SUCCESS);
}

int	ft_sorting(t_data *data)
{
	if (data->len == 2)
		ft_sort_2_arg(data, 1);
	else if (data->len == 3)
		ft_sort_3_arg(data);
	else if (data->len == 4)
		ft_sort_4_arg(data, 1);
	else if (data->len == 5)
		ft_sort_5_arg(data);
	else
		ft_quicksort_a_to_b(data, data->len);
	return (SUCCESS);
}
