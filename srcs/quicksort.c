/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:54:17 by hugsbord          #+#    #+#             */
/*   Updated: 2021/11/06 18:21:29 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"
#include <stdio.h>

void	ft_quicksort_len_4(t_data *data)
{
	if (data->a[data->a_first] > data->a[data->a_first - 1])
		ft_sa(data, 1);
	ft_pb(data);
	if (data->a[data->a_first] > data->a[data->a_first - 1])
		ft_sa(data, 1);
	ft_pb(data);
	if (data->a[data->a_first] > data->a[data->a_first - 1]
		&& data->b[data->b_first] < data->b[data->b_first - 1])
		ft_ss(data);
	else if (data->a[data->a_first] > data->a[data->a_first - 1])
		ft_sa(data, 1);
	else if (data->b[data->b_first] < data->b[data->b_first - 1])
		ft_sb(data, 1);
	ft_pa(data);
	if (data->a[data->a_first] > data->a[data->a_first - 1])
		ft_sa(data, 1);
	ft_pa(data);
	if (data->a[data->a_first] > data->a[data->a_first - 1])
		ft_sa(data, 1);
}

int		ft_already_sort_a(t_data *data, int len)
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

int		ft_already_sort_b(t_data *data, int len)
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

void		ft_quicksort_few_a(t_data *data, int len)
{
	if (len == 2 || len == 3)
	{
		if (data->a[data->a_first] > data->a[data->a_first - 1])
			ft_sa(data, 1);
		if (len == 3)
		{
			if (data->a[data->a_first - 1] > data->a[data->a_first - 2])
			{
				ft_ra(data, 1);
				ft_sa(data, 1);
				ft_rra(data, 1);
				if (data->a[data->a_first] > data->a[data->a_first - 1])
					ft_sa(data, 1);
			}
		}
	}
	if (len == 4)
		ft_quicksort_len_4(data);
}

void			ft_quicksort_few_b(t_data *data, int len)
{
	if (len >= 1 && len <= 3)
		ft_pa(data);
	if (len == 2 || len == 3)
	{
		ft_pa(data);
		if (data->a[data->a_first] > data->a[data->a_first - 1])
			ft_sa(data, 1);
		if (len == 3)
		{
			ft_pa(data);
			if (data->a[data->a_first] > data->a[data->a_first - 1])
				ft_sa(data, 1);
			if (data->a[data->a_first - 1] > data->a[data->a_first - 2])
			{
				ft_ra(data, 1);
				ft_sa(data, 1);
				ft_rra(data, 1);
				if (data->a[data->a_first] > data->a[data->a_first - 1])
					ft_sa(data, 1);
			}
		}
	}
}

int		ft_partitioning_to_a(t_data *data, t_counter *c, t_pivot p, int len)
{
	int i;

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

int		ft_partitioning_to_b(t_data *data, t_counter *c, t_pivot p, int len)
{
	int i;

	i = 0;
//	printf("LEN=%d\n", len);
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

t_pivot		ft_pivot(t_data *data, int len, int flag)
{
	int	*tmp_stack;
	int	point;
	t_pivot p;

	if (flag == 1)
		tmp_stack = ft_stackdup(data, len, 1);
	else
		tmp_stack = ft_stackdup(data, len, 2);
	ft_sort_stack(tmp_stack, len);
	int j = 0;
//	while (tmp_stack[j])
//	{
//		printf("->%d\n", tmp_stack[j]);
//		j++;
//	}
	point = len / 3;
	if (len % 3 == 2)
		point++;
//	printf("TERM%d\n", point);
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
//	printf("P1=%d\n", p.p1);
//	printf("P2=%d\n", p.p2);
	free(tmp_stack);
	return (p);
}

int			ft_quicksort_b_to_a(t_data *data, int len)
{
	int			i;
	t_counter c;
	t_pivot p;

	i = 0;
	c  = (t_counter){0, 0, 0, 0};
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
//	printf("p1%d\n", p.p1);
//	printf("p2%d\n", p.p2);
	ft_partitioning_to_a(data, &c, p,len);
//	printf("RAC=%d\n", c.ra_count);
//	printf("RBC=%d\n",c.rb_count);
//	printf("PBC=%d\n",c.pb_count);

	ft_quicksort_a_to_b(data, c.pa_count - c.ra_count);
//	printf("RAC=%d\n", c.ra_count);
//	printf("RBC=%d\n",c.rb_count);
//	printf("PBC=%d\n",c.pb_count);
	while (i++ < c.ra_count)
		ft_rrr(data);
	ft_quicksort_a_to_b(data, c.rb_count);
	ft_quicksort_b_to_a(data, c.ra_count);
	return (SUCCESS);
}

int		ft_quicksort_a_to_b(t_data *data, int len)
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
	ft_partitioning_to_b(data,&c ,p, len);
//	printf("RAC=%d\n", c.ra_count);
//	printf("RBC=%d\n",c.rb_count);
//	printf("PBC=%d\n",c.pb_count);
//	printf("RBC=%d\n",c.rb_count);
	while (i++ < c.ra_count)
		ft_rrr(data);
	ft_quicksort_a_to_b(data, c.ra_count);
	ft_quicksort_b_to_a(data, c.rb_count);
	ft_quicksort_b_to_a(data, c.pb_count - c.rb_count);
	return (SUCCESS);
}
