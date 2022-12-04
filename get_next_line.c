/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yciftci <yciftci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 00:38:29 by yciftci           #+#    #+#             */
/*   Updated: 2022/12/04 20:22:28 by yciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_raw_line(int fd)
{
	char	*buff;
	char	*ret;
	int		byte;
	
	byte = 1;
	ret = malloc(sizeof(char));
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	buff[BUFFER_SIZE] = '\0';
	while (!iscontain(ret) &&  byte != 0)
	{
		byte = read(fd, buff, BUFFER_SIZE);
		ret = ft_strjoin(ret, buff);
	}
	free(buff);
	return (ret);
}

char	*get_refined_str(char *raw_str)
{
	char	*ret;
	int		after_newline;
	int		i;
	
	i = 0;
	after_newline = newline_counter(raw_str);
	ret = malloc(sizeof(char) * (after_newline + 1));
	while(raw_str[i] != '\0' && raw_str[i] != '\n')
	{
		ret[i] = raw_str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*get_new_raw_str(char *raw_str, int i)
{
	int		len;
	char	*res;

	while (raw_str[i] != '\n' && raw_str[i] != '\0')
		i++;
	i++;
	len = ft_strlen(&raw_str[i]);
	res = malloc(sizeof(char) * (len + 1));
	res[len] = '\0';
	len = 0;
	while (raw_str[i] != '\0')
	{
		res[len] = raw_str[i];
		len ++;
		i++;
	}
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*raw_str;
	char		*refined_str;

	raw_str = get_raw_line(fd);
	refined_str = get_refined_str(raw_str);
	raw_str = get_new_raw_str(raw_str, 0);
	return(refined_str);
}


int	main(void)
{
	int fd = open("mahmut.txt", O_RDONLY);
	// printf("%s",get_next_line(fd));
	// printf("%s",get_next_line(fd));
	// printf("%s",get_next_line(fd));
	// printf("%s",get_next_line(fd));
	// printf("%s",get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	//while (1);
}
