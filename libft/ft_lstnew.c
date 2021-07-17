/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 19:50:37 by chelee            #+#    #+#             */
/*   Updated: 2020/10/01 19:54:36 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_item;

	if (!(new_item = (t_list *)malloc(sizeof(t_list))))
		return (0);
	new_item->content = content;
	new_item->next = NULL;
	return (new_item);
}
