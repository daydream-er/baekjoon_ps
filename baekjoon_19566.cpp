/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   baekjoon_19566.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:04:05 by sangwoki          #+#    #+#             */
/*   Updated: 2023/08/02 11:42:24 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>
#include<unordered_map>
using namespace std;
// just do it.
// 부분합
// 좋은 아이디어

long long   value;
long long   substract[200001];
long long   N, K;

int	main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	
    std::cin >> N >> K;
    long long   i;
    long long   count;
    long long   subsum;
    long long   ans;

    unordered_map<long long, long long> um;
    i = 1;
    subsum = 0;
    ans = 0;
    while (i <= N)
    {
        std::cin >> value;
        subsum += value;
        substract[i] = K * i - subsum;
        // cout << substract[i] << " ";
        if (substract[i] == 0)
            ans+=1;
        count = um[substract[i]];
        um[substract[i]] = count + 1;
        i++;
    }
    // cout << ans << "\n";
    for (unordered_map<long long, long long>::iterator iter = um.begin(); iter != um.end(); iter++)
        ans += (iter->second * (iter->second - 1) / 2);
	std::cout << ans;
}