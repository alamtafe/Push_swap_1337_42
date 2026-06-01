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
	write(1,"a\n",2);
	print(a);
	write(1,"b\n",2);
	sa(&a);
	print(a);
	sb(&b);
	print(b);
	ss(&a,&b);
	print(a);
	print(b);
	pa(&b,&a);
	print(a);
	pb(&a,&b);
	print(b);
	ra(&a);
	print(a);
	rb(&b);
	print(b);
	rr(&a,&b);
	print(a);
	print(b);
	rra(&a);
	print(a);
	rrb(&b);
	print(b);
	rrr(&a,&b);
	print(a);
	print(b);
}

