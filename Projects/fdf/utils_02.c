#include "fdf.h"

void	free_string_arr(char **arr)
{
	int	i;

	if (arr)
	{
		i = 0;
		while (arr[i])
		{
			free(arr[i]);
			arr[i] = 0;
			i++;
		}
		free(arr);
	}
}
