/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 14:26:20 by dzaporoz          #+#    #+#             */
/*   Updated: 2018/11/15 14:27:15 by dzaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_sqrt(int n)
{
	int m;

	if (n == 4 || n == 8)
		return (2);
	m = 1;
	while (m * m < n)
		m++;
	return (m);
}

t_node	*ft_get_node(t_node **matrix, int col, int row)
{
	int		x;
	int		y;
	t_node	*temp;

	temp = (*matrix)->right;
	x = 0;
	y = 0;
	while (temp->col_id != col && (x++ < 1000))
		temp = temp->right;
	while (temp->row_id != row && (y++ < 1000))
		temp = temp->down;
	if (x == 1001 || y == 1001)
		return (NULL);
	return (temp);
}

void	ft_get_borders(int offsets[7], int width)
{
	int n;
	int m;

	n = 0;
	m = 0;
	offsets[4] = 0;
	if ((offsets[3] - (width - 1) == offsets[2] || offsets[3] - (width - 1) ==
		offsets[1] || offsets[3] - (width * 2 - 1) == offsets[1]) && offsets[3]
		- width != offsets[1])
		offsets[4] = 1;
	if (offsets[3] - (width - 2) == offsets[2])
		offsets[4] = 2;
	while (n < width)
	{
		if (offsets[0] == n || offsets[1] == n || offsets[2] == n || offsets[3]
		== n || offsets[1] == n + width || offsets[3] == n + width || offsets[2]
		== n + width || offsets[2] == n + width * 2
		|| offsets[3] == n + width * 2)
			m++;
		n++;
	}
	offsets[5] = m;
}

void	ft_change_array(int *array, int n)
{
	array[0] -= n;
	array[1] -= n;
	array[2] -= n;
	array[3] -= n;
}

int		ft_get_offsets(int *offsets, char *str, int width)
{
	int n;

	n = 0;
	while (*str)
	{
		if (*str == '#' && (*offsets = n) == n)
			offsets++;
		if (*str == '\n')
			n--;
		n++;
		str++;
	}
	offsets = offsets - 4;
	while (offsets[0] >= 4)
		ft_change_array(offsets, 4);
	while (0 != offsets[0] && 0 != offsets[1] && 0 != offsets[1] - 4 && 0
		!= offsets[2] - 8 && 0 != offsets[2] - 4)
		ft_change_array(offsets, 1);
	n = -1;
	while (++n < 4)
		offsets[n] = offsets[n] - ((offsets[n] / 4) * 4) +
		((offsets[n] / 4) * width);
	ft_get_borders(offsets, width);
	return (1);
}
