/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   baekjoon_6087.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:05:29 by sangwoki          #+#    #+#             */
/*   Updated: 2023/08/21 21:39:39 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>
#include<queue>
using namespace std;

char    map[101][101];
int     visited[101][101][4];
int     W, H;
int     ans;
pair<int, int>  s;
pair<int, int>  e;

typedef struct s_node {
    pair<int, int>  co;
    int             dir_idx;
    int             step;
}   t_node;

queue<t_node> heapq;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int bfs_alg(void)
{
    t_node  src;

    src.co = s;
    src.dir_idx = 5;
    src.step = 0;

    heapq.push(src);
    for (int i = 0; i < 4; i++)
        visited[src.co.first][src.co.second][i] = src.step;
    while (heapq.empty() == false)
    {
        t_node  dest;

        src = heapq.front();
        // cout << src.co.first << ", " << src.co.second << "\n";
        heapq.pop();
        for (int i = 0; i < 4; i++)
        {
            dest.co.first = src.co.first + dx[i];
            dest.co.second = src.co.second + dy[i];
            if (!(0 <= dest.co.first && dest.co.first < H) || !(0 <= dest.co.second && dest.co.second < W))
                continue;
            if (map[dest.co.first][dest.co.second] == '*')
                continue;
            dest.dir_idx = i;
            dest.step = src.step;
            if (src.co != s && src.dir_idx != dest.dir_idx)
                dest.step++;
            if (visited[dest.co.first][dest.co.second][i] == -1 || visited[dest.co.first][dest.co.second][i] > dest.step)
            {
                visited[dest.co.first][dest.co.second][i] = dest.step;
                heapq.push(dest);
            }
        }
    }

    int ans;

    ans = 10001;
    for (int i = 0; i < 4; i++)
    {
        if (visited[e.first][e.second][i] != -1 && ans > visited[e.first][e.second][i])
            ans = visited[e.first][e.second][i];
    }
    return (ans);
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

    cin >> W >> H;
    s.first = -1;
    for (int row = 0; row < H; row++)
    {
        for (int col = 0; col < W; col++)
        {
            cin >> map[row][col];
            for (int i = 0; i < 4; i++)
                visited[row][col][i] = -1;
            if (map[row][col] == 'C')
            {
                if (s.first == -1)
                {
                    s.first = row;
                    s.second = col;
                }
                else
                {
                    e.first = row;
                    e.second = col;
                }
            }
        }
    }
    ans = bfs_alg();
    cout << ans;
}