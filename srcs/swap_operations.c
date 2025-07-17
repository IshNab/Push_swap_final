#include "push_swap.h"

static void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (stack->size < 2)
		return ;
	first = stack->head;
	second = first->next;
	if (second->next)
		second->next->prev = first;
	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	stack->head = second;
}

void	sa(t_stack *stack_a, int print)
{
	swap(stack_a);
	if (print)
		write(1, "sa\n", 3);
}

void	sb(t_stack *stack_b, int print)
{
	swap(stack_b);
	if (print)
		write(1, "sb\n", 3);
}

void	ss(t_stack *stack_a, t_stack *stack_b, int print)
{
	swap(stack_a);
	swap(stack_b);
	if (print)
		write(1, "ss\n", 3);
}