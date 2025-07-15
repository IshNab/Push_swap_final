
#include "push_swap.h"

void	reverse_rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (stack->size < 2)
		return ;
	first = stack->head;
	last = first;
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	stack->head = last;
}

void	rra(t_stack *stack_a, int print)
{
	reverse_rotate(stack_a);
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_stack *stack_b, int print)
{
	reverse_rotate(stack_b);
	if (print)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack_a, t_stack *stack_b, int print)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	if (print)
		write(1, "rrr\n", 4);
}