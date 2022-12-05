/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yciftci <yciftci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 00:38:29 by yciftci           #+#    #+#             */
/*   Updated: 2022/12/05 15:05:22 by yciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_raw_line(int fd, char* raw_str)
{
	char	*buff;
	int		byte;

	byte = 1;
	if (!raw_str)
		raw_str = malloc(sizeof(char));
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (!iscontain(raw_str) && byte != 0)
	{
		byte = read(fd, buff, BUFFER_SIZE);
		if (byte == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[byte]='\0';
		raw_str = ft_strjoin(raw_str, buff);
	}
	free(buff);
	return (raw_str);
}

char	*get_refined_str(char *raw_str)
{
	char	*ret;
	int		after_newline;
	int		i;
	
	i = 0;
	after_newline = newline_counter(raw_str);
	ret = malloc(sizeof(char) * (after_newline + 1));
	if (!ret)
		return (0);
	while(raw_str[i] != '\0' && raw_str[i] != '\n')
	{
		ret[i] = raw_str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*get_new_raw_str(char *raw_str)
{
	int		len;
	char	*res;
	int		i;

	i = 0;
	while (raw_str[i] != '\n' && raw_str[i] != '\0')
		i++;
	i++;
	len = ft_strlen(&raw_str[i]);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	len = 0;
	while (raw_str[i] != '\0')
	{
		res[len] = raw_str[i];
		len++;
		i++;
	}
	free(raw_str);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*raw_str;
	char		*refined_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	raw_str = get_raw_line(fd, raw_str);
	if (!raw_str)
		return (NULL);
	refined_str = get_refined_str(raw_str);
	raw_str = get_new_raw_str(raw_str);
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
	//printf("%s\n", get_next_line(fd));
	//printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("\n-----------------------\n");
	printf("%s\n", get_next_line(fd));
	printf("\n-----------------------\n");
	printf("%s\n", get_next_line(fd));
	//while (1);
}
