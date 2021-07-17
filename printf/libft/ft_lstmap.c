/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 20:11:59 by chelee            #+#    #+#             */
/*   Updated: 2020/10/01 23:53:02 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	void	*f_value;

	if (lst == NULL || f == NULL)
		return (NULL);
	head = NULL;
	while (lst)
	{
		f_value = f(lst->content);
		if (!f_value)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, ft_lstnew(f_value));
		lst = lst->next;
	}
	return (head);
}
