/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yciftci <yciftci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 00:38:29 by yciftci           #+#    #+#             */
/*   Updated: 2022/11/30 20:02:34 by yciftci          ###   ########.fr       */
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
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*raw_str;

	if (fd < 0 && BUFFER_SIZE <= 0)
		return (0);
	raw_str = get_raw_line(fd, raw_str);
}

int main()
{
	int fd = open("deneme.txt", O_RDONLY);
	printf("%d\n", fd);
	char *deneme = get_raw_line(fd, deneme);
}