#include "push_swap.h"

void sort_two(t_stack **stack)
{
	int first;
	int second;
	if(!stack || !*stack || !(*stack)->next)
		return;
	first = (*stack)->value;
	second = (*stack)->next->value;
	if (first > second)
		sa(stack);
	return;
}
void sort_three(t_stack **stack)
{
	int first;
	int second;
	int third;
	first = (*stack)->value;
	second = (*stack)->next->value;
	third = (*stack)->next->next->value;
	if( first >  second && first < third)//213
	{	
		sa(stack);
	}else if(first > second && first > third && second > third)//321
	{
		ra(stack);
		sa(stack);
	}else if(first > second && first > third && second < third)//312
	{
		ra(stack);
	}else if(first < second && first > third)//231
	{
		rra(stack);
	}else if(first < second && first < third && second > third)//132
	{	
		sa(stack);
		ra(stack);
	}
}
void sort_five(t_stack **stack)
{
	t_stack *b;
	b = NULL;
	while( size_stack(*stack) > 3)
	{
		move_min_to_top(stack);
		pb(stack,&b);
	}
	sort_three(stack);
	while(b)
		pa(&b,stack);
}
