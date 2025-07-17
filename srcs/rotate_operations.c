#include "push_swap.h"

static void	rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (stack->size < 2)
		return ;
	first = stack->head;
	last = first;
	while (last->next)
		last = last->next;
	stack->head = first->next;
	stack->head->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
}

void	ra(t_stack *stack_a, int print)
{
	rotate(stack_a);
	if (print)
		write(1, "ra\n", 3);
}

void	rb(t_stack *stack_b, int print)
{
	rotate(stack_b);
	if (print)
		write(1, "rb\n", 3);
}

void	rr(t_stack *stack_a, t_stack *stack_b, int print)
{
	rotate(stack_a);
	rotate(stack_b);
	if (print)
		write(1, "rr\n", 3);
}