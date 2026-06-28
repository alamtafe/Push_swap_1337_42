#include "push_swap.h"

void sort_two(t_stack **stack,t_bench *bench)
{
	int first;
	int second;
	if(!stack || !*stack || !(*stack)->next)
		return;
	first = (*stack)->value;
	second = (*stack)->next->value;
	if (first > second)
		sa(stack,bench);
	return;
}
void sort_three(t_stack **stack,t_bench *bench)
{
	int first;
	int second;
	int third;
	first = (*stack)->value;
	second = (*stack)->next->value;
	third = (*stack)->next->next->value;
	if( first >  second && first < third)//213
	{	
		sa(stack,bench);
	}else if(first > second && first > third && second > third)//321
	{
		ra(stack,bench);
		sa(stack,bench);
	}else if(first > second && first > third && second < third)//312
	{
		ra(stack,bench);
	}else if(first < second && first > third)//231
	{
		rra(stack,bench);
	}else if(first < second && first < third && second > third)//132
	{	
		sa(stack,bench);
		ra(stack,bench);
	}
}
void sort_five(t_stack **stack,t_bench *bench)
{
	t_stack *b;
	b = NULL;
	while( size_stack(*stack) > 3)
	{
		move_node_to_top_a(stack,find_min(*stack),bench);
		pb(stack,&b,bench);
	}
	sort_three(stack,bench);
	while(b)
		pa(&b,stack,bench);
}
void radix_sort(t_stack **stack, t_bench *bench)
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
				pb(stack,&b,bench);
			else
				ra(stack,bench);
			j++;
		}
		while(b)
			pa(&b,stack,bench);
		i++;
	}
		
}
void simple_sort(t_stack **stack, t_bench *bench)
{
    t_stack *b;

    b = NULL;
    while (*stack)
    {
        move_node_to_top_a(stack,find_min(*stack),bench); 
        pb(stack, &b,bench);   
    }
    while (b)
    {
        pa(&b, stack,bench);    
    }
}
void medium_sort(t_stack **stack, t_bench *bench)
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
				pb(stack,&b,bench);
			else
				ra(stack,bench);

		}
		start += size_chunk;
		end += size_chunk;
		if(end > size - 1)
			end = size - 1;
	}
	while(b)
	{
		move_node_to_top_b(&b,find_max(b),bench);
		pa(&b,stack,bench);
	}
}
void sort_stack(t_stack **stack,t_bench *bench)
{
	bench->strategy = "Adaptive";
	bench->disorder = compute_disorder(*stack);
	if (bench->disorder < 0.2)
	{
		bench->complexity = "O(n²)";
		simple_sort(stack,bench);

	}else if (bench->disorder >= 0.2 && bench->disorder < 0.5)
	{
		bench->complexity = "O(n√n)";
		medium_sort(stack,bench);
	}else if (bench->disorder >= 0.5)
	{
		bench->complexity = "O(n log n)";
		radix_sort(stack,bench);
	}
}
