/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:14:22 by hugsbord          #+#    #+#             */
/*   Updated: 2021/11/06 18:25:18 by hugsbord         ###   ########.fr       */
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
