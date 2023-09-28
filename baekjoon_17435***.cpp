/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   baekjoon_17435***.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 22:05:03 by sangwoki          #+#    #+#             */
/*   Updated: 2023/08/30 23:01:26 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// DP + 제곱 형태의 트리...
// log2를 기억해라!
// ***************
#include<iostream>
#include<math.h>
using namespace std;

int ac[200001][25];
int m;
void    build_tree(void)
{
    for (int level = 1; level <= (int)log2(500000) + 1; level++)
    {
        for (int i = 1; i <= m; i++)
            ac[i][level] = ac[ac[i][level - 1]][level - 1];
    }
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

    cin >> m;
    for (int i = 1; i <= m; i++)
        cin >> ac[i][0];
    build_tree();
    int n;
    int x;
    int query_cnt;
    cin >> query_cnt;
    for (int i = 1; i <= query_cnt; i++)
    {
        cin >> n >> x;
        for (int level = (int)log2(500000) + 1; level >= 0; level--)
        {
            if (n < pow(2, level))
                continue;
            // cout << level << ", " << n << "\n";
            n -= pow(2, level);
            x = ac[x][level];
        }
        cout << x << "\n";
    }
    // cout << "-------------------------------------------\n";
    // for (int i = 1; i <= m; i++)
    // {
    //     for (int j = 0; j <= (int)log(500000) + 1; j++)
    //         cout << ac[i][j] << " ";
    //     cout << "\n";
    // }
}