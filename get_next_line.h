/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yciftci <yciftci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 00:35:54 by yciftci           #+#    #+#             */
/*   Updated: 2022/12/02 05:43:09 by yciftci          ###   ########.fr       */
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
int		newline_counter(char *raw_str);
char	*ft_strjoin(char *s1, char *s2);
int		iscontain(char *str);
int		count_after_len(char *raw_str);
char	*get_raw_line(int fd);
char	*get_after_newline(char *raw_str);
char	*refined_str(char *raw_str, int i);
char	*get_next_line(int fd);

#endif