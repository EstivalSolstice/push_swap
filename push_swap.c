#include "push_swap.h"

t_node	*new_node(int value, int index)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
	{
		ft_printf("Error\n");
		exit(0);
	}
	node->value = value;
	node->index = index;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	push(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return ;
	node->next = stack->top;
	if (stack->top)
		stack->top->prev = node;
	stack->top = node;
	stack->size++;
}

t_node	*pop(t_stack *stack)
{
	t_node	*node;

	if (!stack || !stack->top)
		return (NULL);
	node = stack->top;
	stack->top = node->next;
	if (stack->top)
		stack->top->prev = NULL;
	node->next = NULL;
	stack->size--;
	return (node);
}

void	rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	last = stack->top;
	while (last->next)
		last = last->next;
	stack->top = first->next;
	stack->top->prev = NULL;
	first->next = NULL;
	last->next = first;
	first->prev = last;
}

void	reverse_rotate(t_stack *stack)
{
	t_node	*last;
	t_node	*second_last;

	if (!stack || stack->size < 2)
		return ;
	last = stack->top;
	while (last->next)
		last = last->next;
	second_last = last->prev;
	second_last->next = NULL;
	last->prev = NULL;
	last->next = stack->top;
	stack->top->prev = last;
	stack->top = last;
}

void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	first->prev = second;
	second->prev = NULL;
	stack->top = second;
}

void	sa(t_push_swap *ps)
{
	swap(ps->a);
	ft_printf("sa\n");
	ps->move_count++;
}

void	sb(t_push_swap *ps)
{
	swap(ps->b);
	ft_printf("sb\n");
	ps->move_count++;
}

void	ss(t_push_swap *ps)
{
	swap(ps->a);
	swap(ps->b);
	ft_printf("ss\n");
	ps->move_count++;
}

void	pa(t_push_swap *ps)
{
	t_node	*node;

	node = pop(ps->b);
	if (node)
	{
		push(ps->a, node);
		ft_printf("pa\n");
		ps->move_count++;
	}
}

void	pb(t_push_swap *ps)
{
	t_node	*node;

	node = pop(ps->a);
	if (node)
	{
		push(ps->b, node);
		ft_printf("pb\n");
		ps->move_count++;
	}
}

void	ra(t_push_swap *ps)
{
	rotate(ps->a);
	ft_printf("ra\n");
	ps->move_count++;
}

void	rb(t_push_swap *ps)
{
	rotate(ps->b);
	ft_printf("rb\n");
	ps->move_count++;
}

void	rr(t_push_swap *ps)
{
	rotate(ps->a);
	rotate(ps->b);
	ft_printf("rr\n");
	ps->move_count++;
}

void	rra(t_push_swap *ps)
{
	reverse_rotate(ps->a);
	ft_printf("rra\n");
	ps->move_count++;
}

void	rrb(t_push_swap *ps)
{
	reverse_rotate(ps->b);
	ft_printf("rrb\n");
	ps->move_count++;
}

void	rrr(t_push_swap *ps)
{
	reverse_rotate(ps->a);
	reverse_rotate(ps->b);
	ft_printf("rrr\n");
	ps->move_count++;
}

int	find_target_position(t_stack *a, int b_index)
{
	t_node	*current;
	int		position;
	int		min_diff;
	int		target_position;
	int		diff;
	int		diff;

	current = a->top;
	position = 0;
	min_diff = INT_MAX;
	target_position = 0;
	while (current)
	{
		diff = current->index - b_index;
		if (diff > 0 && diff < min_diff)
		{
			min_diff = diff;
			target_position = position;
		}
		current = current->next;
		position++;
	}
	if (min_diff == INT_MAX)
	{
		current = a->top;
		min_diff = INT_MAX;
		position = 0;
		while (current)
		{
			diff = b_index - current->index;
			if (diff > 0 && diff < min_diff)
			{
				min_diff = diff;
				target_position = position + 1;
			}
			current = current->next;
			position++;
		}
	}
	return (target_position);
}

int	calculate_rotation_a(t_stack *a, int target_position)
{
	if (target_position <= a->size / 2)
	{
		return (target_position);
	}
	else
	{
		return ((a->size - target_position) * -1);
	}
}

