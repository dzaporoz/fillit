/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_matr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 14:22:52 by dzaporoz          #+#    #+#             */
/*   Updated: 2018/11/15 14:24:05 by dzaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_node	*ft_new_node(void)
{
	t_node *new;

	if (!(new = (t_node*)malloc(sizeof(t_node))))
		return (NULL);
	new->left = NULL;
	new->right = NULL;
	new->up = new;
	new->down = new;
	new->column = NULL;
	new->row_id = 0;
	new->col_id = 0;
	new->node_count = 0;
	return (new);
}

t_node	*ft_insert_node(t_node *matrix, int col_id, int row_id)
{
	t_node *new;
	t_node *header;

	header = matrix;
	while (header->col_id != col_id)
		header = header->right;
	new = ft_new_node();
	new->col_id = col_id;
	new->column = header;
	new->row_id = row_id;
	new->down = header;
	new->up = header->up;
	header->up->down = new;
	header->up = new;
	return (new);
}

void	ft_insert_row(t_node *temp, int rrow, int ifigures, int offsets[7])
{
	ft_insert_node(temp, temp->col_id, rrow);
	temp = temp->up;
	temp->right = ft_insert_node(temp->column, ifigures + offsets[0], rrow);
	temp->right->left = temp;
	temp->right->right = ft_insert_node(temp->column, ifigures + offsets[1],
			rrow);
	temp->right->right->left = temp->right;
	temp->right->right->right = ft_insert_node(temp->column, ifigures +
	offsets[2], rrow);
	temp->right->right->right->left = temp->right->right;
	temp->right->right->right->right = ft_insert_node(temp->column, ifigures +
	offsets[3], rrow);
	temp->right->right->right->right->left = temp->right->right->right;
	temp->right->right->right->right->right = temp;
	temp->left = temp->right->right->right->right;
}

void	ft_fill_figure(t_node **matrix, int figures, int offsets[7], int width)
{
	t_node		*temp;
	int			i;

	i = 0;
	temp = *matrix;
	temp = temp->right;
	while (temp != temp->up)
		temp = temp->right;
	while (offsets[3] + figures + i <= width * width + figures - 1)
	{
		if (i % width <= width - offsets[5])
		{
			ft_insert_row(temp, offsets[6], i + figures, offsets);
			offsets[6]++;
		}
		i++;
	}
}

int		ft_fill_matrix(char *str, t_node **matrix, int width)
{
	int		figures;
	int		offset[7];
	char	*temp;

	figures = (int)((ft_strlen(str) + 1) / 21);
	offset[6] = 1;
	while (*str)
	{
		temp = ft_strsub(str, 0, 20);
		if (ft_validate_puzzle(ft_strsplit(temp, '\n')) &&
			ft_get_offsets(offset, temp, width))
			ft_fill_figure(matrix, figures, offset, width);
		else
			return (0);
		str += 20;
		if (*str != '\n' && *str != '\0')
			return (0);
		if (*str == '\n')
			str++;
		free(temp);
	}
	return (1);
}
