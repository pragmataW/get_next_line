/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utlis.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yciftci <yciftci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 00:34:02 by yciftci           #+#    #+#             */
/*   Updated: 2022/12/01 23:41:44 by yciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	counter;

	counter = 0;
	while (str[counter] != '\0')
		counter++;
	return (counter);
}

int	newline_counter(char *raw_str)
{
	int	counter;

	counter = 0;
	while (raw_str[counter] != '\n' && raw_str[counter] != '\0')
		counter++;
	return (counter);
}

char	*ft_strjoin(char *dest, char *src)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = (char *)malloc((ft_strlen(src) + ft_strlen(dest) + 1) * sizeof(char));
	while (dest[i] != '\0')
		res[j++] = dest[i++];
	i = 0;
	while (src[i] != '\0')
		res[j++] = src[i++];
	res[j] = '\0';
	free (dest);
	return (res);
}

int	iscontain(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		return (1);
	return (0);
}

int	count_after_len(char *raw_str)
{
	int	after_len;
	int	i;

	i = 0;
	after_len = 0;
	while (raw_str[i] != '\n')
		i++;
	i++;
	while (raw_str[i++] != '\0')
		after_len++;
	return (after_len);
}
