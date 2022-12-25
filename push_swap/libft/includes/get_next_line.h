/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisserst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:01:10 by jisserst          #+#    #+#             */
/*   Updated: 2022/12/16 11:01:51 by jisserst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# elif BUFFER_SIZE<0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include <stddef.h>

char	*get_next_line(int fd);
int		ft_strlen1(char *s);
int		ft_strchr1(char *str, char c);
char	*ft_strjoin1(char *s1, char *s2, size_t s2_len);
void	ft_bzero1(void *s, size_t n);
void	*ft_calloc1(size_t nmemb, size_t size);

#endif