int	calculate_rotation_b(t_stack *b, int b_position)
{
	if (b_position <= b->size / 2)
	{
		return (b_position);
	}
	else
	{
		return ((b->size - b_position) * -1);
	}
}

int	calculate_move_cost(t_stack *a, t_stack *b, int b_position)
{
	t_node	*b_node;
	int		i;
	int		target_position;
	int		rotation_a;
	int		rotation_b;
	int		cost;
	int		rotation_a_abs;
	int		rotation_b_abs;

	b_node = b->top;
	i = 0;
	while (i < b_position && b_node != NULL)
	{
		b_node = b_node->next;
		i++;
	}
	if (b_node == NULL)
	{
		return (INT_MAX);
	}
	target_position = find_target_position(a, b_node->index);
	rotation_a = calculate_rotation_a(a, target_position);
	rotation_b = calculate_rotation_b(b, b_position);
	cost = 0;
	if (rotation_a < 0)
		rotation_a_abs = -rotation_a;
	else
		rotation_a_abs = rotation_a;
	if (rotation_b < 0)
		rotation_b_abs = -rotation_b;
	else
		rotation_b_abs = rotation_b;
	if ((rotation_a >= 0 && rotation_b >= 0) || (rotation_a < 0
			&& rotation_b < 0))
	{
		if (rotation_a_abs > rotation_b_abs)
			cost = rotation_a_abs;
		else
			cost = rotation_b_abs;
	}
	else
	{
		cost = rotation_a_abs + rotation_b_abs;
	}
	cost += 1;
	return (cost);
}

void	perform_rotations(t_push_swap *ps, int rotation_a, int rotation_b)
{
	if (ps->a->size == 3 && !is_sorted(ps->a))
	{
		sort_three(ps->a, ps);
		return ;
	}
	if (rotation_a >= 0 && rotation_b >= 0)
	{
		while (rotation_a > 0 && rotation_b > 0)
		{
			rr(ps);
			rotation_a--;
			rotation_b--;
		}
		while (rotation_a > 0)
		{
			ra(ps);
			rotation_a--;
		}
		while (rotation_b > 0)
		{
			rb(ps);
			rotation_b--;
		}
	}
	else if (rotation_a < 0 && rotation_b < 0)
	{
		while (rotation_a < 0 && rotation_b < 0)
		{
			rrr(ps);
			rotation_a++;
			rotation_b++;
		}
		while (rotation_a < 0)
		{
			rra(ps);
			rotation_a++;
		}
		while (rotation_b < 0)
		{
			rrb(ps);
			rotation_b++;
		}
	}
	else
	{
		while (rotation_a > 0)
		{
			ra(ps);
			rotation_a--;
		}
		while (rotation_a < 0)
		{
			rra(ps);
			rotation_a++;
		}
		while (rotation_b > 0)
		{
			rb(ps);
			rotation_b--;
		}
		while (rotation_b < 0)
		{
			rrb(ps);
			rotation_b++;
		}
	}
}

int	is_empty(t_stack *stack)
{
	if (stack == NULL || stack->top == NULL)
	{
		return (1);
	}
	return (0);
}

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->top)
	{
		return (1);
	}
	current = stack->top;
	while (current && current->next)
	{
		if (current->index > current->next->index)
		{
			return (0);
		}
		current = current->next;
	}
	return (1);
}

void	sort_three(t_stack *a, t_push_swap *ps)
{
	int	first;
	int	second;
	int	third;

	first = a->top->index;
	second = a->top->next->index;
	third = a->top->next->next->index;
	if (first < second && second < third)
	{
		return ;
	}
	if (first > second && second < third && first < third)
	{
		sa(ps);
		return ;
	}
	if (first < second && second > third && first < third)
	{
		rra(ps);
		sa(ps);
		return ;
	}
	if (first < second && second > third && first > third)
	{
		sa(ps);
		rra(ps);
		return ;
	}
	if (first > second && second < third && first > third)
	{
		ra(ps);
		return ;
	}
	if (first > second && second > third)
	{
		ra(ps);
		sa(ps);
		return ;
	}
}

