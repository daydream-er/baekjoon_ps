/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   매우중요_12865.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 19:42:06 by sangwoki          #+#    #+#             */
/*   Updated: 2023/08/10 22:46:11 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int N;
vector<pair<int, int> >item(100); // 무게, 가치
int DP[101][100001];
int K; // W의 관한
// bool    compare(pair<int, int> value1, pair<int, int> value2)
// {
//     if (value1.first > value2.first)
//         return (true);
//     return (false);
// }

int	main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    std::cout.tie(NULL);

    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> item[i].first >> item[i].second;
    // sort(item.begin(), item.end(), compare);

    int ans;

    ans = 0;
    for (int j = 0; j <= K; j++)
    {
        if (j - item[0].first < 0)
            DP[0][j] = 0;
        else
            DP[0][j] = item[0].second;
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= K; j++)
        {
            if (j - item[i].first < 0)
                DP[i][j] = DP[i - 1][j];
            else if (DP[i - 1][j] < DP[i - 1][j - item[i].first] + item[i].second)
                DP[i][j] = DP[i - 1][j - item[i].first] + item[i].second;
            else
                DP[i][j] = DP[i - 1][j];
            // cout << i << ", " << j << " : " << DP[i][j] << " ";
        }
        // cout << "\n";
    }
    cout << DP[N][K];
    return (0);
}