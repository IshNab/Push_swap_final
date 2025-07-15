#include "push_swap.h"

/* 交换栈顶的两个元素 */
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

/* sa操作：交换a栈顶两个元素 */
void	sa(t_stack *stack_a, int print)
{
	swap(stack_a);
	if (print)
		write(1, "sa\n", 3);
}

/* sb操作：交换b栈顶两个元素 */
void	sb(t_stack *stack_b, int print)
{
	swap(stack_b);
	if (print)
		write(1, "sb\n", 3);
}

/* ss操作：同时执行sa和sb */
void	ss(t_stack *stack_a, t_stack *stack_b, int print)
{
	swap(stack_a);
	swap(stack_b);
	if (print)
		write(1, "ss\n", 3);
}