void	swap_mod(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	partition(int *arr, int low, int high)
{
	int	pivot;
	int	i;

	pivot = arr[high];
	i = low - 1;
	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap_mod(&arr[i], &arr[j]);
		}
	}
	swap_mod(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void	quick_sort(int *arr, int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition(arr, low, high);
		quick_sort(arr, low, pi - 1);
		quick_sort(arr, pi + 1, high);
	}
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	is_numeric(const char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

void	push_swap_execute(int argc, char **argv)
{
	int			size;
	int			*values;
	int			*sorted_values;
	int			*indices;
	t_push_swap	ps;

	size = argc - 1;
	values = parse_and_convert_args(argv, size);
	sorted_values = copy_and_sort_values(values, size);
	indices = assign_indices(values, sorted_values, size);
	initialize_stacks(&ps, values, indices, size);
	sort_push_swap(&ps);
	final_rotate_sort(&ps);
	ft_printf("Total moves: %d\n", ps.move_count);
	free(values);
	free(sorted_values);
	free(indices);
}

int	*parse_and_convert_args(char **argv, int size)
{
	int	*values;

	values = malloc(sizeof(int) * size);
	if (!values)
	{
		ft_printf("Error\n");
		exit(1);
	}
	for (int i = 0; i < size; i++)
	{
		values[i] = ft_atoi(argv[i + 1]);
	}
	return (values);
}

int	*copy_and_sort_values(int *values, int size)
{
	int	*sorted_values;

	sorted_values = malloc(sizeof(int) * size);
	if (!sorted_values)
	{
		ft_printf("Error\n");
		free(values);
		exit(1);
	}
	for (int i = 0; i < size; i++)
	{
		sorted_values[i] = values[i];
	}
	quick_sort(sorted_values, 0, size - 1);
	return (sorted_values);
}

int	*assign_indices(int *values, int *sorted_values, int size)
{
	int	*indices;

	indices = malloc(sizeof(int) * size);
	if (!indices)
	{
		ft_printf("Error\n");
		free(values);
		free(sorted_values);
		exit(1);
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (values[i] == sorted_values[j])
			{
				indices[i] = j;
				break ;
			}
		}
	}
	return (indices);
}

void	initialize_stacks(t_push_swap *ps, int *values, int *indices, int size)
{
	t_stack	*a;
	t_stack	*b;
	t_node	*node;

	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	if (!a || !b)
	{
		ft_printf("Error\n");
		free(values);
		free(indices);
		exit(1);
	}
	a->top = NULL;
	a->size = 0;
	b->top = NULL;
	b->size = 0;
	ps->a = a;
	ps->b = b;
	ps->move_count = 0;
	for (int i = size - 1; i >= 0; i--)
	{
		node = new_node(values[i], indices[i]);
		push(a, node);
	}
}

void	sort_push_swap(t_push_swap *ps)
{
	int		min_cost;
	int		best_rotation_a;
	int		best_rotation_b;
	t_node	*b_node;
	int		b_position;
	int		cost;
	int		target_position;

	while (ps->a->size > 3)
	{
		pb(ps);
	}
	if (!is_sorted(ps->a))
	{
		sort_three(ps->a, ps);
	}
	while (ps->b->size > 0)
	{
		min_cost = INT_MAX;
		best_rotation_a = 0;
		best_rotation_b = 0;
		b_node = ps->b->top;
		b_position = 0;
		while (b_node)
		{
			cost = calculate_move_cost(ps->a, ps->b, b_position);
			if (cost < min_cost)
			{
				min_cost = cost;
				target_position = find_target_position(ps->a, b_node->index);
				best_rotation_a = calculate_rotation_a(ps->a, target_position);
				best_rotation_b = calculate_rotation_b(ps->b, b_position);
			}
			b_node = b_node->next;
			b_position++;
		}
		perform_rotations(ps, best_rotation_a, best_rotation_b);
		pa(ps);
	}
}

void	final_rotate_sort(t_push_swap *ps)
{
	int		min_position;
	t_node	*current;
	int		min_index;
	int		position;
	int		rotation;

	min_position = 0;
	current = ps->a->top;
	min_index = INT_MAX;
	position = 0;
	while (current)
	{
		if (current->index < min_index)
		{
			min_index = current->index;
			min_position = position;
		}
		current = current->next;
		position++;
	}
	rotation = calculate_rotation_a(ps->a, min_position);
	while (rotation > 0)
	{
		if (!is_sorted(ps->a) && !is_empty(ps->b))
			break ;
		ra(ps);
		rotation--;
	}
	while (rotation < 0)
	{
		if (!is_sorted(ps->a) && !is_empty(ps->b))
			break ;
		rra(ps);
		rotation++;
	}
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_printf("Error\n");
		return (1);
	}
	push_swap_execute(argc, argv);
	return (0);
}

