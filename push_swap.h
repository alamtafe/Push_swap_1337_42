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

typedef struct s_bench
{
	int bench;
	double	disorder;
	char *strategy;
	char *complexity;
	int ops;
	int sa;
	int sb;
	int ss;
	int pa;
	int pb;
	int ra;
	int rb;
	int rr;
	int rra;
	int rrb;
	int rrr;
}t_bench;

t_stack *new_node(int value);
void add_back(t_stack **stack,t_stack *new);
long ft_atol(char *s);
void free_stack(t_stack *stack);
t_stack *parsing(int argc,char **argv);
void swap(t_stack **stack);
void push(t_stack **src,t_stack **dest);
void rotate(t_stack **stack);
void reverse_rotate(t_stack **stack);
void rrr(t_stack **a,t_stack **b, t_bench *bench);
void rrb(t_stack **b, t_bench *bench);
void rrb(t_stack **b, t_bench *bench);
void rra(t_stack **a, t_bench *bench);
void rr(t_stack **a,t_stack **b, t_bench *bench);
void rb(t_stack **b, t_bench *bench);
void ra(t_stack **a, t_bench *bench);
void pa(t_stack **b,t_stack **a, t_bench *bench);
void pb(t_stack **a,t_stack **b, t_bench *bench);
void ss(t_stack **a,t_stack **b, t_bench *bench);
void sb(t_stack **b, t_bench *bench);
void sa(t_stack **a, t_bench *bench);
void sort_two(t_stack **stack,t_bench *bench);
void sort_three(t_stack **stack,t_bench *bench);
void sort_five(t_stack **stack,t_bench *bench);
int is_sorted(t_stack *stack);
int find_min(t_stack *a);
int find_position(t_stack *a,int min);
int size_stack(t_stack *a);
void print(t_stack *a);
void move_node_to_top_a(t_stack **a,int n, t_bench *bench);
void move_node_to_top_b(t_stack **b, int n, t_bench *bench);
void add_ranks(t_stack *stack);
int max_bits(t_stack *stack);
void radix_sort(t_stack **stack, t_bench *bench);
void sort_stack(t_stack **stack, t_bench *bench);
double compute_disorder(t_stack *stack);
void simple_sort(t_stack **stack, t_bench *bench);
int parsing_strategy(char *argv);
int  strategy(char *str,t_stack **stack,t_bench *bench);
int ft_strcmp(char *s1 , char *s2); 
int has_chunk(t_stack *stack, int start, int end);
int chunk_size(int size);
int find_max(t_stack *stack);
void medium_sort(t_stack **stack,t_bench *bench);
int bench_mark(char *str);
void	print_bench(t_bench *bench);
void ft_putstr_fd(char *s,int fd);
void ft_putnbr_fd(int nb,int fd);
void ft_double_fd(double nb, int fd);
#endif
