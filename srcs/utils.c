/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:14:22 by hugsbord          #+#    #+#             */
/*   Updated: 2021/11/08 10:50:32 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

int	ft_already_sort_a(t_data *data, int len)
{
	int		i;

	i = 0;
	i = data->a_first - len + 1;
	while (i < data->a_first)
	{
		if (data->a[i] < data->a[i + 1])
			return (0);
		i++;
	}
	return (SUCCESS);
}

int	ft_already_sort_b(t_data *data, int len)
{
	int		i;

	i = 0;
	i = data->b_first - len + 1;
	while (i < data->b_first)
	{
		if (data->b[i] > data->b[i + 1])
			return (0);
		i++;
	}
	return (SUCCESS);
}

int	*ft_stackdup(t_data *data, int len, int stack)
{
	int	i;
	int	*tmp_stack;

	i = -1;
	tmp_stack = ft_calloc(len, sizeof(int));
	if (!tmp_stack)
		exit(1);
	if (stack == 1)
	{
		while (++i < len)
			tmp_stack[i] = data->a[data->a_first - i];
	}
	else if (stack == 2)
	{
		while (++i < len)
			tmp_stack[i] = data->b[data->b_first - i];
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
	return (smallest);
}
