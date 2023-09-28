/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   baekjoon_3096.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 22:20:09 by sangwoki          #+#    #+#             */
/*   Updated: 2023/08/04 22:25:43 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>
#include<string>
#include<vector>
#include<bitset>
using namespace std;

// nlog(n)
// bitset이 있다니....
// https://j3sung.tistory.com/991
long long   country[1001][40];
int         N;
int         M;

int numberOfSetBits(long i)
{
    i = (i & 0x55555555) + ((i >> 1) & 0x55555555);
    i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
    i = (i & 0x0f0f0f0f) + ((i >> 4) & 0x0f0f0f0f);
    i = (i & 0x00ff00ff) + ((i >> 8) & 0x00ff00ff);
    i = (i & 0x0000ffff) + ((i >> 16) & 0x0000ffff);
    return i;
}

int	main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    std::cout.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= N / 32; j++)
            country[i][j] = 0;
    }
    for (int road = 0; road < M; road++)
    {
        long long s_country;
        long long e_country;
        long long q;
        long long r;

        cin >> s_country >> e_country;
        q = e_country / 32;
        r = e_country % 32;
        country[s_country][q] = country[s_country][q] | (1 << r);
        // cout << country[s_country][q] << "\n";
    }
    long long ans = 0;
    int count;
    for (int i = 1; i <= N; i++)
    {
        for (int j = i + 1; j <= N; j++)
        {
            count = 0;
            for (int k = 0; k <= N / 32; k++)
            {
                if (country[i][k] == 0 || country[j][k] == 0)
                    continue;
                // cout << country[i][k] << ", " << country[j][k] << "\n";
                count += numberOfSetBits(country[i][k] & country[j][k]);
                // if (count != 0)
                //     cout << i << ", " << j << ", " << k << ", " << count << "\n";
            }
            ans += count * (count - 1) / 2;
        }
    }
    cout << ans;
    return (0);
}

// 다른 풀이
// #include <iostream>
// #include <bitset>
// using namespace std;

// const int MAX_N = 1001;
// const int MAX_M = 1001;

// bitset<MAX_M> country[MAX_N];

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     int N, M;
//     cin >> N >> M;

//     for (int i = 1; i <= N; i++) {
//         country[i].reset();
//     }

//     for (int road = 0; road < M; road++) {
//         int s_country, e_country;
//         cin >> s_country >> e_country;
//         country[s_country][e_country] = true;
//     }

//     long long ans = 0;
//     for (int i = 1; i <= N; i++) {
//         for (int j = i + 1; j <= N; j++) {
//             bitset<MAX_M> set = country[i] & country[j];
//             int count = set.count();
//             ans += (count * (count - 1)) / 2;
//         }
//     }

//     cout << ans;
//     return 0;
// }

