#include "push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b, int print)
{
	t_node	*top_b;

	if (stack_b->size == 0)
		return ;
	top_b = pop_node_top(stack_b);
	add_node_top(stack_a, top_b);
	if (print)
		write(1, "pa\n", 3);
}

void	pb(t_stack *stack_a, t_stack *stack_b, int print)
{
	t_node	*top_a;

	if (stack_a->size == 0)
		return ;
	top_a = pop_node_top(stack_a);
	add_node_top(stack_b, top_a);
	if (print)
		write(1, "pb\n", 3);
}