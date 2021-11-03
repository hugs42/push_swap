/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:14:22 by hugsbord          #+#    #+#             */
/*   Updated: 2021/11/03 19:15:38 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

int	*ft_stackdup(t_data *data, int len, int stack)
{
	int	*tmp_stack;
	int	i;

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

void	ft_sort_stack(int *stack, int len)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < len)
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

int	ft_biggest_nb(t_data *data, int len, int stack)
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

int	ft_smallest_nb(t_data *data, int len, int stack)
{
	int	i;
	int	smallest;

	i = 0;
	if (stack == 1)
	{
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
