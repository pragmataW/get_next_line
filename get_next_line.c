/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yciftci <yciftci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 00:38:29 by yciftci           #+#    #+#             */
/*   Updated: 2022/12/02 11:48:59 by yciftci          ###   ########.fr       */
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
	char	*refined_string;

	refined_string = malloc(newline_counter(raw_str) + 2);
	while (raw_str[i] != '\n')
	{
		refined_string[i] = raw_str[i];
		i++;
	}	
	refined_string[i] = '\n';
	refined_string[++i] = '\0';
	i = 0;
	return (refined_string);
}

char	*get_next_line(int fd)
{
	static char	*raw_str;
	char		*refined_string;
	char		*tmp;
	int			i;

	i = 0;
	refined_string = NULL;
	if (fd < 0 && BUFFER_SIZE <= 0)
		return (0);
	raw_str = get_raw_line(fd);
	tmp = get_after_newline(raw_str);
	refined_string = refined_str(raw_str, 0);
	if (raw_str)
		free(raw_str);
	raw_str = malloc((ft_strlen(tmp) + 1) * sizeof(char));
	while (tmp[i] != '\0')
	{
		raw_str[i] = tmp[i];
		i++;
	}
	free(tmp);
	return (refined_string);
}

int	main(void)
{
	//char	*deneme = "yusuf\nselama";
	//printf("%s", refined_str(deneme));

	int fd = open("mahmut.txt", O_RDONLY);
	
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
}
