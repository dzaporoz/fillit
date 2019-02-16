/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matr_cr_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 14:19:08 by dzaporoz          #+#    #+#             */
/*   Updated: 2018/11/15 14:20:50 by dzaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_create_matrix(char *str, t_node **matrix, int width)
{
	int		n;
	int		num;
	t_node	*temp;

	n = 0;
	num = (int)((ft_strlen(str) + 1) / 21) + width * width;
	*matrix = ft_new_node();
	temp = *matrix;
	temp->col_id = -1;
	while (n++ < num)
	{
		temp->right = ft_new_node();
		temp->right->left = temp;
		temp = temp->right;
		temp->col_id = n - 1;
	}
	temp->right = *matrix;
	(*matrix)->left = temp;
	if (!ft_fill_matrix(str, matrix, width))
	{
		ft_putendl("error");
		return (0);
	}
	return (1);
}

void	ft_free_matrix(t_node **matrix)
{
	t_node	*temp1;
	t_node	*temp2;
	t_node	*temp3;

	temp1 = *matrix;
	temp1->left->right = NULL;
	while (temp1)
	{
		temp2 = temp1->down;
		while (temp2 && temp2 != temp1)
		{
			temp3 = temp2->down;
			free(temp2);
			temp2 = temp3;
		}
		temp3 = temp1->right;
		free(temp1);
		temp1 = temp3;
	}
	*matrix = NULL;
}
