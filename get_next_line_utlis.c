/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utlis.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yciftci <yciftci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 00:34:02 by yciftci           #+#    #+#             */
/*   Updated: 2022/11/29 16:37:07 by yciftci          ###   ########.fr       */
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

char	*ft_strjoin(char *src, char *dest)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = (char *)malloc((ft_strlen(src) + ft_strlen(dest) + 1) * sizeof(char));
	while (src[i] != '\0')
		res[j++] = src[i++];
	i = 0;
	while (dest[i] != '\0')
		res[j++] = dest[i++];
	res[j] = '\0';
	free(src);
	return (res);
}

char	*ft_strchr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		return (&str[i]);
	return (0);
}
