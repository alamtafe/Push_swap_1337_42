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
	t_stack *b;
	a = parsing(argc,argv);
	b = parsing(argc,argv);
	if(a == NULL)
		printf("error\n");
	print(a);
	sa(&a);
	print(a);
	write(1,"pb\n",3);
	push(&a,&b);
	print(a);
	print(b);
	write(1,"pa\n",3);
	push(&b,&a);
	print(a);
	print(b);
	ra(&a);
	print(a);
	rra(&a);
	print(a);
}

