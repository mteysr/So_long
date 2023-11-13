/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: metyasar <metyasar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:24:06 by metyasar          #+#    #+#             */
/*   Updated: 2023/11/09 19:49:10 by metyasar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(t_list *data)
{
	free(data);
	write(2, "Error\n", 6);
	write(1, "Wrong value", 11);
	exit(1);
}

int	map_is_square(t_list *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->row && data->map[i] != NULL)
	{
		if (ft_strlen(data->map[i]) != data->colon)
			return (0);
		i++;
	}
	return (1);
}

int	map_name_control(t_list *data, char *av)
{
	int	len;

	(void)data;
	len = ft_strlen(av) - 1;
	if (av[len] != 'r' || av[len - 1] != 'e' || av[len - 2] != 'b'
		|| av[len - 3] != '.')
		return (0);
	if (av[len - 4] == '/' || ft_strlen(av) < 5)
		return (0);
	return (1);
}

void	is_true_map(t_list *data, int i, int j)
{
	data->maptmp[i][j] = '*';
	if (data->maptmp[i - 1][j] != '1' && data->maptmp[i - 1][j] != '*'
		&& data->maptmp[i - 1][j] != 'E')
		is_true_map(data, i - 1, j);
	if (data->maptmp[i][j + 1] != '1' && data->maptmp[i][j + 1] != '*'
		&& data->maptmp[i][j + 1] != 'E')
		is_true_map(data, i, j + 1);
	if (data->maptmp[i + 1][j] != '1' && data->maptmp[i + 1][j] != '*'
		&& data->maptmp[i + 1][j] != 'E')
		is_true_map(data, i + 1, j);
	if (data->maptmp[i][j - 1] != '1' && data->maptmp[i][j - 1] != '*'
		&& data->maptmp[i][j - 1] != 'E')
		is_true_map(data, i, j - 1);
}

int	start_control(t_list *data)
{
	int	i;
	int	flag;
	int	j;

	j = 0;
	i = 0;
	flag = 0;
	while (i < data->row - 1)
	{
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
				flag++;
			j++;
		}
		j = 0;
		i++;
	}
	if (flag >= 2 || flag <= 0)
		return (0);
	else
		return (1);
}
