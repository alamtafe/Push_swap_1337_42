#include "push_swap.h"
#include <stdio.h>

void print(t_stack *stack)
{
	while(stack)
	{
		printf("%d\n",stack->value);
			stack = stack->next;
	}
	return;
}

int main(int argc,char **argv)
{
	t_stack *a;
	a = parsing(argc,argv);
	if(a == NULL)
		printf("error\n");
	print(a);
}

