/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:54:17 by hugsbord          #+#    #+#             */
/*   Updated: 2021/11/07 03:35:15 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

int	ft_partitioning_to_a(t_data *data, t_counter *c, t_pivot p, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (data->b[data->b_first] <= p.p2)
		{
			ft_rb(data, 1);
			c->rb_count += 1;
		}
		else
		{
			ft_pa(data);
			c->pa_count++;
			if (data->a[data->a_first] <= p.p1)
			{
				ft_ra(data, 1);
				c->ra_count += 1;
			}
		}
		i++;
	}
	return (SUCCESS);
}

int	ft_partitioning_to_b(t_data *data, t_counter *c, t_pivot p, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (data->a[data->a_first] >= p.p1)
		{
			ft_ra(data, 1);
			c->ra_count += 1;
		}
		else
		{
			ft_pb(data);
			c->pb_count += 1;
			if (data->b[data->b_first] >= p.p2)
			{
				ft_rb(data, 1);
				c->rb_count += 1;
			}
		}
		i++;
	}
	return (SUCCESS);
}

t_pivot	ft_pivot(t_data *data, int len, int flag)
{
	int		*tmp_stack;
	int		point;
	t_pivot	p;

	if (flag == 1)
		tmp_stack = ft_stackdup(data, len, 1);
	else
		tmp_stack = ft_stackdup(data, len, 2);
	ft_sort_stack(tmp_stack, len);
	point = len / 3;
	if (len % 3 == 2)
		point++;
	if (flag == 1)
	{
		p.p1 = tmp_stack[len - point];
		p.p2 = tmp_stack[len - point * 2];
	}
	else
	{
		p.p1 = tmp_stack[point * 2 - 1];
		p.p2 = tmp_stack[point - 1];
	}
	free(tmp_stack);
	return (p);
}

int	ft_quicksort_b_to_a(t_data *data, int len)
{
	int			i;
	t_counter	c;
	t_pivot		p;

	i = 0;
	c = (t_counter){0, 0, 0, 0};
	if (ft_already_sort_b(data, len) == SUCCESS)
	{
		while (len--)
			ft_pa(data);
		return (SUCCESS);
	}
	if (len < 4)
	{
		ft_quicksort_few_b(data, len);
		return (SUCCESS);
	}
	p = ft_pivot(data, len, 0);
	ft_partitioning_to_a(data, &c, p, len);
	ft_quicksort_a_to_b(data, c.pa_count - c.ra_count);
	while (i++ < c.ra_count)
		ft_rrr(data);
	ft_quicksort_a_to_b(data, c.rb_count);
	ft_quicksort_b_to_a(data, c.ra_count);
	return (SUCCESS);
}

int	ft_quicksort_a_to_b(t_data *data, int len)
{
	int			i;
	t_counter	c;
	t_pivot		p;

	i = 0;
	c = (t_counter){0, 0, 0, 0};
	if (ft_already_sort_a(data, len))
		return (SUCCESS);
	if (len < 5)
	{
		ft_quicksort_few_a(data, len);
		return (SUCCESS);
	}
	p = ft_pivot(data, len, 1);
	ft_partitioning_to_b(data, &c, p, len);
	while (i++ < c.ra_count)
		ft_rrr(data);
	ft_quicksort_a_to_b(data, c.ra_count);
	ft_quicksort_b_to_a(data, c.rb_count);
	ft_quicksort_b_to_a(data, c.pb_count - c.rb_count);
	return (SUCCESS);
}
