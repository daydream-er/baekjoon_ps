/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   baekjoon_1522.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:43:26 by sangwoki          #+#    #+#             */
/*   Updated: 2023/08/09 13:40:10 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>
#include<math.h>
using namespace std;

// sliding window
// https://duddn.tistory.com/12

int     a;
int     b;
int     window_size;
char    window_ch;
int main(void)
{
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

    string  str;
    int     ans;
    int     window_size;
    int     window;

    ans = 0;
    cin >> str;
    a = 0;
    b = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == 'a')
            a++;
        else
            b++;
    }
    window_ch = 'a';
    window_size = a;
    if (a < b)
    {
        window_ch = 'b';
        window_size = b;
    }
    int i, j;
    int max_count, count;

    i = 0;
    max_count = 0;
    while (i < str.length())
    {
        j = i;
        count = 0;
        while (j != (i + window_size) % str.length())
        {
            if (str[j] == window_ch)
                count++;
            j = (j + 1) % str.length();
        }
        if (count > max_count)
            max_count = count;
        i++;
    }
    if (window_size == str.length())
        cout << 0;
    else
        cout << window_size - max_count;
}