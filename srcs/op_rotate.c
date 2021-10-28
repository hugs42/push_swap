/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 17:05:06 by hugsbord          #+#    #+#             */
/*   Updated: 2021/10/27 17:29:05 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

void	ft_ra(t_data *data, int is_op)
{
	int		i;
	int		tmp;


	i = data->a_first;
	tmp = 0;
	if (i != -1)
	{
		tmp = data->a[data->a_first];
		while (i > 0)
		{
			data->a[i] = data->a[i - 1];
			i--;
		}
		data->a[0] = tmp;
	}
	if (is_op)
		ft_putstr_fd("ra\n", 1);
}

void	ft_rb(t_data *data, int is_op)
{
	int	i;
	int	tmp;

	i = data->b_first;
	tmp = 0;
	if (i != -1)
	{
		tmp = data->b[data->b_first];
		while (i > 0)
		{
			data->b[i] = data->b[i - 1];
			i--;
		}
		data->b[0] = tmp;
	}
	if (is_op)
		ft_putstr_fd("rb\n", 1);
}

void	ft_rr(t_data *data)
{
	ft_ra(data, 0);
	ft_rb(data, 0);
	ft_putstr_fd("rr\n", 1);
}
