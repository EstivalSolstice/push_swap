#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list *applyft = lst;

	while(applyft != NULL)
	{
		f(applyft->content);
		applyft = applyft->next;
	}
}