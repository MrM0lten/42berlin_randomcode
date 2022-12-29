/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisserst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:45:48 by jisserst          #+#    #+#             */
/*   Updated: 2022/12/27 13:46:36 by jisserst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int	main()
{
	char	*str;
	int		fd;

	fd = open("./test.txt",O_RDONLY);
	//fd = 0;
	str = get_next_line(fd);
	while(str)
	{
		printf("%s",str);
		free(str);
		str = get_next_line(fd);
	}
	

	close(fd);
	return (0);
}
