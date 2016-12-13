/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_grid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 10:31:24 by ewallner          #+#    #+#             */
/*   Updated: 2016/12/13 17:46:23 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "fdf.h"
#include <unistd.h>

char		*ft_file_to_str(char *file, int *xlen)
{
	char *line;
	char *tmp;
	char *del;
	int		fd;
	int		ret;

	fd = open(file, O_RDONLY);
	line = ft_strnew(0);
	tmp = ft_strnew(0);
	while(ret != 0)
	{
		//line = ft_strnew(0);
		ret = get_next_line(fd, &line);
		if (ret == -1)
			return (0);
		*xlen = (*xlen == 0) ? ft_count_words(line, ' ') : *xlen;
		if (*xlen != ft_count_words(line, ' '))
			return (NULL);
		del = tmp;
		tmp = ft_strjoin(tmp, " ");
		ft_strdel(&del);
		del = tmp;
		tmp = ft_strjoin(tmp, line);
	//	ft_strdel(&line);
		ft_strdel(&del);
	}
	close(fd);
	return (tmp);
}



