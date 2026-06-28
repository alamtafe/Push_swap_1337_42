#include "push_swap.h"

void	print_bench(t_bench *bench)
{ 
	write(2, "[bench] disorder: ", 18);
	ft_double_fd(bench->disorder * 100, 2);
	write(2, "%\n", 2);

	write(2, "[bench] strategy: ", 18);
	ft_putstr_fd(bench->strategy, 2);
	write(2, "\n", 1);

	write(2, "[bench] complexity: ", 20);
	ft_putstr_fd(bench->complexity, 2);
	write(2, "\n", 1);
	
	write(2,"[bench] total_ops : ",20);
	ft_putnbr_fd(bench->ops,2);
	write(2,"\n",1);
	
	write(2,"[bench] sa : ",13);
	ft_putnbr_fd(bench->sa,2);
	write(2," sb : ",6);
	ft_putnbr_fd(bench->sb,2);
	write(2," ss : ",6);
	ft_putnbr_fd(bench->ss,2);
	write(2," pa : ",6);
	ft_putnbr_fd(bench->pa,2);
	write(2," pb : ",6);
	ft_putnbr_fd(bench->pb,2);
	write(2,"\n",1);

	write(2,"[bench] ra : ",13);
	ft_putnbr_fd(bench->ra,2);
	write(2," rb : ",6);
	ft_putnbr_fd(bench->rb,2);
	write(2," rr : ",6);
	ft_putnbr_fd(bench->rr,2);
	write(2," rra : ",7);
	ft_putnbr_fd(bench->rra,2);
	write(2," rrb : ",7);
	ft_putnbr_fd(bench->rrb,2);
	write(2," rrr : ",7);
	ft_putnbr_fd(bench->rrr,2);
	write(2,"\n",1);		
    
}
