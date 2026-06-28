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
void sa(t_stack **a,t_bench *bench)
{
	swap(a);
	write(1,"sa\n",3);
	bench->sa++;
	bench->ops++;
}
void sb(t_stack **b, t_bench *bench)
{
	swap(b);
	write(1,"sb\n",3);
	bench->sb++;
	bench->ops++;
}
void ss(t_stack **a,t_stack **b, t_bench *bench)
{
	swap(a);
	swap(b);
	write(1,"ss\n",3);
	bench->ss++;
	bench->ops++;
}
void pb(t_stack **a,t_stack **b, t_bench *bench)
{
	push(a,b);
	write(1,"pb\n",3);
	bench->pb++;
	bench->ops++;
}
void pa(t_stack **b,t_stack **a, t_bench *bench)
{
	push(b,a);
	write(1,"pa\n",3);
	bench->pa++;
	bench->ops++;
}
void ra(t_stack **a, t_bench *bench)
{
	rotate(a);
	write(1,"ra\n",3);
	bench->ra++;
	bench->ops++;
}
void rb(t_stack **b, t_bench *bench)
{
	rotate(b);
	write(1,"rb\n",3);
	bench->rb++;
	bench->ops++;
}
void rr(t_stack **a,t_stack **b, t_bench *bench)
{
	rotate(a);
	rotate(b);
	write(1,"rr\n",3);
	bench->rr++;
	bench->ops++;
}
void rra(t_stack **a, t_bench *bench)
{
	reverse_rotate(a);
	write(1,"rra\n",4);
	bench->rra++;
	bench->ops++;
}
void rrb(t_stack **b, t_bench *bench)
{
	reverse_rotate(b);
	write(1,"rrb\n",4);
	bench->rrb++;
	bench->ops++;
}
void rrr(t_stack **a,t_stack **b, t_bench *bench)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1,"rrr\n",4);
	bench->rrr++;
	bench->ops++;
}
