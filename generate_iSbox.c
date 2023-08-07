#include "DES.h"
#include "my_library/my_lib.h"

void	creating_inverse(t_sbox *s)
{
	for (int i = 0; s->iS_box[i]; i++)
		s->iS_box[i] = my_strdup("1234");
	
}