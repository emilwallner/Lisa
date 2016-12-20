/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_grid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 10:31:24 by ewallner          #+#    #+#             */
/*   Updated: 2016/12/20 15:44:57 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "fdf.h"
#include <unistd.h>

char	*ft_file_to_str(char *file, int *xlen)
{
	char	*line;
	char	*tmp;
	int		fd;
	int		ret;

	ret = 1;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(0);
	tmp = ft_strnew(0);
	while (ret != 0)
	{
		line = ft_strnew(0);
		ret = get_next_line(fd, &line);
		if (ret == -1)
			return (0);
		*xlen = (*xlen == 0) ? ft_count_words(line, ' ') : *xlen;
		if ((*xlen != ft_count_words(line, ' ') && ret != 0) || xlen == 0)
			return (NULL);
		tmp = ft_strjoin(tmp, " ");
		tmp = ft_strjoin(tmp, line);
		ft_strdel(&line);
	}
	close(fd);
	return (tmp);
}
