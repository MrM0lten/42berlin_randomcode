
#include <unistd.h>
#include <stdlib.h>
#include "../Master-libft/includes/libft.h"
#include "../Master-libft/includes/ft_printf.h"
#include "../Master-libft/includes/array_utils.h"

int main()
{
	char *test ="wow this is the best day of my life!";
	char **arr;
	int lol[] = {5,3,2,1,15};
	int len = 5;
	int i = 0;
	arr = ft_split(test,' ');

	while(arr[i])
	{
		ft_printf("%s\n",arr[i]);
		free(arr[i]);
		i++;
	}
	free(arr);

	ft_printf("biggest elem = %i\n",lol[biggest_arr_elem(lol,len)]);
	ft_printf("elem pos of 1 = %i\n",arr_elem_pos(lol,len, 1));
	ft_printf("next bigest of 2 = %i\n",nextbiggest(lol,len, 2));
	ft_printf("array sorted? = %i\n",is_arr_sorted(lol,len));
	print_array(lol,len);
	return (0);
}
