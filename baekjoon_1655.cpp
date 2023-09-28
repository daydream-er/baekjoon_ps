/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   baekjoon_1655.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 22:14:41 by sangwoki          #+#    #+#             */
/*   Updated: 2023/08/12 17:43:47 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

// why is it wrong? before code...
// heap의 begin()에서 값을 삭제한다. 따라서 곧바로 erase로 삭제하면 안되는가?

// heap을 사용할 때는 push_back -> push_heap, pop_heap -> pop_back을 수행한다.
vector<int> max_heapq;
vector<int> min_heapq;
int	main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

    int N;
    int value;
    int tmp1;
    int tmp2;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> value;
        if (max_heapq.size() == min_heapq.size())
        {
            max_heapq.push_back(value);
            push_heap(max_heapq.begin(), max_heapq.end());
        }
        else
        {
            min_heapq.push_back(-value);
            push_heap(min_heapq.begin(), min_heapq.end());
        }
        if (!max_heapq.empty() && !min_heapq.empty() && max_heapq.front() > -min_heapq.front())
        {
            tmp1 = -min_heapq.front();
            tmp2 = max_heapq.front();
            // min_heapq.erase(min_heapq.begin());
            // max_heapq.erase(max_heapq.begin());
            pop_heap(max_heapq.begin(), max_heapq.end());
            pop_heap(min_heapq.begin(), min_heapq.end());
            max_heapq.pop_back();
            min_heapq.pop_back();
            max_heapq.push_back(tmp1);
            min_heapq.push_back(-tmp2);
            push_heap(max_heapq.begin(), max_heapq.end());
            push_heap(min_heapq.begin(), min_heapq.end());
        }
        // for (int i = 0; i < max_heapq.size(); i++)
        //     cout << max_heapq[i] << "< ";
        // cout << "\n";
        // for (int i = 0; i < min_heapq.size(); i++)
        //     cout << -min_heapq[i] << "<< ";
        // cout << "\n ans: ";
        cout << max_heapq.front() << "\n";
    }
    return (0);
}