// int main(int argc, char **argv)
// {
// 	if (argc < 2)
//     {
//         ft_printf("Error\n");
//         exit(0);
//     }

//     int size = argc - 1;

//     int *values = malloc(sizeof(int) * size);

// 	if (!values)
//     {
//         ft_printf("Error\n");
//         exit(1);
//     }

// 	for (int i = 0; i < size; i++)
//     {
//         values[i] = ft_atoi(argv[i + 1]);
//     }

//     int *sorted_values = malloc(sizeof(int) * size);
//     if (!sorted_values)
//     {
//         ft_printf("Error\n");
//         free(values);
//         exit(0);
//     }

//     for (int i = 0; i < size; i++)
//     {
//         sorted_values[i] = values[i];
//     }

//     quick_sort(sorted_values, 0, size - 1);

//     int *indices = malloc(sizeof(int) * size);
//     if (!indices)
// 	{
//         ft_printf("Error\n");
//         free(values);
//         free(sorted_values);
//         exit(0);
//     }
//     for (int i = 0; i < size; i++)
// 	{
//         for (int j = 0; j < size; j++)
// 		{
//             if (values[i] == sorted_values[j])
// 			{
//                 indices[i] = j;
//                 break ;
//             }
//         }
//     }

//     t_stack *a = malloc(sizeof(t_stack));
//     t_stack *b = malloc(sizeof(t_stack));
//     if (!a || !b)
// 	{
//         ft_printf("Error\n");
//         free(values);
//         free(sorted_values);
//         free(indices);
//         exit(0);
//     }
//     a->top = NULL;
//     a->size = 0;
//     b->top = NULL;
//     b->size = 0;

//     t_push_swap ps;
//     ps.a = a;
//     ps.b = b;
//     ps.move_count = 0;

//     for (int i = size - 1; i >= 0; i--)
// 	{
//         t_node *node = new_node(values[i], indices[i]);
//         push(a, node);
//     }

//     while (ps.a->size > 3)
// 	{
//         pb(&ps);
//     }

//     if (!is_sorted(ps.a))
// 	{
//         sort_three(ps.a, &ps);
//     }

// while (ps.b->size > 0)
// {
//     int min_cost = INT_MAX;
//     int best_rotation_a = 0;
//     int best_rotation_b = 0;

//     t_node *b_node = ps.b->top;
//     int b_position = 0;

//     while (b_node)
// 	{
//         int cost = calculate_move_cost(ps.a, ps.b, b_position);

//         if (cost < min_cost)
// 		{
//             min_cost = cost;

//             int target_position = find_target_position(ps.a, b_node->index);
//             best_rotation_a = calculate_rotation_a(ps.a, target_position);
//             best_rotation_b = calculate_rotation_b(ps.b, b_position);
//         }

//         b_node = b_node->next;
//         b_position++;
//     }

//     perform_rotations(&ps, best_rotation_a, best_rotation_b);
//     pa(&ps);
// }

//     int min_position = 0;
//     t_node *current = ps.a->top;
//     int min_index = INT_MAX;
//     int position = 0;
//     while (current) {
//         if (current->index < min_index)
// 		{
//             min_index = current->index;
//             min_position = position;
//         }
//         current = current->next;
//         position++;
//     }
//     int rotation = calculate_rotation_a(ps.a, min_position);
//     while (rotation > 0)
// 	{
// 		if(!is_sorted(ps.a) && !is_empty(ps.b))
// 			break ;
//         ra(&ps);
//         rotation--;
//     }
//     while (rotation < 0)
// 	{
// 		if(!is_sorted(ps.a) && !is_empty(ps.b))
// 			break ;
//         rra(&ps);
//         rotation++;
//     }

//     ft_printf("Total moves: %d\n", ps.move_count);

//     free(values);
//     free(sorted_values);
//     free(indices);

//     return (0);
// }