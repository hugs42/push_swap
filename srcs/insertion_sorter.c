/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sorter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:54:17 by hugsbord          #+#    #+#             */
/*   Updated: 2021/11/03 18:43:42 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

int		ft_sort_by_insertion(t_data *data)
{
	ft_median(data);
	while (data->a)
	{
//		ft_a_to_b(data);
	}
	return (SUCCESS);
}


int		ft_quicksorting(t_data *data)
{
	int pivot;
	int i;
	int j;
	int start;
	int	end;

	start = 0;
	end = data->len;
	return (SUCCESS);
}
