/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:16:50 by hugsbord          #+#    #+#             */
/*   Updated: 2021/11/03 19:12:30 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

int	ft_init_data(t_data *data, int len)
{
	data->len = len;
	data->a_first = -1;
	data->b_first = -1;
	data->median = 0;
	data->quarter = 0;
	data->a = ft_calloc(len, sizeof(int));
	data->b = ft_calloc(len, sizeof(int));
	if (!data->a || !data->b)
		return (ERROR);
	return (0);
}
