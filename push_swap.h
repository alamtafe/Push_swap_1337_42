#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

typedef struct s_stack
{
	int		value;
	int		index;
	struct s_stack 	*next;

}t_stack;

t_stack *new_node(int value);
void add_back(t_stack **stack,t_stack *new);
long ft_atol(char *s);
void free_stack(t_stack *stack);
t_stack *parsing(int argc,char **argv);
void swap(t_stack **stack);
void push(t_stack **src,t_stack **dest);
void rotate(t_stack **stack);
void reverse_rotate(t_stack **stack);
void rrr(t_stack **a,t_stack **b);
void rrb(t_stack **b);
void rrb(t_stack **b);
void rra(t_stack **a);
void rr(t_stack **a,t_stack **b);
void rb(t_stack **b);
void ra(t_stack **a);
void pa(t_stack **b,t_stack **a);
void pb(t_stack **a,t_stack **b);
void ss(t_stack **a,t_stack **b);
void sb(t_stack **b);
void sa(t_stack **a);
void sort_two(t_stack **stack);
void sort_three(t_stack **stack);
void sort_five(t_stack **stack);
int is_sorted(t_stack *stack);
int find_min(t_stack *a);
int find_position(t_stack *a,int min);
int size_stack(t_stack *a);
void print(t_stack *a);
void move_min_to_top(t_stack **a);
void add_ranks(t_stack *stack);
int max_bits(t_stack *stack);
void radix_sort(t_stack **stack);
void sort_stack(t_stack **stack);
#endif
