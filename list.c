#include "push_swap.h"

t_stack *new_node(int value)
{
	t_stack	*new;
	
	new = malloc(sizeof(t_stack));
	if(!new)
		return(NULL);
	new->value = value;
	new->next = NULL;
       	return(new);
}	

void add_back(t_stack **stack,t_stack *new)
{
	t_stack *tmp;
	
	if(!stack ||!new)
		return;
	if(!*stack)
	{
		*stack = new;
		return;
	}
	tmp = *stack;
	while(tmp->next)
		tmp =tmp->next;
	tmp->next  = new;
}
