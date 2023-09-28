/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 22:31:27 by sangwoki          #+#    #+#             */
/*   Updated: 2023/09/26 20:11:02 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

// bool	visited[21][21];
char	map[21][21];
bool	alpha[30];
int	dx[4] = {0, 1, 0, -1};
int	dy[4] = {1, 0, -1, 0};
int R, C;
queue<vector<pair<int, int> > >	que;

int	dfs_alg(pair<int, int> cur_v)
{
	int				count;
	pair<int, int>	next_v;

	// visited[cur_v.first][cur_v.second] = true;
	alpha[map[cur_v.first][cur_v.second] - 'A'] = true;
	count = 0;
	for (int i = 0; i < 4; i++)
	{
		if (!(1 <= cur_v.first + dx[i] && cur_v.first + dx[i] <= R))
			continue;
		if (!(1 <= cur_v.second + dy[i] && cur_v.second + dy[i] <= C))
			continue;
		next_v = make_pair(cur_v.first + dx[i], cur_v.second + dy[i]);
		// if (alpha[map[next_v.first][next_v.second] - 'A'] || visited[next_v.first][next_v.second])
		// 	continue;
		if (alpha[map[next_v.first][next_v.second] - 'A'])
			continue;
		count = max(dfs_alg(next_v), count);
		alpha[map[next_v.first][next_v.second] - 'A'] = false;
	}
	return (count + 1);
}

int	main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> R >> C;
	for (int row = 1; row <= R; row++)
	{
		for (int col = 1; col <= C; col++)
			cin >> map[row][col];
	}
	// for (int row = 1; row <= R; row++)
	// {
	// 	for (int col = 1; col <= C; col++)
	// 		visited[row][col] = false;
	// }
	for (int i = 0; i <= 30; i++)
		alpha[i] = false;
	pair<int, int> cur_v = make_pair(1, 1);
	cout << dfs_alg(cur_v) << "\n";
    return (0);
}