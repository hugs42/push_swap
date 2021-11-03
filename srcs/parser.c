/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:14:25 by hugsbord          #+#    #+#             */
/*   Updated: 2021/11/03 17:01:21 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

int		ft_parse_input(t_data *data, int argc, char **argv)
{
	int		i;
	int		len;
	int		tmp_i;
	char	**input;

	i = 1;
	len = 0;
	while (i < argc)
		len += ft_check_len(argv[i++], ' ');
	ft_init_data(data, len);
	i = 1;
	while (i < argc)
	{
		tmp_i = 0;
		input = ft_split(argv[i++], ' ');
		while (input[tmp_i])
		{
			data->a_first += 1;
			if (ft_check_char(input[tmp_i]) == ERROR)
				return (ERROR);
			data->a[data->a_first] = ft_atoi(input[tmp_i]);
//			if (!data->a[data->a_first])
//			{
//				ft_putstr_fd("aaa",1);
//				return (ERROR);
//			}
			tmp_i++;
			if (ft_check_double(data->a, data->a_first, data->a[data->a_first]) == ERROR)
				return (ERROR);
		}
//		ft_free_input(input);
	}
	ft_reverse_stack(data);
//	ft_putnbr_fd(data->a_first, 1);
//	ft_putstr_fd("\n***",1);
//	ft_show_stack(data, 1, len);
	return (0);
}
