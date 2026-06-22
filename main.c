#include "push_swap.h"
#include <stdio.h>

int main(int argc,char **argv)
{
	t_stack *a;
	if (argc == 1)
		return(0);
	a = parsing(argc,argv);
	if(a == NULL)
	{
		write(1,"Erorr\n",6);
		return(1);
	}
	sort_stack(&a);
	free_stack(a);
	return(0);	
}

