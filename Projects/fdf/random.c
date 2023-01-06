#include "fdf.h"

void *ft_realloc(void *old, size_t old_size, size_t new_size)
{
	void *new;
	size_t copy_size;

	new = malloc(new_size);
	copy_size = old_size;
	if(new_size < old_size)
		copy_size = new_size;
	ft_memcpy(new,old,copy_size);
	free(old);
	return (new);
}

size_t	ft_poschr(const char *str, int c)
{
	size_t i;

	i = 0;
	while (str[i] != '\0' && str[i] != (char)c)
		i++;
	if (str[i] != '\0' || (char)c == '\0')
		return (i);
	else
		return (0);
}

int ft_hextoi(char *str)
{
	int i;
	int rtn;
	int byte;

	i = 0;
	rtn = 0;
	if(str[i] == '0' && str[i + 1] == 'x')
		i += 2;
	while(str[i]) //could have also done it with rtn = rtn * 16 -(15 -character)
	{
		if(str[i] >= 'a' && str[i] <= 'f')
			byte = str[i] - 'a' + 10;
		else if(str[i] >= 'A' && str[i] <= 'F')
			byte = str[i] - 'A' + 10;
		else
			byte = str[i] - '0';
		rtn = (rtn << 4) | (byte & 0xF);
		i++;
	}
	return (rtn);
}

int ft_abs(int x)
{
	if(x < 0)
		return (-x);
	return (x);
}

int count_elems(char **str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}