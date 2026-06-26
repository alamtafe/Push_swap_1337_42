#include "push_swap.h"

		
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
		if (parsing_strategy(argv[i]))
    		{
        		i++;
			continue;
    		}	
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

		

