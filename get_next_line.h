/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yciftci <yciftci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 00:35:54 by yciftci           #+#    #+#             */
/*   Updated: 2022/12/05 16:15:14 by yciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_strlen(char *str);
int		newline_counter(char *raw_str);
char	*ft_strjoin(char *s1, char *s2);
int		iscontain(char *str);
int		count_after_nl(char *raw_str);
char	*get_raw_line(int fd, char *raw_str);
char	*get_refined_str(char *raw_str);
char	*get_new_raw_str(char *raw_str);
char	*get_next_line(int fd);

#endif