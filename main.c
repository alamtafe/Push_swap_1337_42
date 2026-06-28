#include "push_swap.h"

int main(int argc,char **argv)
{
	t_stack *a;
	t_bench bench;
	int v;
	int i;
	if (argc == 1)
		return(0);
	a = parsing(argc,argv);
	if(a == NULL)
	{
		write(1,"Erorr\n",6);
		return(1);
	}
	add_ranks(a);
	bench.bench = 0;
	bench.disorder = 0;
	bench.strategy = NULL;
	bench.complexity = NULL;
	bench.ops = 0;
	bench.sa = 0;
	bench.sb = 0;
	bench.pa = 0;
	bench.ss = 0;
	bench.pb = 0;
	bench.ra = 0;
	bench.rb = 0;
	bench.rr = 0;
	bench.rra = 0;
	bench.rrb = 0;
	bench.rrr = 0;
	i = argc - 1;
	v = 0;
	while (i > 0)
	{
		if(parsing_strategy(argv[i]))
		{
			if (strategy(argv[i],&a,&bench))
				v = 1;
		}
		i--;
	}
	i = argc - 1;
	while (i > 0)
	{
		if(bench_mark(argv[i]))
		{
			bench.bench = 1;
		}
		i--;
	}	
	if (v == 0)	
		sort_stack(&a,&bench);
	if(bench.bench)
	{
		print_bench(&bench);
		
	}
	free_stack(a);
	return(0);	
}

