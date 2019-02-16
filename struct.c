/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmyslyvy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 12:31:16 by mmyslyvy          #+#    #+#             */
/*   Updated: 2018/11/16 16:06:04 by mmyslyvy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	**create_res_matrix(int size)
{
	char	**mat;
	int		i;
	int		j;

	mat = malloc(size * sizeof(char*));
	i = 0;
	while (i < size)
	{
		mat[i] = malloc((size + 1) * sizeof(char));
		i++;
	}
	i = -1;
	while (++i < size)
	{
		j = 0;
		while (j < size)
			mat[i][j++] = '.';
		mat[i][j] = '\0';
	}
	return (mat);
}

int		pr(int figures, int square)
{
	char	letter;
	char	**mat;
	t_node	*row_right;
	int		i;
	int		real_id;

	mat = create_res_matrix(square);
	letter = 'A';
	i = -1;
	while (++i <= gind())
	{
		row_right = get_sol(i)->right;
		while (row_right != get_sol(i))
		{
			real_id = row_right->col_id - figures;
			mat[real_id / square][real_id % square] = letter;
			row_right = row_right->right;
		}
		letter++;
	}
	i = -1;
	while (++i < square)
		ft_putendl(mat[i]);
	return (1);
}

int		cover(t_node *target_node)
{
	t_node *row;
	t_node *right_row;

	target_node->left->right = target_node->right;
	target_node->right->left = target_node->left;
	row = target_node->down;
	while (row != target_node)
	{
		right_row = row->right;
		while (right_row != row)
		{
			right_row->up->down = right_row->down;
			right_row->down->up = right_row->up;
			right_row = right_row->right;
		}
		row = row->down;
	}
	return (1);
}

int		uncover(t_node *target_node)
{
	t_node *row;
	t_node *left_row;

	row = target_node->up;
	while (row != target_node)
	{
		left_row = row->left;
		while (left_row != row)
		{
			left_row->up->down = left_row;
			left_row->down->up = left_row;
			left_row = left_row->left;
		}
		row = row->up;
	}
	target_node->left->right = target_node;
	target_node->right->left = target_node;
	return (1);
}

int		solver(t_node *header, char *str, int sqr)
{
	t_node	*col;
	t_node	*row;
	t_node	*row_mov;

	if ((header->right == header || header->right->down == header->right) &&
	(int)((L(str) + 1) / 21) == gind() + 1 && pr((int)((L(str) + 1) / 21), sqr))
		return (1);
	useless_shit(&col, &row, &header);
	while (row != col)
	{
		solution_add(row);
		row_mov = row->right;
		while (row_mov != row && cover(row_mov->column))
			row_mov = row_mov->right;
		if (solver(header, str, sqr) && uncover(col))
			return (1);
		solution_remove();
		row_mov = row->left;
		while (row_mov != row && uncover(row_mov->column))
			row_mov = row_mov->left;
		row = row->down;
		if (g_i >= 1000000)
			break ;
	}
	return (!uncover(col));
}
