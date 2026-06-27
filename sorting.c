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
		move_node_to_top_a(stack,find_min(*stack));
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
void simple_sort(t_stack **stack)
{
    t_stack *b;

    b = NULL;
    while (*stack)
    {
        move_node_to_top_a(stack,find_min(*stack)); 
        pb(stack, &b);   
    }
    while (b)
    {
        pa(&b, stack);    
    }
}
void medium_sort(t_stack **stack)
{
	t_stack *b;
	int size;
	int size_chunk;
	int end;
	int start;
	b = NULL;
	size = size_stack(*stack);
	size_chunk = chunk_size(size);
	start = 0;
	end = size_chunk - 1;
	while(*stack)
	{
		while(has_chunk(*stack,start,end))
		{
			if((*stack)->index >= start && (*stack)->index <= end)
				pb(stack,&b);
			else
				ra(stack);

		}
		start += size_chunk;
		end += size_chunk;
		if(end > size - 1)
			end = size - 1;
	}
	while(b)
	{
		move_node_to_top_b(&b,find_max(b));
		pa(&b,stack);
	}
}
void sort_stack(t_stack **stack)
{
	if (compute_disorder(*stack) < 0.2)
	{
		simple_sort(stack);

	}else if (compute_disorder(*stack) >= 0.2 && compute_disorder(*stack) < 0.5)
	{
		medium_sort(stack);
	}else if (compute_disorder(*stack) >= 0.5)
	{
		radix_sort(stack);
	}
}
