/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:54:35 by dzaporoz          #+#    #+#             */
/*   Updated: 2018/11/16 16:08:08 by mmyslyvy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H

# define FT_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"

# define L ft_strlen

int						g_i;

typedef struct			s_tetrimino
{
	struct s_tetrimino	*left;
	struct s_tetrimino	*right;
	struct s_tetrimino	*up;
	struct s_tetrimino	*down;
	struct s_tetrimino	*column;
	int					row_id;
	int					col_id;
	int					node_count;
}						t_node;

void					ft_free_str(char **str);
int						ft_sqrt(int n);
t_node					*ft_get_node(t_node **matrix, int col, int row);
t_node					*ft_new_node(void);
t_node					*ft_insert_node(t_node *matrix, int col_id, int row_id);
void					ft_free_matrix(t_node **matrix);
void					t_matrix_to_zero(int matrix[4][4]);
int						ft_add_relations(int matrix[4][4]);
int						ft_validate_puzzle(char **str);
void					ft_get_borders(int offsets[6], int width);
void					ft_change_array(int *array, int n);
int						ft_get_offsets(int *offsets, char *str, int width);
void					ft_insert_row(t_node *tmp, int row, int fgr, int os[6]);
void					ft_fill_figure(t_node **m, int fgr, int os[6], int wd);
int						ft_fill_matrix(char *str, t_node **matrix, int width);
int						ft_create_matrix(char *str, t_node **matrix, int width);
char					*ft_readfile(int fd);
void					solution_add(t_node *row);
void					solution_remove(void);
int						pr(int figures, int n);
int						cover(t_node *target_node);
int						uncover(t_node *target_node);
int						solver(t_node *header, char *str, int n);
int						gind(void);
t_node					*get_sol(int i);
void					useless_shit(t_node **col, t_node **row, t_node **hd);

#endif
