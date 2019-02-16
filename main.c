/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 19:15:00 by dzaporoz          #+#    #+#             */
/*   Updated: 2018/11/17 16:02:36 by dzaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_readfile(int fd)
{
	int		rb;
	char	buf[547];
	char	*str;

	if (fd < 0 || read(fd, 0, 0))
		return (NULL);
	rb = read(fd, &buf, 547);
	buf[rb] = '\0';
	close(fd);
	if ((rb == 547 || rb < 20) || ((rb + 1) % 21) != 0)
		return (NULL);
	str = buf;
	while (*str)
	{
		if (*str != '.' && *str != '#' && *str != '\n')
			return (NULL);
		str++;
	}
	return (ft_strdup(buf));
}

int		main(int argc, char **argv)
{
	char	*str;
	t_node	*matrix;
	int		square;

	if (argc == 2)
	{
		if ((str = ft_readfile(open(argv[1], O_RDONLY))) == NULL)
		{
			ft_putendl("error");
			return (0);
		}
		square = ft_sqrt((((int)ft_strlen(str) + 1) / 21) * 4) - 1;
		while (++square < 12 && (g_i = 0) == 0)
		{
			if (ft_create_matrix(str, &matrix, square) == 0)
				return (0);
			if (solver(matrix, str, square))
				break ;
			ft_free_matrix(&matrix);
		}
		free(str);
	}
	else
		ft_putendl("usage: fillit file");
	return (0);
}
