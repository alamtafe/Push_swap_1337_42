#include "push_swap.h"
#include <stdio.h>

int main(int argc,char **argv)
{
	t_stack *a;
	a = parsing(argc,argv);
	if(a == NULL)
		printf("error\n");
	//if(!is_sorted(a))
	//{
	//	sort_three(&a);
	//	print(a);
	//}else
	//{
	//	print(a);
	//}
	int min = find_min(a);
	printf("%d\n",min);
	int position =  find_position(a,min);
	printf("%d\n",position);
	int size = size_stack(a);
	printf("%d\n",size);
	move_min_to_top(&a);
	sort_five(&a);
	print(a);
	free_stack(a);	
}

