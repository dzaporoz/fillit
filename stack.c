/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmyslyvy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 13:20:21 by mmyslyvy          #+#    #+#             */
/*   Updated: 2018/11/16 16:07:01 by mmyslyvy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_node	*g_solutions[123];
int		g_ind = -1;

void	solution_add(t_node *row)
{
	t_node	*row_right;
	t_node	*min;

	g_ind++;
	row_right = row->right;
	min = row;
	while (row_right != row)
	{
		if (row_right->row_id < min->row_id)
			min = row_right;
		row_right = row_right->right;
	}
	g_solutions[g_ind] = min;
}

t_node	*get_sol(int i)
{
	return (g_solutions[i]);
}

int		gind(void)
{
	return (g_ind);
}

void	solution_remove(void)
{
	if (g_ind >= 0)
	{
		g_solutions[g_ind] = NULL;
		g_ind--;
	}
}

void	useless_shit(t_node **col, t_node **row, t_node **header)
{
	*col = (*header)->right;
	cover(*col);
	*row = (*col)->down;
	g_i++;
}
