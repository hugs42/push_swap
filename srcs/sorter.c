/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:25:41 by hugsbord          #+#    #+#             */
/*   Updated: 2021/11/03 16:07:27 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

int		*ft_stackdup(t_data *data, int len, int stack)
{
	int *tmp_stack;
	int i;

	tmp_stack = (int *)malloc(sizeof(int) * len);
	if (!tmp_stack)
		exit(1);
	i = -1;
	if (stack == 1)
	{
		while (++i < len)
			tmp_stack[i] = data->a[data->a_first - i];
	}
	return (tmp_stack);
}

void			ft_sort_stack(int *stack, int len)
{
	int i;
	int j;
	int tmp;

	i = 0;
	while (i < len )
	{
		j = i + 1;
		while (j < len)
		{
			if (stack[i] > stack[j])
			{
				tmp = stack[i];
				stack[i] = stack[j];
				stack[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

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
	int	biggest;
	int smallest;
	int *tmp_stack;

	i = 0;
	biggest = ft_biggest_nb(data, len, 1);
	smallest = ft_smallest_nb(data, len, 1);
	tmp_stack = ft_stackdup(data, len, 1);
	ft_sort_stack(tmp_stack, len);
	while (i <= len)
	{
		if (tmp_stack[1] >= data->a[data->a_first])
			ft_pb(data);
		else
			ft_ra(data, 1);
		i++;
	}
	ft_sort_3_arg(data,len);
		if (data->b[0] > data->b[1])
		ft_sb(data, 1);
//	ft_sort_2_arg(data, len);
	ft_pa(data);
	ft_pa(data);
//	ft_putnbr_fd(len, 1);
//	ft_show_stack(data, 1, len);
//	ft_putstr_fd("\n", 1);
//	ft_show_stack(data, 2, len);
//	ft_putstr_fd("\n", 1);
//	ft_putnbr_fd(data->a_first, 1);
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
//	ft_show_stack(data, len, 1);
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
	if (len == 2)
		ft_sort_2_arg(data, 1);
	if (len == 3)
		ft_sort_3_arg(data, len);
	else if (len == 4)
		ft_sort_4_arg(data, len);
	else if (len == 5)
		ft_sort_5_arg(data, len);
	return (SUCCESS);
}
