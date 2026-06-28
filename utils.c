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
	int min;
	min = a->index;
	while(a)
	{
		if(min > a->index) 
			min = a->index;
		a = a->next;
	}
	return(min);
}
int find_max(t_stack *a)
{
	int max;
	max = a->index;
	while(a)
	{
		if(max < a->index)
			max = a->index;
		a = a->next;
	}
	return(max);
}
int find_position(t_stack *a,int min)
{
	t_stack *tmp;
	tmp = a;
	int i;
	i = 0;
	while(tmp && min != tmp->index)
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
void	move_node_to_top_a(t_stack **a,int n, t_bench *bench)
{
	int pos;
	int size;
	pos = find_position(*a,n);
	size = size_stack(*a);
	if(pos > size / 2)
	{
		while((*a)->index != n)
			rra(a,bench);
	}else{
		while((*a)->index != n)
			ra(a,bench);
	}
}
void	move_node_to_top_b(t_stack **b,int n, t_bench *bench)
{
	int pos;
	int size;
	pos = find_position(*b,n);
	size = size_stack(*b);
	if(pos > size / 2)
	{
		while((*b)->index != n)
			rrb(b,bench);
	}else{
		while((*b)->index != n)
			rb(b,bench);
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
int  strategy(char *str,t_stack **stack,t_bench *bench)
{
	if (ft_strcmp(str,"--simple"))
	{
		bench->disorder = compute_disorder(*stack);
		bench->strategy = "simple";
		bench->complexity = "O(n²)";
		simple_sort(stack,bench);
		return(1);
	}else if(ft_strcmp(str,"--medium"))
	{
		bench->disorder = compute_disorder(*stack);
		bench->strategy = "Medium";
		bench->complexity = "O(n√n)";
		medium_sort(stack,bench);
		return(1);
	}else if (ft_strcmp(str,"--complex"))
	{
		bench->disorder = compute_disorder(*stack);
		bench->strategy = "Complex";
		bench->complexity = "O(n log n)";
		radix_sort(stack,bench);
		return(1);
	}else if (ft_strcmp(str,"--adaptive"))
	{
		sort_stack(stack,bench);
		return(1);	
	}else if (ft_strcmp(str,"--bench"))
	{
		return(0);
	}else
	{
		write(1,"Error\n",6);
		return(1);	
	}
}
int bench_mark(char *str)
{
	return(ft_strcmp(str,"--bench"));
}
int ft_strcmp(char *s1 , char *s2)
{
	int i;
	i = 0;
	while(s1[i] && s2[i])
	{
		if(s1[i] != s2[i])
			return(0);
		i++;
	}
	if (s1[i] == '\0' && s2[i] == '\0')
		return(1);
	return(0);
}
int has_chunk(t_stack *stack, int start, int end)
{
	while(stack)
	{
		if(stack->index >= start && stack->index <= end)
			return(1);
		stack = stack->next;
	}
	return(0);
}
int chunk_size(int size)
{
	int n;
	n = 1;
	while(n * n <= size)
	{
		n++;
	}
	return(n - 1);
}
int parsing_strategy(char *argv)
{

	if (argv[0] == '-' && argv[1]== '-')
		return(1);
	return(0);
}
void ft_putstr_fd(char *s,int fd)
{
	int i;
	i = 0;
	if(!s)
		return;
	while(s[i])
	{
		write(fd,&s[i],1);
		i++;
	}
}
void ft_putnbr_fd(int nb , int fd)
{
	char c;
	if (nb  == -2147483648)
	{
		write(fd,"-2147483648",11);
		return;
	}
	if (nb < 0)
	{
		write(fd,"-",1);
		nb = -nb;
	}
	if(nb >= 10)
		ft_putnbr_fd(nb / 10 ,fd);
	c = (nb % 10) + '0';
	write(fd,&c,1);
}
void ft_double_fd(double nb,int fd)
{
	int intiger;
	int dicimal;
	intiger = (int)nb;
	dicimal =(int)((nb - intiger) * 100 + 0.5);
	if(dicimal == 100)
	{
		intiger++;
		dicimal = 0;
	}
	ft_putnbr_fd(intiger,fd);
	write(2,".",1);
	if(dicimal < 10)
		write(2,"0",1);
	ft_putnbr_fd(dicimal,fd);
}
		
