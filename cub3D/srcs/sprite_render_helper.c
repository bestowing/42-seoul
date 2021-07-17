/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_render_helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 17:55:01 by chelee            #+#    #+#             */
/*   Updated: 2021/02/21 18:38:23 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	swap_item(int order[], int dis[], int a, int b)
{
	int		temp;

	temp = order[a];
	order[a] = order[b];
	order[b] = temp;
	temp = dis[a];
	dis[a] = dis[b];
	dis[b] = temp;
	return ;
}

static int	partition(int order[], int dis[], int left, int right)
{
	int		pivot;
	int		low;
	int		high;

	pivot = dis[left];
	low = left + 1;
	high = right;
	while (low <= high)
	{
		while (low <= right && pivot >= dis[low])
			low++;
		while (high >= (left + 1) && pivot <= dis[high])
			high--;
		if (low <= high)
			swap_item(order, dis, low, high);
	}
	swap_item(order, dis, left, high);
	return (high);
}

void		sort_items(int order[], int dis[], int l, int r)
{
	int	pivot;

	if (l <= r)
	{
		pivot = partition(order, dis, l, r);
		sort_items(order, dis, l, pivot - 1);
		sort_items(order, dis, pivot + 1, r);
	}
	return ;
}
