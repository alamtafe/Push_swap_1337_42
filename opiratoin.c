#include "push_swap.h"

void swap(t_stack **stack)
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
void rotate(t_stack **stack)
{
	t_stack *first;
	t_stack *last;
	if(!stack ||!*stack || !(*stack)->next)
		return;
	last = *stack;
	while(last->next)
		last = last->next;
	first = *stack;
	*stack = first->next;
	last->next = first;
	first->next = NULL;
}
void reverse_rotate(t_stack **stack)
{
	t_stack *before_last;
	t_stack *last;
	if(!stack || !*stack ||!(*stack)->next)
		return;
	before_last = NULL;
	last = *stack;
	while(last->next)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL;
	last->next = *stack;
	*stack  = last;
}
void sa(t_stack **a)
{
	swap(a);
	write(1,"sa\n",3);
}
void sb(t_stack **b)
{
	swap(b);
	write(1,"sb\n",3);
}
void ss(t_stack **a,t_stack **b)
{
	swap(a);
	swap(b);
	write(1,"ss\n",3);
}
void pb(t_stack **a,t_stack **b)
{
	push(a,b);
	write(1,"pb\n",3);
}
void pa(t_stack **b,t_stack **a)
{
	push(b,a);
	write(1,"pa\n",3);
}
void ra(t_stack **a)
{
	rotate(a);
	write(1,"ra\n",3);
}
void rb(t_stack **b)
{
	rotate(b);
	write(1,"rb\n",3);
}
void rr(t_stack **a,t_stack **b)
{
	rotate(a);
	rotate(b);
	write(1,"rr\n",3);
}
void rra(t_stack **a)
{
	reverse_rotate(a);
	write(1,"rra\n",4);
}
void rrb(t_stack **b)
{
	reverse_rotate(b);
	write(1,"rrb\n",4);
}
void rrr(t_stack **a,t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1,"rrr\n",4);
}
