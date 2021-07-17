/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa_add_bigint.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 20:01:12 by chelee            #+#    #+#             */
/*   Updated: 2020/10/26 21:39:12 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	find_idx(char *nbr)
{
	int i;

	i = 0;
	while (nbr[i] > 0)
	{
		if (nbr[i] && nbr[i + 1] == -1)
			return (i);
		i++;
	}
	i = i < 1 ? 0 : i - 1;
	return (i);
}

static void	add_bigint_cont(char **fraction, int tmp_f)
{
	int prev;
	int i;

	prev = 0;
	i = 0;
	while (!((*fraction)[i] <= 0))
	{
		tmp_f = (*fraction)[i] - '0' + prev;
		if (tmp_f >= 10)
		{
			prev = tmp_f / 10;
			tmp_f %= 10;
		}
		else
			prev = 0;
		(*fraction)[i] = tmp_f + '0';
		i++;
	}
	return ;
}

void		add_bigint(char **fraction, char *big_int)
{
	int idx_f;
	int idx_b;
	int tmp;
	int tmp_f;

	idx_f = find_idx(*fraction);
	idx_b = find_idx(big_int);
	while (idx_b >= 0)
	{
		tmp = big_int[idx_b] - '0';
		if (idx_f < 0)
			tmp_f = 0;
		else
			tmp_f = (*fraction)[idx_f] - '0';
		tmp_f += tmp;
		(*fraction)[idx_b] = tmp_f + '0';
		idx_f--;
		idx_b--;
	}
	add_bigint_cont(fraction, tmp_f);
	return ;
}
