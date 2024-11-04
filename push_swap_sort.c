/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltmann <joltmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:59:35 by joltmann          #+#    #+#             */
/*   Updated: 2024/11/04 19:02:40 by joltmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	find_best_rotation(t_push_swap *ps, int *best_rotation_a,
// 		int *best_rotation_b)
// {
// 	t_node	*b_node;
// 	int		min_cost;
// 	int		b_position;
// 	int		cost;
// 	int		target_position;

// 	b_node = ps->b->top;
// 	min_cost = INT_MAX;
// 	b_position = 0;
// 	while (b_node)
// 	{
// 		cost = calculate_move_cost(ps->a, ps->b, b_position);
// 		if (cost < min_cost)
// 		{
// 			min_cost = cost;
// 			target_position = find_target_position(ps->a, b_node->index);
// 			*best_rotation_a = calculate_rotation_a(ps->a, target_position);
// 			*best_rotation_b = calculate_rotation_b(ps->b, b_position);
// 		}
// 		b_node = b_node->next;
// 		b_position++;
// 	}
// }

static void find_best_rotation(t_push_swap *ps, int *best_rotation_a, int *best_rotation_b)
{
    t_node *b_node = ps->b->top;
    int min_cost = INT_MAX;
    int b_position = 0;
    int cost, rotation_a, rotation_b, target_position;

    while (b_node)
    {
        target_position = find_target_position(ps->a, b_node->value);
        rotation_a = calculate_rotation_a(ps->a, target_position);
        rotation_b = calculate_rotation_b(ps->b, b_position);
        cost = calculate_rotation_cost(rotation_a, rotation_b);

        if (cost < min_cost)
        {
            min_cost = cost;
            *best_rotation_a = rotation_a;
            *best_rotation_b = rotation_b;
        }
        b_node = b_node->next;
        b_position++;
    }

    // Debug: Print chosen rotation values to track any misalignments
    // printf("Best rotation_a: %d, rotation_b: %d with cost: %d\n", *best_rotation_a, *best_rotation_b, min_cost);
}


t_node *get_node_at(t_stack *stack, int position)
{
    t_node *current = stack->top;
    int i = 0;
    while (current && i < position)
    {
        current = current->next;
        i++;
    }
    return current;
}

int find_target_position_in_b(t_stack *b, int value)
{
    t_node  *current;
    int     position;

    current = b->top;
    position = 0;

    while (current)
    {
        if (value > current->value)
            break;
        current = current->next;
        position++;
    }
    return position;
}


int calculate_move_cost_to_b(t_stack *a, t_stack *b, int a_position)
{
    t_node  *a_node;
    int     i;
    int     target_position;
    int     rotation_a;
    int     rotation_b;

    a_node = a->top;
    i = 0;
    while (i < a_position && a_node != NULL)
    {
        a_node = a_node->next;
        i++;
    }
    if (a_node == NULL)
        return (INT_MAX);

    target_position = find_target_position_in_b(b, a_node->value);

    rotation_a = calculate_rotation_a(a, a_position);
    rotation_b = calculate_rotation_b(b, target_position);

    return calculate_rotation_cost(rotation_a, rotation_b);
}


static void find_best_move_to_b(t_push_swap *ps, int *best_rotation_a, int *best_rotation_b)
{
    int best_cost = INT_MAX;
    int current_cost;
    int rotation_a;
    int rotation_b;
    int i;

    i = 0;
    while (i < ps->a->size)
    {
        current_cost = calculate_move_cost_to_b(ps->a, ps->b, i);

        if (current_cost < best_cost)
        {
            best_cost = current_cost;
            rotation_a = calculate_rotation_a(ps->a, i);
            int target_position = find_target_position_in_b(ps->b, get_node_at(ps->a, i)->value);
            rotation_b = calculate_rotation_b(ps->b, target_position);

            *best_rotation_a = rotation_a;
            *best_rotation_b = rotation_b;
        }
        i++;
    }
}

static void push_until_three(t_push_swap *ps)
{
	int best_rotation_a;
	int best_rotation_b;

	while (ps->a->size > 3)
	{
		find_best_move_to_b(ps, &best_rotation_a, &best_rotation_b);
		perform_rotations(ps, best_rotation_a, best_rotation_b);
		pb(ps);
	}
	if (!is_sorted(ps->a))
		sort_three(ps->a, ps);
}

void	sort_push_swap(t_push_swap *ps)
{
	int	best_rotation_a;
	int	best_rotation_b;

	push_until_three(ps);
	while (ps->b->size > 0)
	{
		find_best_rotation(ps, &best_rotation_a, &best_rotation_b);
		perform_rotations(ps, best_rotation_a, best_rotation_b);
		pa(ps);
	}
}
