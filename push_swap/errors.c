#include "push_swap.h"

void error_handler(char *message)
{
	ft_printf("Programm Aborted, Reason: %s\n",message);
}

int err_arr_is_unique(int *arr,int len)
{
	int i;
	int j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while(j < len)
		{
			if(arr[i] == arr[j])
			{
				error_handler("Array contains identical elements");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}