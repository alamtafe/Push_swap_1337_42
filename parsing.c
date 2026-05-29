#include "push_swap.h"

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
		
t_stack *parsing(int argc,char **argv)
{
	int i;
	int k;
	long nb;
	t_stack *a;
	t_stack *tmp;
	t_stack *node;
	i = 1;
	a = NULL;
	if(argc == 1)
		return(NULL);
	while(argv[i])
	{
		k = 0;
		while(argv[i][k])
		{
			if(!(k == 0) && (argv[i][k] == '-' || argv[i][k] == '+'))
			{
				free_stack(a);
				return(NULL);
			}
			if(argv[i][k] == '-' || argv[i][k] == '+')
			{
				if (argv[i][k + 1] == '\0') 
				{
					free_stack(a);
					return(NULL);
				}
				k++;
			}
			if(!(argv[i][k] >= '0' && argv[i][k] <= '9'))
			{
				free_stack(a);
				return(NULL);
			}
			k++;
		}
		nb = ft_atol(argv[i]);
		if(nb > INT_MAX || nb < INT_MIN)
		{
			free_stack(a);
			return(NULL);
		}
		tmp = a;
		while(tmp)
		{
			if(tmp->value == (int)nb)
			{
				free_stack(a);
				return(NULL);
			}
			tmp = tmp->next;
		}
		node = new_node((int)nb);
		if(node == NULL)
		{
			free_stack(a);
			return(NULL);
		}
		add_back(&a,node);	
		i++;
	}
	return(a);
}

		

