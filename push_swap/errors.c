#include "push_swap.h"

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
				ft_printf("Error\n");
				return (0);
			}
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
		{
			ft_printf("%c\n",str[i]);
			ft_printf("Error\n");
			return (0);
		}
		i++;
	}
	return (1);
}