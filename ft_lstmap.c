#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(f)(void *), void (*del)(void *))
{
	if(f == NULL || del == NULL)
	{
		return (NULL);
	}

	t_list	*new_list = NULL;
	t_list 	*iter_lst = lst;
	t_list	*new_node;
	void 	*new_content;

	while (iter_lst != NULL)
	{
		new_content = f(iter_lst->content);

		new_node = ft_lstnew(new_content);
		if (!new_node)
        {
            ft_lstclear(&new_list, del);
            return (NULL);
        }

		ft_lstadd_back(&new_list, new_node);

		iter_lst = iter_lst->next;
	}
	return (new_list);
}