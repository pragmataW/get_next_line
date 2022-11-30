/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yciftci <yciftci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 00:35:54 by yciftci           #+#    #+#             */
/*   Updated: 2022/11/30 19:52:22 by yciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 4

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

int		ft_strlen(char *str);
char	*ft_strjoin(char *dest, char *src);
char	*ft_strchr(char *str);
char	*get_next_line(int fd);
char	*get_raw_line(int fd, char *raw_str);

#endif