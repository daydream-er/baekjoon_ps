/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   baekjoon_2829.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 19:07:16 by sangwoki          #+#    #+#             */
/*   Updated: 2023/08/08 20:17:21 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>
using namespace std;

int N;
int left2right[400][400];
int right2left[400][400];

typedef struct COR
{
	int row;
	int col;
}   COR;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> left2right[i][j];
			right2left[i][j] = left2right[i][j];
			if (i - 1 >= 0 && j - 1 >= 0)
				left2right[i][j] += left2right[i - 1][j - 1];
			if (i - 1 >= 0 && j + 1 < N)
				right2left[i][j] += right2left[i - 1][j + 1];
			// cout << left2right[i][j] << ", " << right2left[i][j];
		}
		// cout  << "\n";
	}
	int ans = -400001;

	COR	left;
	COR	right;
	int	left_sum;
	int	right_sum;
	for (int size = 2; size <= N; size++)
	{
		for (int i = 0; i <= N - size; i++)
		{
			for (int j = 0; j <= N - size; j++)
			{
				left.row = i;
				left.col = j;
				right.row = i;
				right.col = j + size - 1;
				left_sum = 0;
				right_sum = 0;
				if (left.row - 1 >= 0 && left.col - 1 >= 0)
					left_sum = left2right[left.row - 1][left.col - 1];
				if (right.row - 1 >= 0 && right.col + 1 < N)
					right_sum = right2left[right.row - 1][right.col + 1];
				// cout << left_sum << ", " << right_sum << "\n";
				left_sum = left2right[left.row + size - 1][left.col + size - 1] - left_sum;
				right_sum = right2left[right.row + size - 1][right.col - size + 1] - right_sum;
				if (ans < (left_sum - right_sum))
					ans = left_sum - right_sum;
			}
		}
	}
	cout << ans;
}