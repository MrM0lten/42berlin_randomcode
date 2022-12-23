#include "push_swap.h"

size_t ft_abs(int i)
{
	if(i < 0)
		return(i * -1);
	return (i);
}

int largest_from_zero(int a, int b)
{
	if(a >= 0 && b >= 0)
	{
		if (a > b)
			return (a);
		else
			return (b);
	}
	else
	{
		if(a < b)
			return (a * -1);
		else
			return (b * -1);
	}
}