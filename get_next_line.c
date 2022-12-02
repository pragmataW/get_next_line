/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yciftci <yciftci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 00:38:29 by yciftci           #+#    #+#             */
/*   Updated: 2022/12/02 01:41:35 by yciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_raw_line(int fd)
{
	char	*buff;
	char	*ret;

	ret = malloc(sizeof(char));
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (!iscontain(buff))
	{
		read(fd, buff, BUFFER_SIZE);
		ret = ft_strjoin(ret, buff);
	}
	free (buff);
	return (ret);
}

char	*get_after_newline(char *raw_str)
{
	int		i;
	int		j;
	int		after_len;
	char	*tmp;

	i = 0;
	j = 0;
	after_len = count_after_len(raw_str);
	tmp = (char *)malloc(sizeof(char) * (after_len + 1));
	while (raw_str[i] != '\n')
		i++;
	i++;
	while (raw_str[i] != '\0')
	{
		tmp[j] = raw_str[i];
		i++;
		j++;
	}
	tmp[j] = '\0';
	return (tmp);
}

char	*refined_str(char *raw_str, int i)
{
	char	*refined_str;
	int		after_len;
	char	*tmp_raw;

	tmp_raw = get_after_newline(raw_str);
	after_len = count_after_len(raw_str);
	refined_str = (char *)malloc(newline_counter(raw_str) * sizeof(char) + 1);
	while (raw_str[i] != '\n' && raw_str[i] != '\0')
	{
		refined_str[i] = raw_str[i];
		i++;
	}
	refined_str[i] = '\0';
	if (raw_str)
		free(raw_str);
	raw_str = malloc(sizeof(char) * after_len + 1);
	i = 0;
	while (tmp_raw[i] != '\0')
	{
		raw_str[i] = tmp_raw[i];
		i++;
	}
	raw_str[i] = '\0';
	return (refined_str);
}

char	*get_next_line(int fd)
{
	static char	*raw_str;
	char		*refined_string;
	char		*deneme;

	refined_string = NULL;
	if (fd < 0 && BUFFER_SIZE <= 0)
		return (0);
	raw_str = get_raw_line(fd);
	refined_string = refined_str(raw_str, 0);
	deneme = ft_strjoin(refined_string, raw_str);
	//printf("%s", deneme);
}

int	main(void)
{
	//char	*deneme = "yusuf\nselama";
	//printf("%s", refined_str(deneme));
	
	int fd = open("mahmut.txt", O_RDONLY);
	
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
}
