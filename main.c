#include "push_swap.h"
#include <stdio.h>

int main(int argc,char **argv)
{
	t_stack *a;
	if (argc == 1)
		return(0);
	int i;
	a = parsing(argc,argv);
	if(a == NULL)
	{
		write(1,"Erorr\n",6);
		return(1);
	}
	//printf("%.2f\n",compute_disorder(a));
	i = argc;
	int v;
	v = 0;
	while (i > 0)
	{
		i--;
		if(parsing_strategy(argv[i]))
		{      
			strategy(argv[i],&a);
			v = 1;
		}
	}
	if (v == 0)	
		sort_stack(&a);
	free_stack(a);
	return(0);	
}

