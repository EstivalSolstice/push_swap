#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (!lst || !*lst)
	{
    	return;
	}

	t_list *find_node = *lst;
	t_list *find_next;

	while(find_node != NULL)
	{
		find_next = find_node->next;
		del(find_node->content);
		free(find_node);
		find_node = find_next;
	}

	*lst = NULL;
}