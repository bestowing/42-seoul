/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 04:24:41 by chelee            #+#    #+#             */
/*   Updated: 2021/05/02 04:26:08 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void test_strlen()
{
	char	*str = "abcdefg";

	printf("str: %s\n", str);
	printf(ANSI_COLOR_RED"original: %lu\n", strlen(str));
	printf(ANSI_COLOR_YELLOW"ft_strlen: %lu\n", ft_strlen(str));
	printf(ANSI_COLOR_RESET"\n\n");
	str = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed in malesuada purus. Etiam a scelerisque massa. Ut non euismod elit. Aliquam bibendum dolor mi, id fringilla tellus pulvinar eu. Fusce vel fermentum sem. Cras volutpat, eros eget rhoncus rhoncus, diam augue egestas dolor, vitae rutrum nisi felis sed purus. Mauris magna ex, mollis non suscipit eu, lacinia ac turpis. Phasellus ac tortor et lectus fermentum lobortis eu at mauris. Vestibulum sit amet posuere tortor, sit amet consequat amet.";
	printf("str: %s\n", str);
	printf(ANSI_COLOR_RED"original: %lu\n", strlen(str));
	printf(ANSI_COLOR_YELLOW"ft_strlen: %lu\n", ft_strlen(str));
	printf(ANSI_COLOR_RESET"\n\n");

	str = "";
	printf("str: %s\n", str);
	printf(ANSI_COLOR_RED"original: %lu\n", strlen(str));
	printf(ANSI_COLOR_YELLOW"ft_strlen: %lu\n", ft_strlen(str));
	printf(ANSI_COLOR_RESET"\n\n");
	return ;
}

void test_strcpy()
{
	char	*str = "abcdefg";
	char	original_dst[600] = {0, };
	char	ft_dst[600] = {0, };

	printf("str: %s\n", str);
	printf(ANSI_COLOR_RED"original: %s\n", strcpy(original_dst, str));
	printf(ANSI_COLOR_YELLOW"ft_strcpy: %s\n\n", ft_strcpy(ft_dst, str));
	printf(ANSI_COLOR_RESET"\n\n");

	str = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed in malesuada purus. Etiam a scelerisque massa. Ut non euismod elit. Aliquam bibendum dolor mi, id fringilla tellus pulvinar eu. Fusce vel fermentum sem. Cras volutpat, eros eget rhoncus rhoncus, diam augue egestas dolor, vitae rutrum nisi felis sed purus. Mauris magna ex, mollis non suscipit eu, lacinia ac turpis. Phasellus ac tortor et lectus fermentum lobortis eu at mauris. Vestibulum sit amet posuere tortor, sit amet consequat amet.";
	printf("str: %s\n", str);
	printf(ANSI_COLOR_RED"original: %s\n", strcpy(original_dst, str));
	printf(ANSI_COLOR_YELLOW"ft_strcpy: %s\n\n", ft_strcpy(ft_dst, str));
	printf(ANSI_COLOR_RESET"\n\n");

	str = "";
	printf("str: %s\n", str);
	printf(ANSI_COLOR_RED"original: %s\n", strcpy(original_dst, str));
	printf(ANSI_COLOR_YELLOW"ft_strcpy: %s\n\n", ft_strcpy(ft_dst, str));
	printf(ANSI_COLOR_RESET"\n\n");
	return ;
}

void test_strcmp()
{
	char	*str1 = "abcdefg";
	char	*str2 = "";
	
	printf("%s vs %s\n", str1, str2);
	printf(ANSI_COLOR_RED"original: %d\n", strcmp(str1, str2));
	printf(ANSI_COLOR_YELLOW"ft_strlen: %d\n", ft_strcmp(str1, str2));
	printf(ANSI_COLOR_RESET"\n\n");

	str1 = "";
	str2 = "asdf";
	printf("%s vs %s\n", str1, str2);
	printf(ANSI_COLOR_RED"original: %d\n", strcmp(str1, str2));
	printf(ANSI_COLOR_YELLOW"ft_strlen: %d\n", ft_strcmp(str1, str2));
	printf(ANSI_COLOR_RESET"\n\n");

	str1 = "asdf";
	str2 = "asdf";
	printf("%s vs %s\n", str1, str2);
	printf(ANSI_COLOR_RED"original: %d\n", strcmp(str1, str2));
	printf(ANSI_COLOR_YELLOW"ft_strlen: %d\n", ft_strcmp(str1, str2));
	printf(ANSI_COLOR_RESET"\n\n");

	str1 = "asdklfjasdfj////asdf'''asdf3##";
	str2 = "asdklfjasdfj////asdf'''asdf3##";
	printf("%s vs %s\n", str1, str2);
	printf(ANSI_COLOR_RED"original: %d\n", strcmp(str1, str2));
	printf(ANSI_COLOR_YELLOW"ft_strlen: %d\n", ft_strcmp(str1, str2));
	printf(ANSI_COLOR_RESET"\n\n");
	return ;
}

void test_write()
{
	char	*str = "#c#s#p#x#X#e#f#g";

	printf("src: %s\n", str);
	printf(ANSI_COLOR_RED"\noriginal: %zd\n", write(1, str, strlen(str)));
	printf(ANSI_COLOR_YELLOW"\nft_write: %zd\n\n", ft_write(1, str, strlen(str)));
	printf(ANSI_COLOR_RESET"\n\n");

	str = "";
	printf("src: %s\n", str);
	printf(ANSI_COLOR_RED"\noriginal: %zd\n", write(1, str, strlen(str)));
	printf(ANSI_COLOR_YELLOW"\nft_write: %zd\n\n", ft_write(1, str, strlen(str)));
	printf(ANSI_COLOR_RESET"\n\n");
	return ;
}

void test_read()
{
	//char	*str = "#c#s#p#x#X#e#f#g";
	char	original_dst[600] = {0, };
	char	ft_dst[600] = {0, };

	printf(ANSI_COLOR_RED"\noriginal input: %zd\n", read(0, original_dst, 600));
	printf(ANSI_COLOR_YELLOW"\nft_write input: %zd\n\n", ft_read(0, ft_dst, 600));
	printf(ANSI_COLOR_RESET"\n\n");

	return ;
}

void test_strdup()
{
	char	*str = "abcdefg";
	char	*cp1;
	char	*cp2;

	printf("src: %s\n", str);
	cp1 = strdup(str);
	cp2 = ft_strdup(str);
	printf(ANSI_COLOR_RED"original: %s\n", cp1);
	printf(ANSI_COLOR_YELLOW"ft_stdup: %s\n\n", cp2);
	printf(ANSI_COLOR_RESET"\n\n");
	free(cp1); free(cp2);

	str = "";
	printf("src: %s\n", str);
	cp1 = strdup(str);
	cp2 = ft_strdup(str);
	printf(ANSI_COLOR_RED"original: %s\n", cp1);
	printf(ANSI_COLOR_YELLOW"ft_stdup: %s\n\n", cp2);
	printf(ANSI_COLOR_RESET"\n\n");
	free(cp1); free(cp2);

	str = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed in malesuada purus. Etiam a scelerisque massa. Ut non euismod elit. Aliquam bibendum dolor mi, id fringilla tellus pulvinar eu. Fusce vel fermentum sem. Cras volutpat, eros eget rhoncus rhoncus, diam augue egestas dolor, vitae rutrum nisi felis sed purus. Mauris magna ex, mollis non suscipit eu, lacinia ac turpis. Phasellus ac tortor et lectus fermentum lobortis eu at mauris. Vestibulum sit amet posuere tortor, sit amet consequat amet.";
	printf("src: %s\n", str);
	cp1 = strdup(str);
	cp2 = ft_strdup(str);
	printf(ANSI_COLOR_RED"original: %s\n", cp1);
	printf(ANSI_COLOR_YELLOW"ft_stdup: %s\n\n", cp2);
	printf(ANSI_COLOR_RESET"\n\n");
	free(cp1); free(cp2);
	return ;
}

int main(void)
{
	printf("|-------------------|\n");
	printf("|     ft_strlen     |\n");
	printf("|-------------------|\n\n");
	test_strlen();
	printf("|-------------------|\n");
	printf("|     ft_strcpy     |\n");
	printf("|-------------------|\n\n");
	test_strcpy();
	printf("|-------------------|\n");
	printf("|     ft_strcmp     |\n");
	printf("|-------------------|\n\n");
	test_strcmp();
	printf("|-------------------|\n");
	printf("|      ft_write     |\n");
	printf("|-------------------|\n\n");
	test_write();
	printf("|-------------------|\n");
	printf("|      ft_read      |\n");
	printf("|-------------------|\n\n");
	test_read();
	printf("|-------------------|\n");
	printf("|     ft_strdup     |\n");
	printf("|-------------------|\n\n");
	test_strdup();
	printf("all test done.\n");
	return (0);
}
