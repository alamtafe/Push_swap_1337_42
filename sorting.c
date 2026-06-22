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
void radix_sort(t_stack **stack)
{
	t_stack *b;
	int bits;
	int i;
	int size;
	int j;
	add_ranks(*stack);
	b = NULL;
	bits = max_bits(*stack);
	i = 0;
	while(i < bits)
	{
		size = size_stack(*stack);
		j = 0;
	      	while(j < size)
		{
			if((((*stack)->index >> i ) & 1) == 0)	
				pb(stack,&b);
			else
				ra(stack);
			j++;
		}
		while(b)
			pa(&b,stack);
		i++;
	}
		
}
void sort_stack(t_stack **stack)
{
	int size;
	size = size_stack(*stack);
	if(is_sorted(*stack))
			return;
	else if (size == 2)
		sort_two(stack);
	else if (size == 3)
		sort_three(stack);
	else if (size == 5)
		sort_five(stack);
	else if (size > 5)
		radix_sort(stack);
}
