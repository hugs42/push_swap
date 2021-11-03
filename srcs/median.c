/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:10:39 by hugsbord          #+#    #+#             */
/*   Updated: 2021/11/03 17:53:40 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

int		ft_median(t_data *data)
{
	int		i;
	int		quarter_len;
	int		*tmp_stack;

	i = 0;
	quarter_len = 0;
	tmp_stack = ft_stackdup(data, data->len, 1);
	ft_sort_stack(tmp_stack, data->len);
	data->median = data->len / 2;
	data->quarter = data->len / 4;
	
	return (SUCCESS);
}
