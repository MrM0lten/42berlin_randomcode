#include "push_swap.h"

int err_arr_is_unique(int *arr,int len)
{
	int i;
	int j;

	if(len == 1)
		return (1);
	i = 0;
	while (i < len)
	{
		j = i + 1;
		while(j < len)
		{
			if(arr[i] == arr[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
int err_arr_is_all_num(char *str)
{
	int i;
	char c;

	i = 0;
	while(str[i])
	{
		c = str[i];
		if(str[i] != ' ' && str[i] != '-' && str[i] != '+' && !ft_isdigit(c))
			return (0);
		c = str[i + 1];
		if(str[i] == '+' || str[i] == '-')
		{
			if(str[i + 1] == '-' || str[i + 1] == '+' || !ft_isdigit(c))
				return (0);
		}
		i++;
	}
	return (1);
}

void write_error()
{
	write(STDERR_FILENO, "Error\n", 6);
}