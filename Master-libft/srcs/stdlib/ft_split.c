/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisserst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:53:49 by jisserst          #+#    #+#             */
/*   Updated: 2022/12/10 18:34:51 by jisserst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../includes/libft.h"

static size_t	calc_arr_elem(char const *s, char delim);
static size_t	get_next_str_len(char const *s, char delim);
static char		**free_arr(char **arr);

char	**ft_split(char const *s, char delim)
{
	int		cnt;
	char	**arr;
	int		i;
	size_t	str_len;

	if (!s)
		return (0);
	cnt = calc_arr_elem(s, delim);
	arr = (char **)malloc((cnt + 1) * sizeof(char *));
	if (!arr)
		return (0);
	i = -1;
	while (++i < cnt && *s)
	{
		while (*s == delim && *s)
			s++;
		str_len = get_next_str_len(s, delim);
		arr[i] = (char *)malloc(str_len * sizeof(char) + 1);
		if (!arr[i])
			return (free_arr(arr));
		ft_strlcpy(arr[i], s, str_len + 1);
		s += str_len + 1;
	}
	arr[i] = 0;
	return (arr);
}

static size_t	calc_arr_elem(char const *s, char delim)
{
	size_t	cnt;
	size_t	word_flag;

	cnt = 0;
	word_flag = 0;
	while (*s)
	{
		if (*s != delim && word_flag == 0)
		{
			word_flag = 1;
			cnt++;
		}
		else if (*s == delim)
			word_flag = 0;
		s++;
	}
	return (cnt);
}

static size_t	get_next_str_len(char const *s, char delim)
{
	size_t	pos;

	pos = 0;
	while (s[pos] != delim && s[pos] != '\0')
		pos++;
	return (pos);
}

static char	**free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}
