/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   baekjoon_11438.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 19:32:32 by sangwoki          #+#    #+#             */
/*   Updated: 2023/08/31 23:07:21 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int ac[100001][20];
int depth[100001];
vector<int> vec[100001];

void    build_tree(int here, int parent)
{
    int tmp;

    depth[here] = depth[parent] + 1;
    ac[here][0] = parent;
    for (int level = 1; level <= (int)log2(100000) + 1; level++)
    {
        tmp = ac[here][level - 1];
        ac[here][level] = ac[tmp][level - 1];
    }
    for (int i = 0; i < vec[here].size(); i++)
    {
        if (vec[here][i] == parent)
            continue;
        build_tree(vec[here][i], here);
    }
}

int lca(int a, int b)
{
    int tmp;

    if (depth[a] != depth[b])
    {
        if (depth[a] < depth[b])
        {
            tmp = b;
            b = a;
            a = tmp;
        }
        for (int i = (int)log2(100000) + 1; i >= 0; i--)
        {
            if (depth[ac[a][i]] >= depth[b])
                a = ac[a][i];
        }
    }
    int lca;

    lca = a;
    if (a != b)
    {
        for (int i = (int)log2(100000) + 1; i >= 0; i--)
        {
            if (ac[a][i] != ac[b][i])
            {
                a = ac[a][i];
                b = ac[b][i];
            }
            lca = ac[a][i];
        }
    }
    return (lca);
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

    int N;
    int a;
    int b;
    int M;

    cin >> N;
    for (int i = 1; i <= N; i++)
        depth[i] = 0;
    for (int i = 1; i < N; i++)
    {
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    build_tree(1, 1);
    cin >> M;
    for (int i = 1; i <= M; i++)
    {
        cin >> a >> b;
        cout << lca(a, b) << "\n";
    }
}