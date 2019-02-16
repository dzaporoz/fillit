/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 14:15:56 by dzaporoz          #+#    #+#             */
/*   Updated: 2018/11/17 16:03:54 by dzaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_matrix_to_zero(int matrix[4][4])
{
	int n;
	int m;

	n = -1;
	while (++n < 4 && (m = -1) == -1)
		while (++m < 4)
		{
			matrix[n][m] = 0;
		}
}

int		ft_add_relations(int matrix[4][4])
{
	int n;
	int m;
	int r;

	r = 0;
	n = -1;
	while (++n < 4 && (m = -1) == -1)
		while (++m < 4)
			r += matrix[n][m];
	return (r);
}

void	ft_free_str(char **str)
{
	char	*temp;
	int		n;

	n = 0;
	temp = str[0];
	while (temp)
	{
		free(temp);
		n++;
		temp = str[n];
	}
	free(str);
}

int		ft_validation2(char **str)
{
	int sharps;
	int n;
	int m;

	sharps = 0;
	n = 0;
	while (str[n])
	{
		m = 0;
		while (str[n][m])
		{
			if (str[n][m] == '#')
				sharps++;
			if (str[n][m] != '.' && str[n][m] != '#')
				return (0);
			m++;
		}
		if (m != 4)
			return (0);
		n++;
	}
	if (sharps != 4)
		return (0);
	return (1);
}

int		ft_validate_puzzle(char **str)
{
	int n;
	int m;
	int matrix[4][4];
	int r;

	n = -1;
	ft_matrix_to_zero(matrix);
	while (++n < 4 && (m = -1) == -1)
		while (++m < 4)
		{
			if (n > 0 && str[n - 1][m] == '#' && str[n][m] == '#')
				matrix[n][m] += 1;
			if (n < 3 && str[n + 1][m] == '#' && str[n][m] == '#')
				matrix[n][m] += 1;
			if (m > 0 && str[n][m - 1] == '#' && str[n][m] == '#')
				matrix[n][m] += 1;
			if (m < 3 && str[n][m + 1] == '#' && str[n][m] == '#')
				matrix[n][m] += 1;
		}
	r = ft_add_relations(matrix);
	if ((r != 6 && r != 8) || !ft_validation2(str))
		return (0);
	ft_free_str(str);
	return (1);
}
