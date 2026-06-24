#include "push_swap.h"
//sorting.c
int is_sorted(t_stack *stack)
{
	int count;
	count = 0;
	while(stack->next)
	{
		count = stack->value;
		if(count > stack->next->value)
		       return(0);
		stack = stack->next;
	}
	return(1);	
}
double compute_disorder(t_stack *stack)
{
	t_stack *tmp;
	t_stack *t;
	double mistakes;
	double total;
	tmp = stack;
	mistakes = 0;
	total = 0;
	while(tmp)
	{	
		t = tmp->next;
		while(t)
		{	total++;
			if(tmp->value > t->value)
				mistakes++;
			t = t->next;
		}
		tmp = tmp->next;
	}
	if (total == 0)
		return(0);
	return (mistakes / total);
}

int find_min(t_stack *a)
{
	t_stack *tmp;
	int min;
	tmp = a;
	min = tmp->value;//5
	while(tmp)// 5 2 3 4 1 //2 3 4 1 // 3 4 1 // 4 1
	{
		if(min > tmp->value) //5 > 2 //2 < 3 // 2 < 4 // 2 <4
			min = tmp->value;//=2
		tmp = tmp->next;//2 3 4 1 // 3 4 1 //4 1 //1
	}
	return(min);
}
int find_position(t_stack *a,int min)
{
	t_stack *tmp;
	tmp = a;
	int i;
	i = 0;
	while(tmp && min != tmp->value)
	{
		i++;
		tmp = tmp->next;
	}
	return(i);
}
int size_stack(t_stack *a)
{
	t_stack *tmp;
	int i;
	tmp = a;
	i = 0;
	while(tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return(i);
}
void	move_min_to_top(t_stack **a)
{
	int min;
	int pos;
	int size;
	min = find_min(*a);
	pos = find_position(*a,min);
	size = size_stack(*a);
	if(pos > size / 2)
	{
		while((*a)->value != min)
			rra(a);
	}else{
		while((*a)->value != min)
			ra(a);
	}
}
void add_ranks(t_stack *stack)
{
	t_stack *tmp;
	t_stack *t;
	int i;
	if (!stack)
		return;
	tmp = stack;
	while(tmp)
	{ 
		i = 0;
		t = stack;
		while(t) 
		{ 
			if(tmp->value > t->value) 
				i++;
			t = t->next;
		}
		tmp->index = i;
		tmp = tmp->next;
	}
	
}	
int max_bits(t_stack *stack)
{
	t_stack *tmp;
	int max;
	int bit;
	tmp = stack;
	max = tmp->value;
	while(tmp)
	{
		if(max < tmp->index)
			max = tmp->index;
		tmp = tmp->next;
	}
	bit = 0;
	while(max > 0)
	{
		bit++;
		max = max / 2;
	}
	return(bit);
}
//parsing.c
long ft_atol(char *s)
{
	long res;
	long sign;
	int i;
	res = 0;
	i = 0;
	sign = 1;
	while(s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	if(s[i]	== '-' || s[i] == '+')
	{
		if(s[i] == '-')
			sign = -1;
		i++;
	}
	while(s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + (s[i] - '0');
	       	i++;
	}
	return(res * sign);
}

void free_stack(t_stack *stack)
{
	t_stack *tmp;
	while(stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}
