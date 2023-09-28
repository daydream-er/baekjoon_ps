/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   baekjoon_11066.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:13:51 by sangwoki          #+#    #+#             */
/*   Updated: 2023/08/27 21:35:20 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#define INF 1000000001
using namespace std;

// 이 문제를 1년 뒤에 본다면 한번에 풀 수 있을까?
// ### 없다.
// ### 중요도 ****
// DP를 점화식으로 구현하는 마인드 셋.

int file[501];
int s_file[501][501];
int prefix_sum[501];

int main(void)
{
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

    int         test_case;
    int         end;
    int         value;
    long long   ans;

    cin >> test_case;
    for (int t = 0; t < test_case; t++)
    {
        cin >> end;
        prefix_sum[0] = 0;
        for (int i = 1; i <= end; i++)
        {
            cin >> file[i];
            prefix_sum[i] = prefix_sum[i - 1] + file[i];
        }
        for (int i = 0; i <= end; i++)
        {
            for (int j = 0; j <= end; j++)
            {
                s_file[i][j] = 1000000001;
                if (i == j)
                    s_file[i][j] = 0;
            }
        }
        for (int i = 1; i <= end; i++)
        {
            for (int j = 1; j <= end - i; j++)
            {
                for (int k = j; k < i + j; k++)
                    s_file[j][i + j] = min(prefix_sum[i + j] - prefix_sum[j - 1] + s_file[j][k] + s_file[k + 1][i + j], s_file[j][i + j]);
            }
        }
        cout << s_file[1][end] << "\n";
    }
    return (0);
}


