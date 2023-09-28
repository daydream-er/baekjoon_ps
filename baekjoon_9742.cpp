/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   baekjoon_9742.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 21:22:58 by sangwoki          #+#    #+#             */
/*   Updated: 2023/07/17 22:46:18 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>
#include<string>
#include<vector>

// 병신아, 벡터와 연결리스트 구분해라.

typedef	struct NODE
{
	char	ch;
	int		length;
	struct NODE	*next;
}	NODE;

int	nbr[5];
NODE	str[5][11];

int	permutation_count(int N)
{
	if (N == 1)
		return (1);
	return (N * permutation_count(N - 1));
}

void	print_string(int i)
{
	int	idx;
	int	remainder;
	int	Q;
	int N;
	int	count;

	idx = nbr[i];
	N = str[i][0].length - 1;
	while (N >= 0)
	{
		count = permutation_count(N);
		Q = idx / count;
		remainder = idx % count;
		if (remainder == 0)
		{
			std::cout << str[i][Q].ch;
			str[i][Q - 1].next = str[i][Q].next;
			idx = count;
		}
		else
		{
			std::cout << str[i][Q + 1].ch;
			str[i][Q].next = str[i][Q + 1].next;
			idx = remainder;
		}
		N--;
	}
}

int	main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::string	tmp;
	for (int i = 0; i < 5; i++)
	{
		std::cin >> tmp;
		str[i][0].length = tmp.length();
		str[i][0].next = 0;
		for (int j = 1; j <= tmp.length(); j++)
		{
			str[i][j].ch = tmp[j - 1];
			str[i][j - 1].next = &str[i][j];
			str[i][j].next = 0;
		}
		std::cin >> nbr[i];
	}
	std::string result[5];
	for (int i = 0; i < 5; i++)
	{
		int	j;

		j = 0;
		do
		{
			j++;
			std::cout << str[i][j].ch;
		} while (str[i][j].next != 0);
		std::cout << " " << nbr[i] << " = ";
		if (nbr[i] > permutation_count(str[i][0].length))
			std::cout << "No permutation" << "\n";
		else
			print_string(i);
	}
	return (0);
}