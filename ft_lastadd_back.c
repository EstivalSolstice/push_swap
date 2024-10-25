#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (new == NULL)
	{
		*lst = new;
        return;
	}

	t_list *findlast_node = *lst;

	while (findlast_node->next != NULL)
	{
		findlast_node = findlast_node->next;
	}
	findlast_node->next = new;
	new->next = NULL;
}