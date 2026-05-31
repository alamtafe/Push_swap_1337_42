#include "push_swap.h"

void sa(t_stack **stack)
{
	t_stack *first;
	t_stack *second;
	t_stack *third;
	if (!stack || !*stack || !(*stack)->next)
		return;
	first = *stack;
	second = first->next;
	third = second->next;
	first->next = third;
	second->next = first;
	*stack = second;
	write(1,"sa\n",3);
}
void push(t_stack **src,t_stack **dest)
{
	t_stack *first;
	if(!src || !dest ||!*src)
		return;
	first = *src;
	*src = first->next;
	first->next = *dest;
	*dest = first;
}
void ra(t_stack **stack)
{
	t_stack *first;
	t_stack *last;
	t_stack *tmp;
	if(!stack ||!*stack || !(*stack)->next)
		return;
	tmp = *stack;
	while(tmp)
	{
		if(tmp->next)
			last = tmp->next;
		tmp = tmp->next;
	}
	first = *stack;
	*stack = first->next;
	last->next = first;
	first->next = NULL;
	write(1,"ra\n",3);
}
void rra(t_stack **stack)
{
	t_stack *before_last;
	t_stack *last;
	t_stack *tmp;
	t_stack *p;
	
	if(!stack || !*stack ||!(*stack)->next)
		return;
	tmp = *stack;
	before_last = NULL;
	while(tmp->next)
	{	
		p = tmp->next;
		if(!p->next)
		{
			before_last = tmp;
			break;
		}
		tmp = tmp->next;
	}
	last = *stack;
	while(last->next)
		last = last->next;
	before_last->next = NULL;
	last->next = *stack;
	*stack  = last;
	write(1,"rra\n",4);
}
