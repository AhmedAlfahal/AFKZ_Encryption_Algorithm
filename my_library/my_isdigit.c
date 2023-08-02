#include "my_lib.h"

int	my_isbinary(int s)
{
	if (s == '0' || s == '1')
		return (1);
	else
		return (0);
}
