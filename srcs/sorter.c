/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:25:41 by hugsbord          #+#    #+#             */
/*   Updated: 2021/11/03 13:37:04 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

int		ft_biggest_nb(t_data *data, int len, int stack)
{
	int		i;
	int		biggest;

	i = 0;
	if (stack == 1)
	{
		biggest = data->a[0];
		while (i < len)
		{
			if (biggest < data->a[i + 1])
				biggest = data->a[i + 1];
			i++;
		}
	}
	else if (stack == 2)
	{
		biggest = data->b[0];
		while (i < len)
		{
			if (biggest < data->b[i + 1])
				biggest = data->b[i + 1];
			i++;
		}
	}
	return (biggest);
}

int		ft_smallest_nb(t_data *data, int len, int stack)
{
	int	i;
	int	smallest;

	i = 0;
	if (stack == 1)
	{
//		ft_putnbr_fd(data->a[0],1);
		smallest = data->a[0];
		while (i < len - 1)
		{
			if (smallest > data->a[i + 1])
				smallest = data->a[i + 1];
			i++;
		}
	}
	else if (stack == 2)
	{
		smallest = data->b[0];
		while (i < len - 1)
		{
			if (smallest < data->b[i + 1])
				smallest = data->b[i + 1];
			i++;
		}
	}
	return (smallest);
}

int		ft_sort_5_arg(t_data *data, int len)
{
	int i;
	int	a_first_tmp;
	int *arr;
	int	biggest;

	biggest = ft_biggest_nb(data, len, 1);

	i = 0;
//	ft_putnbr_fd(bigger_nb, 1);
//	ft_putstr_fd("\n$$", 1);
	ft_pb(data);
	ft_pb(data);
	ft_sort_3_arg(data, len);
	ft_show_stack(data, 1, len);
	ft_putstr_fd("\n", 1);
	ft_show_stack(data, 2, len);
	ft_putstr_fd("\n", 1);
	ft_putnbr_fd(data->a_first, 1);
	ft_putstr_fd("\n####", 1);
//	ft_reverse_stack(data);
//	if (data->b[0] > data->b[1])
//		ft_sb(data, 1);
//	while (i < 5)
//	{
//		ft_putstr_fd("##\n", 1);
//		ft_putnbr_fd(data->a[0], 1);
//		ft_putstr_fd("##", 1);
//		ft_putnbr_fd(data->b[1], 1);
//		ft_putstr_fd("##\n", 1);
	a_first_tmp = data->a_first;
	while (i < 2)
	{
		if (data->b[i] > data->a[data->a_first])
		{
			while (data->b[i] > data->a[a_first_tmp])
			{
				ft_ra(data, 1);
				a_first_tmp++;
			}
			ft_ra(data, 1);
			ft_pa(data);
			while (data->a[0] != biggest)
				ft_ra(data, 1);
//		ft_ra(data, 1);
//			ft_pa(data);
		}
		i++;
	}
	if (data->b[1] < data->a[2])
	{
//		ft_pa(data);
	}
	if (data->b[0] > data->a[0])
	{
//		ft_pa(data);
//		ft_ra(data, 1);
	}
//		else if (data->b[i] < data->a[data->a_first])
//			ft_ra(data, 1);
//		else if (data->b[i] > data->a[5])
//			ft_pa(data);
//		i++;
//	}
//	ft_putnbr_fd(len, 1);
	ft_show_stack(data, 1, len);
	ft_putstr_fd("\n", 1);
	ft_show_stack(data, 2, len);
	ft_putstr_fd("\n", 1);
	ft_putnbr_fd(data->a_first, 1);
	return (SUCCESS);
}

int	ft_sort_4_arg(t_data *data, int len)
{
	int smallest;

	smallest = ft_smallest_nb(data, len, 1);
	while (data->a[data->a_first] != smallest)
		ft_ra(data, 1);
	ft_pb(data);
	ft_sort_3_arg(data, len);
	ft_pa(data);
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

int		ft_sort_2_arg(t_data *data, int stack)
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

int		ft_sorting(t_data *data, int len)
{
//	ft_putnbr_fd(ft_biggest_nb(data, len, 1), 1);
//	ft_show_stack(data, 1);
	if (len == 2)
		ft_sort_2_arg(data, 1);
	if (len == 3)
	{
		ft_sort_3_arg(data, len);
//	ft_show_stack(data, 1, len);
//	ft_putstr_fd("\n", 1);
//	ft_show_stack(data, 2, len);
//	ft_putstr_fd("\n", 1);
//	ft_putnbr_fd(data->a_first, 1);
	}
	else if (len == 4)
	{
		ft_sort_4_arg(data, len);
	}
	else if (len == 5)
	{
		ft_sort_5_arg(data, len);
	}
	return (SUCCESS);
}
