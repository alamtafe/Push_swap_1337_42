#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

typedef struct s_stack
{
	int		value;
	struct s_stack 	*next;

}t_stack;

t_stack *new_node(int value);
void add_back(t_stack **stack,t_stack *new);
long ft_atol(char *s);
void free_stack(t_stack *stack);
t_stack *parsing(int argc,char **argv);
void sa(t_stack **stack);
void push(t_stack **src,t_stack **dest);
void ra(t_stack **stack);
void rra(t_stack **stack);
#endif
