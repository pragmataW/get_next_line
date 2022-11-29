/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yciftci <yciftci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 00:38:29 by yciftci           #+#    #+#             */
/*   Updated: 2022/11/29 17:02:13 by yciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_raw_line(int fd, char *raw_str)
{
	char	buff[BUFFER_SIZE];
	char	*ret;

	while (!ft_strchr(raw_str))
	{
		read(fd, buff, BUFFER_SIZE);
		ret = ft_strjoin(ret, buff);
	}
}

char	*get_next_line(int fd)
{
	static char	*raw_str;

	if (fd < 0 && BUFFER_SIZE <= 0)
		return (0);
	raw_str = get_raw_line(fd, raw_str);
}
