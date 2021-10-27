/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:16:50 by hugsbord          #+#    #+#             */
/*   Updated: 2021/10/27 16:19:39 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

int		ft_init_data(t_data *data, int len)
{
	data->len = len;
	data->a_first = -1;
	data->b_first = -1;
	data->a = ft_calloc(len, sizeof(int));
	data->b = ft_calloc(len, sizeof(int));
	if (!data->a || !data->b)
		return (ERROR);
	return (0);
}
